#!/usr/bin/env python3
"""filter_rows.py - keep only the rows of a rename table that leave the compiled objects byte-identical.

A `use` row splits one decompile variable into two; gcc 4.0.1 gives each variable its own register choice, so a perfectly valid split can still change the
generated code (and a split across which a value flows certainly does). This tool tries the rows one by one, in file order: for each `use` row it applies
"the rows accepted so far + this row" to a clean checkout and runs Tools/renames/quick_verify.sh (compile only the changed files, compare objects with
the base revision); the row is kept if every object is identical, rejected otherwise. `def` and `decl` rows are names only and are always kept.
Run it in a WORKTREE that has no other uncommitted Sources/Headers changes (it resets them with `git checkout`):

    filter_rows.py TABLE.tsv [BASE_REV=HEAD] [ssh-host=G5]       -> rewrites TABLE.tsv with the accepted rows, writes TABLE.tsv.rejected, leaves the accepted rows applied
Env: WORK (remote directory for quick_verify, default rung3/qv_filter).
"""
import os, subprocess, sys

def run(*a, **k): return subprocess.run(a, capture_output=True, text=True, **k)

def main():
    if len(sys.argv) < 2: sys.exit(__doc__)
    table = sys.argv[1]; base = sys.argv[2] if len(sys.argv) > 2 else 'HEAD'; host = sys.argv[3] if len(sys.argv) > 3 else 'G5'
    if run('git', 'status', '--porcelain', '--', 'Sources', 'Headers').stdout.strip():
        sys.exit('Sources/Headers have uncommitted changes: run this in a clean worktree')
    lines = open(table).read().rstrip('\n').split('\n')
    env = {**os.environ, 'WORK': os.environ.get('WORK', 'rung3/qv_filter')}
    tmp = table + '.trial'
    out, rejected, accepted_uses = [], [], 0
    def apply(rows):
        run('git', 'checkout', '-q', '--', 'Sources', 'Headers')
        open(tmp, 'w').write('\n'.join(rows) + '\n')
        return run('python3', 'Tools/apply_renames.py', tmp)
    for l in lines:
        f = l.split('\t')
        if not l.strip() or l.startswith('#') or f[0] != 'use':
            out.append(l); continue
        a = apply(out + [l])
        if a.returncode:
            rejected.append((l, 'does not apply: ' + a.stderr.strip().splitlines()[-1][:120])); continue
        q = run('sh', 'Tools/renames/quick_verify.sh', host, base, env=env)
        last = (q.stdout.strip().splitlines() or [q.stderr.strip()[:120]])[-1]
        if q.returncode == 0:
            out.append(l); accepted_uses += 1; print('keep    %-28s %s' % (f[3], f[1]), flush=True)
        else:
            rejected.append((l, last[:120])); print('reject  %-28s %s : %s' % (f[3], f[1], last[:90]), flush=True)
    apply(out)
    os.remove(tmp)
    open(table, 'w').write('\n'.join(out) + '\n')
    open(table + '.rejected', 'w').write(''.join('# %s\n%s\n' % (why, row) for row, why in rejected))
    print('kept %d use rows, rejected %d (see %s.rejected); the kept rows are applied' % (accepted_uses, len(rejected), table))

main()
