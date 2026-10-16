"""Differential cases for IOATIR500Surface (stock vs rebuilt). Run: python3 Tools/difftest/difftest.py Tests/difftest/surface_cases.py"""
import os, sys
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'Tools', 'difftest'))
from difftest import Case
from common import surface_world, word, small, fill_words, surface_with_contexts, texture_buffer


def s16(v): return v & 0xffff


def w_size_supported(m, rng):
    SELF, ACCEL = surface_world(m, rng)
    return [SELF, s16(rng.choice([0, 1, 4, 100, 1024, 4096, 0x7fff, -1, -100])), s16(rng.choice([0, 1, 4, 100, 1024, 4096, 0x7fff, -1]))]


def w_convert_bits(m, rng):
    SELF, ACCEL = surface_world(m, rng)
    return [SELF, rng.choice([0, 1, 2, 4, 8, 0x10, 0x80, 0x100, 0x400, 0x800, 0x10000, 0x10f9f, rng.getrandbits(17)])]


def w_idx_mask(m, rng):
    SELF, ACCEL = surface_world(m, rng)
    out = m.alloc(0x100)
    return [SELF, rng.choice([0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11, 0x11, 0x12, word(rng)]), out]


def w_get_state(m, rng):
    SELF, ACCEL = surface_world(m, rng)
    return [SELF, m.alloc(0x100)]


def w_one_arg(m, rng):
    SELF, ACCEL = surface_world(m, rng)
    return [SELF, word(rng)]


def w_two_args(m, rng):
    SELF, ACCEL = surface_world(m, rng)
    return [SELF, word(rng), word(rng)]


def w_no_args(m, rng):
    SELF, ACCEL = surface_world(m, rng)
    return [SELF]


def w_lock(m, rng):
    SELF, ACCEL = surface_world(m, rng)
    return [SELF, m.alloc(0x100), rng.choice([0, 0x44, 0x48])]


def w_set_scaling(m, rng):
    SELF, ACCEL = surface_world(m, rng)
    sc = m.alloc(0x100); fill_words(m, sc, 0x100, rng)
    rec = m.alloc(0x100); fill_words(m, rec, 0x100, rng)                 # the per-panel region record at +0xd60: width/height halves at +8/+0xa
    m.w16(rec + 8, rng.choice([0, 1, 640, 1920, 4096])); m.w16(rec + 10, rng.choice([0, 1, 480, 1080, 4096]))
    m.w32(SELF + 0xd60, rec); m.w32(SELF + 0xd68, rec)
    return [SELF, word(rng), rng.choice([0, sc])]


def w_cmft(m, rng):
    SELF, ACCEL = surface_world(m, rng)
    return [SELF, rng.choice([0, 1, 2, 3, word(rng)]), m.alloc(0x10), m.alloc(0x10)]


def w_delete_buffer_backing(m, rng):
    SELF, ACCEL = surface_world(m, rng)
    return [SELF, texture_buffer(m, rng, SELF)]


CASES = [
    Case('IOATIR500Surface::update_contexts', surface_with_contexts, ret='void'),
    Case('IOATIR500Surface::reset_req_bits', surface_with_contexts, ret='void'),
    Case('IOATIR500Surface::delete_buffer_backing', w_delete_buffer_backing, ret='void'),
    Case('IOATIR500Surface::is_surface_size_supported', w_size_supported, ret='s32'),
    Case('IOATIR500Surface::convert_surface_bits', w_convert_bits, ret='u32'),
    Case('IOATIR500Surface::surface_buffer_idx_mask', w_idx_mask, ret='u32'),
    Case('IOATIR500Surface::get_state', w_get_state, ret='u32'),
    Case('IOATIR500Surface::update_ref_stamps', w_two_args, ret='u32'),
    Case('IOATIR500Surface::surface_write_unlock_options', w_one_arg, ret='void'),
    Case('IOATIR500Surface::surface_write_unlock', w_no_args, ret='void'),
    Case('IOATIR500Surface::surface_query_lock', w_no_args, ret='u32'),
    Case('IOATIR500Surface::surface_write_lock', w_lock, ret='void'),
    Case('IOATIR500Surface::set_scaling', w_set_scaling, ret='u32', stack_args={'tmpAllocVRAM': {1: 16}}),
    Case('IOATIR500Surface::setupFullScreen', w_no_args, ret='void'),
    Case('IOATIR500Surface::set_volatile_state', w_one_arg, ret='void'),
]
