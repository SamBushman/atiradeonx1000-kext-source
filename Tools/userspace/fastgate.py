#!/usr/bin/env python3
"""fastgate.py DIR TRIALDIR PART.c [PART.c ...] [--sem] - gate a split_trial.py result in seconds: compile TRIALDIR/base_<part> and TRIALDIR/<part> on the G5
(gcc -arch ppc -w -S, plus the -O1 -Wuninitialized warnings, exactly as verify_names.sh does) with DIR's headers, then run split_equiv.py (tier 1) and with
--sem also sem_equiv.py (tier 2) on the two assembler files. Needs the G5 (ssh G5). Prints the tools' output; exit 0 when tier 1 passes."""
import os, sys, subprocess, tempfile, glob, shutil
H = os.path.dirname(os.path.abspath(__file__))


def sh(c, **k): return subprocess.run(c, shell=True, capture_output=True, text=True, **k)


def rsh(cmd): return subprocess.run(['ssh', 'G5', 'sh', '-s'], input=cmd, capture_output=True, text=True)


def main():
    a = [x for x in sys.argv[1:] if not x.startswith('--')]; sem = '--sem' in sys.argv
    d, trial, parts = a[0], a[1], a[2:]
    tmp = os.environ.get('TMPDIR', '/tmp'); w = tempfile.mkdtemp(prefix='fg_', dir=tmp)
    stage = os.path.join(w, 'stage'); os.makedirs(stage)
    for h in glob.glob(os.path.join(d, '*.h')): shutil.copy(h, stage)
    for p in parts:
        shutil.copy(os.path.join(trial, 'base_' + p), os.path.join(stage, 'base_' + p)); shutil.copy(os.path.join(trial, p), os.path.join(stage, 'cand_' + p))
    r = 'rung3/fg_%d' % os.getpid()
    sh('tar czf %s/s.tgz -C %s .' % (w, stage))
    x = sh('ssh G5 "rm -rf %s; mkdir -p %s" && scp -q %s/s.tgz G5:%s/s.tgz' % (r, r, w, r))
    if x.returncode: sys.exit('ssh/scp failed: ' + x.stderr)
    cmd = 'cd %s && tar xzf s.tgz && for p in %s; do for s in base cand; do gcc -arch ppc -w -S ${s}_$p -o ${s}_$p.dis 2>${s}_$p.err || echo FAIL $s $p; gcc -arch ppc -O1 -Wuninitialized -c ${s}_$p -o /dev/null 2> ${s}_$p.warn; done; done' % (r, ' '.join(parts))
    x = rsh(cmd); print(x.stdout.strip())
    rc = 0
    for p in parts:
        for s in ('base', 'cand'):
            for ext in ('dis', 'warn', 'err'):
                sh('scp -q G5:%s/%s_%s.%s %s/%s_%s.%s' % (r, s, p, ext, w, s, p, ext))
        bd, cd, bw, cw = ['%s/%s_%s.%s' % (w, s, p, e) for s, e in (('base', 'dis'), ('cand', 'dis'), ('base', 'warn'), ('cand', 'warn'))]
        if not os.path.exists(cd) or os.path.getsize(cd) == 0: print('COMPILE FAIL cand', p); print(open('%s/cand_%s.err' % (w, p)).read()[:1500]); rc = 1; continue
        t1 = sh('python3 %s/split_equiv.py %s %s %s %s' % (H, bd, cd, bw, cw)); print('tier1 %s:' % p, t1.stdout.strip()[-1500:])
        if t1.returncode: rc = 1
        if sem and os.path.exists(os.path.join(H, 'sem_equiv.py')):
            t2 = sh('python3 %s/sem_equiv.py %s %s' % (H, bd, cd)); print('sem %s:' % p, t2.stdout.strip()[-3000:])
    rsh('rm -rf %s' % r); print('files:', w)
    sys.exit(rc)


main()
