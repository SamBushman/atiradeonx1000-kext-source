"""Hand-written worlds for functions whose generic world (all_classes_cases.py) does not give a meaningful run - typically because a random
argument indexes a table out of bounds (the two builds lay their data out differently, so that is an artifact, not a defect). Run:
python3 Tools/difftest/difftest.py Tests/difftest/hand_cases.py"""
import os, sys, struct
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'Tools', 'difftest'))
from difftest import Case
from common import surface_world, word, fill_words


def fbits(f): return struct.unpack('>I', struct.pack('>f', f))[0]


FLOATS = [0.0, -0.0, 1.0, -1.0, 0.5, 2.0, 128.0, 1e-3, -300.0, 65535.0]


def w_linear_transform(m, rng):
    """set_linear_transform(matrixIndex, OverlayPictureControl*, OverlayRegisters*): the index selects one of the two 7-double rows of the global
    colour-space matrix (CO[14]); the control record holds gain (+0), contrast (+4) and brightness (+0xc) as floats; the register image is written at +0x1b0.."""
    SELF, ACCEL = surface_world(m, rng, 'ATIR500Surface')
    ctl = m.alloc(0x40); regs = m.alloc(0x400)
    for off in (0, 4, 0xc):
        m.w32(ctl + off, fbits(rng.choice(FLOATS)))
    return [SELF, rng.choice([0, 1]), ctl, regs]


CASES = [
    Case('ATIR500Surface::set_linear_transform', w_linear_transform, ret='void', seeds=40),
]
