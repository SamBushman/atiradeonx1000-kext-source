#!/usr/bin/env python3
"""greedy_use_rows.py - keep the `use` rows of a rename table that leave the compiled object unchanged.

A `use` row splits one decompile variable in two; the names alone cannot change the code, but a second variable can change gcc 4.0.1's register allocation,
so every split is checked: the rows are applied one at a time (in table order) on top of the committed sources plus the `def`/`decl` rows, and a row is
kept only if Tools/renames/quickcheck.sh finds the objects of the files it touched identical to the committed build. The accepted rows are written to
OUT (a table), the rejected ones are listed.
Usage: greedy_use_rows.py TABLE OUT      (run from the repository root; the working tree's Sources/ and Headers/ are reset to HEAD and rebuilt from TABLE)
Needs the Tiger host of Tools/renames/quickcheck.sh. Patches of patched files are not regenerated here: run Tools/renames/make_patch.sh on them afterwards.
"""
import os, subprocess, sys

def run(cmd, **kw): return subprocess.run(cmd, capture_output=True, text=True, **kw)

def main():
    table, out = sys.argv[1], sys.argv[2]
    lines = open(table).read().split('\n')
    head = [l for l in lines if l.startswith('#')]
    rows = [l for l in lines if l.strip() and not l.startswith('#')]
    defs = [l for l in rows if l.split('\t')[0] != 'use']
    uses = [l for l in rows if l.split('\t')[0] == 'use']
    tmp = out + '.try'
    def reset(): run(['git', 'checkout', 'HEAD', '--', 'Sources', 'Headers'])
    def apply(table_rows):
        open(tmp, 'w').write('\n'.join(head + table_rows) + '\n')
        r = run(['python3', 'Tools/apply_renames.py', tmp])
        errs = [l for l in r.stderr.split('\n') if l.startswith('ERROR') and 'patch' not in l and '.patch' not in l]
        return errs
    reset()
    e = apply(defs)
    if e: sys.exit('the def/decl rows do not apply:\n' + '\n'.join(e))
    accepted, rejected = [], []
    for r in uses:
        before = set(run(['git', 'diff', '--name-only', 'Sources']).stdout.split())
        errs = apply(defs + accepted + [r])
        if errs:
            rejected.append((r, 'anchors: ' + errs[0][:150])); reset(); apply(defs + accepted); continue
        changed = sorted(run(['git', 'diff', '--name-only', 'Sources']).stdout.split())
        q = run(['sh', 'Tools/renames/quickcheck.sh'] + changed)
        if q.returncode == 0:
            accepted.append(r); print('kept     ', r.split('\t')[1], r.split('\t')[2], '->', r.split('\t')[3], flush=True)
        else:
            rejected.append((r, 'object differs' if q.returncode == 1 else 'compile failed: ' + q.stdout[-200:]))
            print('REJECTED ', r.split('\t')[1], r.split('\t')[2], '->', r.split('\t')[3], '(' + rejected[-1][1][:40] + ')', flush=True)
            reset(); apply(defs + accepted)
    open(out, 'w').write('\n'.join(head + defs + accepted) + '\n')
    os.remove(tmp)
    print('%d use rows kept, %d rejected' % (len(accepted), len(rejected)))

if __name__ == '__main__':
    main()
