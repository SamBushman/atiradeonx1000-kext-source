#!/usr/bin/env python3
"""disfn.py SUBSTRING [LINES] - print the disassembly of the function(s) whose symbol contains SUBSTRING, from the stock and the rebuilt kext.
The disassemblies are `otool -arch ppc -tV` dumps made on the Tiger machine: $STOCK_DIS (made once from the stock kext) and $REBUILT_DIS
(Tools/difftest/build_rebuilt.sh writes build/difftest/rebuilt.dis next to the binary)."""
import sys, os, re


def fn(path, sub, n):
    out, on = [], False
    for ln in open(path, errors='replace'):
        s = ln.strip()
        if re.match(r'^_\S+:$', s):
            if on: break
            on = sub in s
            if on: out.append(s)
            continue
        if on: out.append(ln.rstrip('\n'))
    return out[:n]


if __name__ == '__main__':
    sub = sys.argv[1]; n = int(sys.argv[2]) if len(sys.argv) > 2 else 80
    for lab, env in (('STOCK', 'STOCK_DIS'), ('REBUILT', 'REBUILT_DIS')):
        p = os.environ.get(env)
        print('=====', lab)
        if p and os.path.exists(p):
            print('\n'.join(fn(p, sub, n)))
        else:
            print('(set $%s to an `otool -arch ppc -tV` dump)' % env)
