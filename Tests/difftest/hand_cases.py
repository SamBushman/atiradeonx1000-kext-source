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


def w_surface_from_texture(m, rng):
    """build_surface_from_texture(texture, surfaceBuffer, width, height, formatIndex, offset, pitch): formatIndex selects one of the 48 entries of
    ati_format_info_table (a larger one reads past the table: the two builds lay the table out differently); the texture header's byte at +0x15 holds the
    tiling/sample field (bits 2-4), the texture's own fields are read from +0x40..+0x4c, +0x6c and +0x7a."""
    this = m.alloc(0x100); fill_words(m, this, 0x100, rng); m.w32(this, m.vtable('ATIR500GLContext'))
    tex = m.alloc(0xc0); fill_words(m, tex, 0xc0, rng)
    hdr = m.alloc(0x40); fill_words(m, hdr, 0x40, rng); m.w32(tex + 0x14, hdr)
    m.w8(tex + 0x20, rng.choice([0, 6, 6, 1])); m.w8(hdr + 0x15, rng.getrandbits(8))
    buf = m.alloc(0x60); fill_words(m, buf, 0x60, rng)
    return [this, tex, buf, rng.choice([0, 8, 16, 64, 256, 1024]), rng.choice([0, 8, 16, 64, 256, 1024]), rng.randrange(48), word(rng) & 0xffff00, rng.choice([0, 16, 64, 512, 4096])]


CASES = [
    Case('ATIR500GLContext::build_surface_from_texture', w_surface_from_texture, ret='void', seeds=40),
    Case('ATIR500Surface::set_linear_transform', w_linear_transform, ret='void', seeds=40),
]
