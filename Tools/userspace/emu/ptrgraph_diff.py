#!/usr/bin/env python3
"""ptrgraph_diff.py - the census (trace_diff.py --out) with POINTER-RICH inputs.  The census arena is random words (30% valid pointers, 30% garbage), so a function that walks several levels of a
structure faults at the first garbage field in both images and only the common prefix is compared.  Here the arena of trial t is built from one of six profiles (t mod 6) in which almost every
word is a valid arena pointer (to a 16-byte aligned place), a small count or zero, never garbage, and the pointer arguments are such objects:
  0: 85% pointers, 10% small (0..8), 5% zero; all eight arguments pointers
  1: 70% pointers, 20% small (1..16), 10% zero; argument 1 a pointer, the others small
  2: 85% pointers, 10% small, 5% zero; arguments as the ledger's signature says (p/i -> pointer, n -> small, f/d -> doubles)
  3: 50% pointers, 40% small (0..3), 10% zero; argument 1 a pointer, the rest as the signature
  4: every word a pointer; all arguments pointers      5: 94% pointers, 6% small (1..2); all arguments pointers
usage: same as trace_diff.py --out (census), plus env TD_REPAIR=12 TD_HEAP=1 TD_ENTRYARGS=1 as for the repaired census."""
import sys, os, struct, random
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import trace_diff as t

def _profile(seed): return (seed % 100003) % 6

class GGen(t.Gen):
    def __init__(self, seed): super().__init__(seed); self.prof = _profile(seed)
    def aptr(self): return t.ARENA + 0x1000 + (self.r.randrange(t.ARENA_SIZE - 0x3000) & ~0xf)
    def arena(self):
        r = self.r; out = bytearray(); pp, ps = ((85, 10), (70, 20), (85, 10), (50, 40), (100, 0), (94, 6))[self.prof]; lo, hi = ((0, 8), (1, 16), (0, 8), (0, 3), (0, 0), (1, 2))[self.prof]
        for i in range(t.ARENA_SIZE // 4):
            k = r.randrange(100)
            w = self.aptr() if k < pp else r.randint(lo, hi) if k < pp + ps else 0
            out += struct.pack('>I', w)
        return bytes(out)
    def call(self, pc, valid=False):
        ia, da, sw = super().call(pc, valid)
        if self.prof in (0, 4, 5): ia = [self.aptr() for _ in range(8)]
        elif self.prof == 1: ia = [self.aptr()] + [self.r.randint(1, 16) for _ in range(7)]
        else:
            ia = [self.aptr() if (ch in 'pi' or k == 0) else v for k, (ch, v) in enumerate(zip((pc.split('-')[0] + '--------')[:8], ia))]
            if self.prof == 3: ia[0] = self.aptr()
            ia = [x if not (t.ARENA <= x < t.ARENA + t.ARENA_SIZE) or k == 0 or (pc.split('-')[0] + '--------')[k] in 'pi' else self.r.randint(0, 3) for k, x in enumerate(ia)]
        sw = [self.aptr() if self.r.randrange(2) else self.r.randint(0, 8) for _ in range(16)]
        return ia, da, sw

t.Gen = GGen
if __name__ == '__main__': t.main(sys.argv[1:])
