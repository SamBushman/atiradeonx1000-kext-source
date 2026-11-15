#!/usr/bin/env python3
"""fnfuzz_dist.py CONFIG.json [--resume] - run ONE fnfuzz ledger as many small chunks over SEVERAL machines with a work queue (Nov 15, user-requested producer/consumer design).

Every machine has `slots` worker threads here (one fnfuzz parent per slot, G5 <= 3). A worker takes the next pending chunk (`@first,count` of the ledger), launches it DETACHED on its
machine (fnfuzz_chunk.sh over ssh, so an ssh drop or this script ending does not kill it), polls for its `.done` marker, pulls the output, and takes the next chunk. A faster machine therefore
simply takes more chunks: no guessed split. Checksum discipline as fnfuzz_par.sh: each machine writes manifest.start before the first chunk, every chunk re-checks its state against it and refuses
to run on a change (rc 99), manifest.end is compared at the end; the merged output carries `RESULT:` only if every chunk ended in a RESULT line and every machine's manifest is unchanged.
The merge keeps every chunk line untouched (digests are only comparable on the SAME machine: see EVIDENCE_fnfuzz.md, G4 vs G5) and writes OUT.chunks.tsv (chunk, first row, count, machine, secs,
md5, RESULT) so any row can be traced to the machine that ran it.

Config (JSON): name, ledger (local path), trials, rows_per_chunk, out (local output prefix), env {FNFUZZ_*...} common to all machines, machines {NAME: {host (ssh alias), slots, dir (remote work dir,
created), fz, stock, rebuilt (remote absolute paths), env {per-machine FNFUZZ_* e.g. FNFUZZ_DATA}}}.
--resume: keep state from an earlier run of the SAME config ONLY if the ledger md5, config and every machine's manifest.start equal the saved ones; chunks that were running are re-attached by their
marker, chunks done are kept only if the pulled output's md5 equals the recorded one; anything else is rerun from its first row (never partial trust).
Remote chunks are never killed by this script; to stop a run kill this script, then the remote chunk PIDs (DIR/out.cK.pid) by PID.
"""
import sys, os, json, subprocess, threading, time, hashlib, shlex, re

HERE = os.path.dirname(os.path.abspath(__file__))
SSHO = ['-o', 'ConnectTimeout=20', '-o', 'BatchMode=yes', '-o', 'ServerAliveInterval=15']
LOCK = threading.Lock()
LOGF = None

def log(msg):
    line = time.strftime('%H:%M:%S ') + msg
    with LOCK:
        print(line, flush=True)

def run(args, timeout=180):
    try:
        p = subprocess.run(args, capture_output=True, text=True, timeout=timeout)
        return p.returncode, (p.stdout or '') + (p.stderr or '')
    except Exception as e:
        return 255, str(e)

def ssh(host, cmd, timeout=180):
    return run(['ssh'] + SSHO + [host, cmd], timeout)

def ssh_detached(host, cmd):
    # `ssh -f` goes to the background after authentication; with the pipes captured (as run() does) the call would not return until the REMOTE command ended
    # (first test run: each launch blocked for the whole chunk, and a 60 s timeout would have launched it twice). All three streams go to /dev/null so it returns at once;
    # a launch that did not start shows up as a missing pid file and is handled by poll() (NOPID for more than 120 s = DEAD = requeued).
    try:
        return subprocess.run(['ssh', '-f'] + SSHO + [host, cmd], stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, timeout=60).returncode, ''
    except Exception as e:
        return 255, str(e)

def scp_to(host, local, remote):
    return run(['scp', '-q'] + SSHO + [local, '%s:%s' % (host, remote)])[0] == 0

def scp_from(host, remote, local):
    return run(['scp', '-q'] + SSHO + ['%s:%s' % (host, remote), local])[0] == 0

def md5f(path):
    h = hashlib.md5()
    with open(path, 'rb') as f:
        for b in iter(lambda: f.read(1 << 20), b''):
            h.update(b)
    return h.hexdigest()

def envprefix(d):
    return 'env ' + ' '.join('%s=%s' % (k, shlex.quote(str(v))) for k, v in sorted(d.items())) if d else ''

