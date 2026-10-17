"""Hand-written world for the free function track_regs_written_by_pm4 (no generic world exists for free functions). Run:
python3 Tools/difftest/difftest.py Tests/difftest/hand_cases_U6P.py"""
import os, sys
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'Tools', 'difftest'))
from difftest import Case


def w_track_regs(m, rng):
    """track_regs_written_by_pm4(tracked_register_set *state, UInt32 *rangeStart, UInt32 *rangeEnd): a stream of whole PM4 packets that ends exactly at
    rangeEnd - type 0 (header: count-1 in bits 16-29, register in bits 0-12, bit 15 = write the same register), type 1 (two register pairs, 3 dwords),
    type 2 (one dword), type 3 (header + count+1 dwords skipped); store_reg is a mocked callee, so every (register, value) it is given is compared."""
    state = m.alloc(0x100)
    words = []
    for _ in range(rng.randrange(1, 9)):
        t = rng.choice([0, 0, 1, 2, 3])
        if t == 0:
            cnt = rng.randrange(0, 5)
            words += [(cnt << 16) | rng.randrange(0x1fff) | rng.choice([0, 0x8000])] + [rng.getrandbits(32) for _ in range(cnt + 1)]
        elif t == 1:
            words += [(1 << 30) | rng.randrange(0x800) | (rng.randrange(0x800) << 11), rng.getrandbits(32), rng.getrandbits(32)]
        elif t == 2:
            words += [2 << 30]
        else:
            cnt = rng.randrange(0, 4)
            words += [(3 << 30) | (cnt << 16)] + [rng.getrandbits(32) for _ in range(cnt + 1)]
    base = m.alloc(4 * len(words) + 16)
    for i, w in enumerate(words):
        m.w32(base + 4 * i, w)
    return [state, base, base + 4 * len(words)]


CASES = [
    Case('__Z25track_regs_written_by_pm4P20tracked_register_setPmS1_', w_track_regs, ret='void', seeds=80),
]
