#!/usr/bin/env python3
"""decode_composite_record.py - issue #141: decode the real 0x12000000 (MC-composite) record from a
captures/comp/*/*.tsv.mem write-ahead snapshot, per the field layout read from the real client's
record builder (FUN_00007850, Userspace/ATIRadeonX1000VADriver/ppc/part_001.c:2199).

Usage: decode_composite_record.py <run.tsv.mem> [seq]
Without seq, decodes every snapshot that contains the tag and prints how far the point-list
pad pair at [0xe]/[0xf] has been overwritten with real content (see findings section 9p)."""
import re, struct, sys

def snaps(path):
    data = open(path, 'rb').read()
    for c in data.split(b'SNAP ')[1:]:
        hdr, rest = c.split(b'\n', 1)
        m = re.match(rb'seq=(\d+) why=(\S+) connect=(\S+)', hdr)
        mm = re.match(rb'MAP type=(\d+) addr=(\S+) size=(\S+) dumped=(\d+) ([0-9a-fA-F]+)', rest)
        if not m or not mm:
            continue
        raw = bytes.fromhex(mm.group(5).decode())
        words = struct.unpack('>%dI' % (len(raw) // 4), raw[:len(raw) // 4 * 4])
        yield dict(seq=m.group(1).decode(), why=m.group(2).decode(), addr=mm.group(2).decode(), words=words)


FIELDS = ['tag', 'f1', 'f2', 'f3', 'f4', 'f5', 'off_A', 'off_B', 'f8', 'f9', 'fA', 'fB', 'fC', 'fD', 'pt0_hi', 'pt0_lo']

if __name__ == '__main__':
    path = sys.argv[1]
    want_seq = sys.argv[2] if len(sys.argv) > 2 else None
    for s in snaps(path):
        if want_seq and s['seq'] != want_seq:
            continue
        idx = [i for i, w in enumerate(s['words']) if (w & 0xffff0000) == 0x12000000]
        for i in idx:
            rec = s['words'][i:i + 16]
            decoded = dict(zip(FIELDS, (hex(w) for w in rec)))
            filled = decoded['pt0_hi'] != '0x80000000'
            print(f"seq={s['seq']:>4} why={s['why']:<35} addr={s['addr']:<10} rec@{i:<4} "
                  f"len_field={rec[0] & 0xffff:#06x} off_A={hex(rec[6])} off_B={hex(rec[7])} "
                  f"point_list_entry_0={'FILLED ' + hex(rec[14]) + ',' + hex(rec[15]) if filled else 'empty (0x80000000 pad)'}")
