"""Automatic differential cases for every method of IOATIR500Surface that surface_cases.py does not cover by hand.

Each gets a generic world (common.auto_surface: a surface with a vtable, an accelerator, panel counts, list nodes, typed arguments from the mangled
signature) - enough to reach the code, not enough to reach every branch. Read the `cov` column: a low coverage or many inconclusive runs mean the
function needs a hand-written world (move it to surface_cases.py)."""
import os, sys, re
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(HERE, '..', '..', 'Tools', 'difftest'))
from difftest import Case, Image, demangle_all
from common import auto_surface, return_kind
import surface_cases

CLASS = 'IOATIR500Surface'
HEADER = os.path.join(HERE, '..', '..', 'Headers', CLASS + '.h')
_stock = Image(os.environ['STOCK_KEXT'], 'stock')     # the shipped kext binary (also passed to difftest.py)
_done = {c.function for c in surface_cases.CASES}
for _m in ('hand_cases', 'hand_cases_A', 'hand_cases_B', 'hand_cases_C', 'hand_cases_D', 'hand_cases_P1', 'hand_cases_P2'):     # functions with a hand-written world need no generic one
    _done |= {c.function for c in __import__(_m).CASES}
SKIP = re.compile(r'(C[12]E|D[012]E|getMetaClass|MetaClass|^__ZN16IOATIR500Surface9metaClass)')

CASES = []
names = sorted(n for n in _stock.funcs if n.startswith('__ZN%d%s' % (len(CLASS), CLASS)) and not SKIP.search(n))
dem = demangle_all(names)
for n in names:
    d = dem[n]
    meth = d.split('(')[0].split('::')[-1]
    if (CLASS + '::' + meth) in _done:
        continue
    CASES.append(Case(CLASS + '::' + meth, auto_surface, ret=return_kind(HEADER, meth), signature=d[d.index('::') + 2:], name=d, seeds=12))
