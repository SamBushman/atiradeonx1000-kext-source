"""MetaClass::alloc of the eight concrete classes (the shipped code: OSObject::operator new(size); if (p) construct(p); return p), with the allocation failing on odd seeds.
The macro-generated `return new className;` compiled to an unconditional constructor call (a write through a null `this` when the allocation fails, the #187 class).
Run: python3 Tools/difftest/difftest.py Tests/difftest/hand_cases_R2.py   (needs STOCK_KEXT; see Tools/difftest/README.md)"""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'Tools', 'difftest'))
from difftest import Case
from unicorn.ppc_const import UC_PPC_REG_3

CLASSES = ['ATIRadeonX1000', 'ATIR500GLContext', 'ATIR5002DContext', 'ATIR500DVDContext', 'ATIR500Surface', 'IOATIR500Shared', 'ATIR500Memory']


def w_metaclass(m, rng):
    return [m.alloc(0x40)]


def alloc_mock(m, name, k):
    """OSObject::operator new(size): fails on odd seeds, else a zeroed block of the requested size"""
    if 'operator new' in name or 'nwEm' in name:
        size = m.uc.reg_read(UC_PPC_REG_3)
        return 0 if m.seed % 2 else m.alloc(max(size, 0x10))
    return 0


CASES = [Case('_ZNK%d%s9MetaClass5allocEv' % (len(c), c), w_metaclass, ret='u32', seeds=8, mock=alloc_mock, plain_words=False, name='%s::MetaClass::alloc (allocation fails on odd seeds)' % c) for c in CLASSES]
