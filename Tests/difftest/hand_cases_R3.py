"""R3 hand worlds for functions flagged by the rlwscan triage (Tests/difftest/shift_audit.md section 4) whose generic or earlier hand worlds left their
condition-bit (CR pseudo-register) paths thin.
Run: python3 Tools/difftest/difftest.py Tests/difftest/hand_cases_R3.py   (needs STOCK_KEXT; see Tools/difftest/README.md)"""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'Tools', 'difftest'))
from difftest import Case
from unicorn.ppc_const import UC_PPC_REG_3
import hand_cases_A as HA


def w_hz_init(m, rng):
    """HZMEM_InitMemResource(hizData, hzMode, numPipes, numZPipes): every mode 0-3, and the n-th IOMallocPageable fails (n = 1..6, or none), so each
    allocation-failure cleanup runs as well as the success path"""
    m.hz_fail_at = rng.choice([0, 0, 1, 2, 3, 4, 5, 6])
    m.hz_mallocs = 0
    hz = m.alloc(0x20)
    return [hz, rng.choice([0, 1, 2, 3, 3, 4]), rng.choice([1, 2, 4, 6, 8]), rng.choice([1, 2, 4])]


def hz_mock(m, name, k):
    if 'IOMallocPageable' in name:
        m.hz_mallocs += 1
        if m.hz_mallocs == m.hz_fail_at: return 0
        return m.alloc(max(m.uc.reg_read(UC_PPC_REG_3), 0x10))
    return 0


PITCHES = [0x8, 0x40, 0x7f8, 0x800, 0x1000, 0x1f800, 0x2000, 0x3ff8, 0x7fff8, 0xfff8, 0x1fff8]


def w_pageoff_cpu_pitch(m, rng):
    """pageoff_dirty_texture_with_cpu with source pitches whose >>3 reaches bits 8-12 (the register word packs (pitch>>3) as a byte-reversed field; the earlier world kept the
    pitch below 0x800, so a wrong mask on those bits went unnoticed - mutation check, Tests/difftest/shift_audit.md)"""
    args = HA.w_pageoff_cpu(m, rng)
    m.w32(args[2] + 0xc, rng.choice(PITCHES))
    return args


CASES = [
    Case('__Z21HZMEM_InitMemResourceP7_HZDATAmmm', w_hz_init, ret='u32', name='HZMEM_InitMemResource (failure injection R3)', seeds=240, mock=hz_mock, plain_words=True),
    Case('ATIRadeonX1000::pageoff_dirty_texture_with_cpu', w_pageoff_cpu_pitch, ret='void', name='pageoff_dirty_texture_with_cpu (wide pitches R3)', seeds=80, plain_words=True),
]
