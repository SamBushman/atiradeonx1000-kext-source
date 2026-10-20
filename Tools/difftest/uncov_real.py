#!/usr/bin/env python3
"""uncov_real.py MODULE_OR_FILE [FILTER] - run the cases of a case file and print, per case, the STOCK instructions no run executed, minus `nop` padding
(the disassembly is $STOCK_DIS, `otool -tV` of the stock kext). A case whose output is empty reaches all real code. Needs $STOCK_KEXT and a built rebuilt image."""
import sys, os, re
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE); sys.path.insert(0, os.path.join(HERE, '..', '..', 'Tests', 'difftest'))
import difftest as d


def load_dis(path):
    ins = {}
    for ln in open(path, errors='replace'):
        m = re.match(r'^([0-9a-f]{8})\t(.*)$', ln.rstrip('\n'))
        if m: ins[int(m.group(1), 16)] = m.group(2)
    return ins


def main():
    path, flt = sys.argv[1], (sys.argv[2] if len(sys.argv) > 2 else '')
    files = re.findall(r'Tests/difftest/\w+\.py', open(os.path.join(HERE, '..', '..', 'Tests', 'difftest', 'run_all.sh')).read()) if path == 'ALL' else [path]
    files = [os.path.join(HERE, '..', '..', f) if not os.path.isabs(f) and not os.path.exists(f) else f for f in files]
    stock = d.Image(os.environ['STOCK_KEXT'], 'stock'); reb = d.Image(d.REBUILT_DEFAULT, 'rebuilt'); reg = d.StubRegistry()
    dis = load_dis(os.environ['STOCK_DIS'])
    for c in [c for f in files for c in d.load_cases(f)]:
        if flt not in c.name: continue
        sym, res = d.run_case(c, stock, reb, reg)
        entry = stock.funcs[sym]
        miss = []
        for lo, hi in c.uncov[0]:
            for off in range(lo, hi, 4):
                t = dis.get(entry + off)
                if t is None or t.startswith('nop'): continue
                miss.append((off, t))
        print('%s: cov %d%%/%d%%  real uncovered %d insns (function at 0x%x)' % (c.name, round(100 * c.cov[0]), round(100 * c.cov[1]), len(miss), entry))
        last = None
        for off, t in miss:
            print('   %4x  %05x  %s' % (off, entry + off, t))


main()
