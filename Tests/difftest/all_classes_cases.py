"""Generic differential cases for every method of the kext's classes except IOATIR500Surface (surface_auto_cases.py): a "pointer soup" world
(common.generic_this) with the class's vtable, an accelerator with a register window and a flip-flop device model. They show which functions the
generic world already exercises (cov column) and which need a hand-written world (inconclusive / low coverage)."""
import os, sys, re
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(HERE, '..', '..', 'Tools', 'difftest'))
from difftest import Case, Image, demangle_all
from common import make_generic_world, CONCRETE

CLASSES = ['ATIRadeonX1000', 'IOATIR500Accelerator', 'IOATIR500GLContext', 'ATIR500GLContext', 'IOATIR5002DContext', 'ATIR5002DContext',
           'IOATIR500DVDContext', 'ATIR500DVDContext', 'ATIR500Surface', 'IOATIR500Shared', 'ATIR500Memory']
_stock = Image(os.environ['STOCK_KEXT'], 'stock')
SKIP = re.compile(r'(C[12]E|D[012]E|MetaClass|metaClass|_GLOBAL__N|__static_init)')
_manual = set()
for mod in ('surface_cases', 'registers_cases'):
    try:
        m = __import__(mod)
        _manual |= {c.function for c in m.CASES}
    except Exception:
        pass


def header_return(cls, meth):
    p = os.path.join(HERE, '..', '..', 'Headers', cls + '.h')
    if os.path.exists(p):
        for ln in open(p):
            mm = re.match(r'^\s*(?:virtual\s+|static\s+)?((?:unsigned\s+)?[A-Za-z_][\w:]*[\s\*&]+)%s\s*\(' % re.escape(meth), ln)
            if mm:
                t = mm.group(1).strip()
                return 'void' if t == 'void' else 'bool' if t == 'bool' else 'u32'
    return 'u32'


CASES = []
for cls in CLASSES:
    names = sorted(n for n in _stock.funcs if re.match(r'^__ZN%d%s\d' % (len(cls), cls), n) and not SKIP.search(n))
    dem = demangle_all(names)
    world = make_generic_world(cls)
    for n in names:
        d = dem[n]
        meth = d.split('(')[0].split('::')[-1]
        if (cls + '::' + meth) in _manual:
            continue
        CASES.append(Case(cls + '::' + meth, world, ret=header_return(cls, meth), signature=d[d.index('::') + 2:], name=d, seeds=10))