class Dist:
    def __init__(self, cfg, resume):
        self.cfg = cfg; self.resume = resume
        self.out = cfg['out']; self.trials = cfg['trials']
        lines = open(cfg['ledger'], errors='replace').read().split('\n')
        self.rows = [l for l in lines if re.match(r'^\d+\t', l) and l.count('\t') >= 6]
        per = cfg['rows_per_chunk']; n = len(self.rows)
        self.chunks = [(k, k * per, min(per, n - k * per)) for k in range((n + per - 1) // per)]
        self.state = {k: {'status': 'pending', 'machine': None, 'attempts': 0} for k, _, _ in self.chunks}
        self.statef = self.out + '.dist.json'
        self.m = cfg['machines']
        self.ledger_md5 = md5f(cfg['ledger'])
        self.t0 = time.time()

    def save(self):
        with LOCK:
            json.dump({'config': self.cfg, 'ledger_md5': self.ledger_md5, 'state': self.state}, open(self.statef + '.tmp', 'w'), indent=1)
            os.replace(self.statef + '.tmp', self.statef)

    # ---- machine setup -------------------------------------------------------------------------------------------------------------------
    def common_env(self, name):
        e = dict(self.cfg.get('env', {})); e.update(self.m[name].get('env', {})); return e

    def setup_machine(self, name):
        mc = self.m[name]; h = mc['host']; d = mc['dir']
        rc, o = ssh(h, 'mkdir -p %s && echo ok' % shlex.quote(d))
        if 'ok' not in o: sys.exit('%s: cannot create %s: %s' % (name, d, o))
        for loc, rem in ((self.cfg['ledger'], 'ledger.tsv'), (os.path.join(HERE, 'fnfuzz_chunk.sh'), 'fnfuzz_chunk.sh'), (os.path.join(HERE, 'fnfuzz_manifest.sh'), 'fnfuzz_manifest.sh')):
            if not scp_to(h, loc, d + '/' + rem): sys.exit('%s: scp %s failed' % (name, loc))
        rc, o = ssh(h, 'cd %s && (md5 -q ledger.tsv 2>/dev/null || md5sum ledger.tsv | cut -d" " -f1)' % shlex.quote(d))
        if o.strip().split()[-1:] != [self.ledger_md5]: sys.exit('%s: ledger md5 mismatch after copy (%s)' % (name, o.strip()))
        for need in ('fz', 'stock', 'rebuilt'):
            rc, o = ssh(h, 'test -f %s && echo ok' % shlex.quote(mc[need]))
            if 'ok' not in o: sys.exit('%s: missing %s %s' % (name, need, mc[need]))
        mf = self.out + '.manifest.' + name
        cmd = 'cd %s && %s sh fnfuzz_chunk.sh start %s %s %s %s %d' % (shlex.quote(d), envprefix(self.common_env(name)), shlex.quote(d), shlex.quote(mc['fz']), shlex.quote(mc['stock']), shlex.quote(mc['rebuilt']), self.trials)
        rc, o = ssh(h, cmd)
        if rc != 0: sys.exit('%s: manifest start failed: %s' % (name, o))
        newf = mf + ('.now' if self.resume and os.path.exists(mf) else '')
        if not scp_from(h, d + '/manifest.start', newf): sys.exit('%s: cannot pull manifest.start' % name)
        if newf != mf:
            a = [l for l in open(mf) if not l.startswith('#')]; b = [l for l in open(newf) if not l.startswith('#')]
            os.remove(newf)
            if a != b: sys.exit('%s: RESUME REFUSED: manifest.start differs from the saved one' % name)

    # ---- one chunk -----------------------------------------------------------------------------------------------------------------------
    def alive(self, name, k):
        mc = self.m[name]; rc, o = ssh(mc['host'], 'cd %s && [ -f out.c%d.pid ] && kill -0 `cat out.c%d.pid` 2>/dev/null && echo ALIVE' % (shlex.quote(mc['dir']), k, k), 60)
        return rc == 0 and 'ALIVE' in o

    def launch(self, name, k):
        mc = self.m[name]; h = mc['host']; d = shlex.quote(mc['dir']); _, first, cnt = self.chunks[k]
        if self.alive(name, k): log('%s chunk %d: a chunk process is already running there - attaching, not launching a second one' % (name, k)); return True
        cmd = 'cd %s && rm -f out.c%d.done out.c%d.pid out.c%d.full && nohup %s sh fnfuzz_chunk.sh chunk %s %d %d %d %s %s %s %d > /dev/null 2>&1 < /dev/null &' % (
            d, k, k, k, envprefix(self.common_env(name)), d, k, first, cnt, shlex.quote(mc['fz']), shlex.quote(mc['stock']), shlex.quote(mc['rebuilt']), self.trials)
        for _ in range(5):
            rc, o = ssh_detached(h, cmd)
            if rc == 0: return True
            time.sleep(10)
        return False

    def poll(self, name, k, t_launch):
        mc = self.m[name]; h = mc['host']; d = shlex.quote(mc['dir'])
        cmd = 'cd %s; if [ -f out.c%d.done ]; then cat out.c%d.done; elif [ -f out.c%d.pid ] && kill -0 `cat out.c%d.pid` 2>/dev/null; then echo RUNNING; elif [ ! -f out.c%d.pid ]; then echo NOPID; else echo DEAD; fi' % (d, k, k, k, k, k)
        fails = 0
        while True:
            rc, o = ssh(h, cmd, 60); o = o.strip().split('\n')[-1] if o.strip() else ''
            if rc == 0 and o.startswith('chunk %d rc ' % k): return o
            if rc == 0 and o == 'DEAD': return 'DEAD'
            if rc == 0 and o == 'NOPID' and time.time() - t_launch > 120: return 'DEAD'
            if rc != 0:
                fails += 1
                if fails % 10 == 1: log('%s: ssh poll failed (%d in a row) - waiting, the chunk keeps running on the machine' % (name, fails))
            else: fails = 0
            time.sleep(15)

    def do_chunk(self, name, k, attach):
        t = time.time()
        if not attach:
            if not self.launch(name, k):
                log('%s chunk %d: launch failed' % (name, k)); return 'DEAD'
            log('%s chunk %d (rows %d..%d) launched' % (name, k, self.chunks[k][1], self.chunks[k][1] + self.chunks[k][2] - 1))
        res = self.poll(name, k, t)
        if res == 'DEAD': return 'DEAD'
        mm = dict(zip(res.split()[2::2], res.split()[3::2]))
        h = self.m[name]['host']; d = self.m[name]['dir']; loc = '%s.c%d.full' % (self.out, k)
        for _ in range(5):
            if scp_from(h, '%s/out.c%d.full' % (d, k), loc) and md5f(loc) == mm.get('md5'): break
            time.sleep(10)
        else:
            log('%s chunk %d: pulled output md5 != remote md5' % (name, k)); return 'FAILED'
        ok = mm.get('result') == 'yes' and mm.get('manifest') == 'same'
        with LOCK:
            self.state[k].update({'status': 'done' if ok else 'failed', 'machine': name, 'secs': int(mm['end']) - int(mm['start']), 'md5': mm['md5'], 'rc': mm['rc'], 'result': mm['result'], 'manifest': mm['manifest'], 'host': mm['host']})
        self.save()
        log('%s chunk %d %s in %ds (result line %s, manifest %s)' % (name, k, 'done' if ok else 'FAILED', self.state[k]['secs'], mm['result'], mm['manifest']))
        return 'OK' if ok else 'FAILED'

    # ---- queue ---------------------------------------------------------------------------------------------------------------------------
    def take(self, name):
        got = (None, False)
        with LOCK:
            for k, s in self.state.items():
                if s['status'] == 'running' and s['machine'] == name and not s.get('claimed'):
                    s['claimed'] = True; got = (k, True); break          # re-attach after a resume
            else:
                for k, s in self.state.items():
                    if s['status'] == 'pending':
                        s.update({'status': 'running', 'machine': name, 'claimed': True, 'attempts': s['attempts'] + 1}); got = (k, False); break
        if got[0] is not None: self.save()      # a 'running' chunk must be on disk BEFORE it is launched, so a resume can re-attach to it (first resume test found 0 chunks to re-attach)
        return got

    def worker(self, name):
        while True:
            k, attach = self.take(name)
            if k is None: return
            r = self.do_chunk(name, k, attach)
            if r in ('DEAD', 'FAILED'):
                with LOCK:
                    s = self.state[k]; s.pop('claimed', None)
                    s['status'] = 'pending' if s['attempts'] < 3 else 'failed'
                self.save()
                log('%s chunk %d %s (attempt %d): %s' % (name, k, r, self.state[k]['attempts'], 'requeued' if self.state[k]['status'] == 'pending' else 'GIVEN UP'))

    def run_all(self):
        if self.resume and os.path.exists(self.statef):
            old = json.load(open(self.statef))
            if old['ledger_md5'] != self.ledger_md5 or old['config'] != self.cfg: sys.exit('RESUME REFUSED: config or ledger changed')
            for k, s in old['state'].items():
                k = int(k)
                loc = '%s.c%d.full' % (self.out, k)
                if s['status'] == 'done' and os.path.exists(loc) and md5f(loc) == s.get('md5'): self.state[k] = s
                elif s['status'] == 'running': s.pop('claimed', None); self.state[k] = s
            log('resume: %d chunks kept done, %d to re-attach' % (sum(1 for s in self.state.values() if s['status'] == 'done'), sum(1 for s in self.state.values() if s['status'] == 'running')))
        else:
            for f in os.listdir(os.path.dirname(self.out) or '.'):
                if f.startswith(os.path.basename(self.out) + '.') and f != os.path.basename(self.out) + '.dist.json': pass
        for name in self.m: self.setup_machine(name)
        self.save()
        log('%d rows in %d chunks of up to %d rows; machines %s' % (len(self.rows), len(self.chunks), self.cfg['rows_per_chunk'], ', '.join('%s x%d' % (n, m['slots']) for n, m in self.m.items())))
        ths = [threading.Thread(target=self.worker, args=(n,), daemon=True) for n, m in self.m.items() for _ in range(m['slots'])]
        for t in ths: t.start()
        for t in ths: t.join()
        self.finish()

    # ---- merge ---------------------------------------------------------------------------------------------------------------------------
    def finish(self):
        mfok = {}
        for name, mc in self.m.items():
            d = shlex.quote(mc['dir'])
            rc, o = ssh(mc['host'], 'cd %s && %s sh fnfuzz_chunk.sh end %s %s %s %s %d' % (d, envprefix(self.common_env(name)), d, shlex.quote(mc['fz']), shlex.quote(mc['stock']), shlex.quote(mc['rebuilt']), self.trials))
            mfok[name] = o.strip().split('\n')[-1] == 'same'
            scp_from(mc['host'], mc['dir'] + '/manifest.end', self.out + '.manifest.end.' + name)
        bad = [k for k, s in self.state.items() if s['status'] != 'done']
        outl = []; sums = [0, 0, 0, 0, 0]
        tsv = open(self.out + '.chunks.tsv', 'w'); tsv.write('chunk\tfirst_row\tcount\tmachine\tsecs\tmd5\tresult\n')
        for k, first, cnt in self.chunks:
            s = self.state[k]
            tsv.write('%d\t%d\t%d\t%s\t%s\t%s\t%s\n' % (k, first, cnt, s.get('machine'), s.get('secs'), s.get('md5'), s.get('result')))
            loc = '%s.c%d.full' % (self.out, k)
            if not os.path.exists(loc): continue
            for l in open(loc, errors='replace').read().split('\n'):
                m = re.match(r'^fnfuzz: (\d+) functions, (\d+) trials .*?; (\d+) differ, (\d+) uninformative .*?, (\d+) nondeterministic', l)
                if m:
                    for i in range(5): sums[i] += int(m.group(i + 1))
                elif l.startswith('RESULT: ') or l == '': pass
                else: outl.append(l)
        tsv.close()
        per = {}
        for s in self.state.values():
            if s.get('machine'): a = per.setdefault(s['machine'], [0, 0]); a[0] += 1; a[1] += s.get('secs') or 0
        outl.append('distributed run: %s; per-chunk machines in %s.chunks.tsv; wall %ds' % ('; '.join('%s %d chunks, %ds of chunk time' % (n, v[0], v[1]) for n, v in sorted(per.items())), os.path.basename(self.out), int(time.time() - self.t0)))
        for name in self.m:
            fx = [l.split() for l in open(self.out + '.manifest.' + name) if l.startswith('file ')]
            outl.append('manifest %s: %s (start == end: %s)' % (name, ', '.join('%s %s' % (x[1], x[2]) for x in fx if x[1] in ('harness', 'ledger', 'stock', 'rebuilt')), mfok[name]))
        allok = not bad and all(mfok.values())
        if allok:
            outl.append('fnfuzz: %d functions, %d trials (each: stock twice + rebuilt; merged from chunks); %d differ, %d uninformative (always the same signal), %d nondeterministic in the stock' % tuple(sums))
            outl.append('RESULT: PASS' if sums[2] == 0 else 'RESULT: FAIL')
            open(self.out + '.merged.done', 'w').write('done\n')
        else:
            outl.append('NO RESULT: %s' % ('chunk(s) %s incomplete or failed' % bad if bad else 'a machine manifest CHANGED during the run'))
        open(self.out + '.full', 'w').write('\n'.join(outl) + '\n')
        log('merged: ' + outl[-1] + (' | ' + outl[-2][:120] if allok else ''))

if __name__ == '__main__':
    if len(sys.argv) < 2: sys.exit(__doc__)
    cfg = json.load(open(sys.argv[1]))
    Dist(cfg, '--resume' in sys.argv).run_all()
