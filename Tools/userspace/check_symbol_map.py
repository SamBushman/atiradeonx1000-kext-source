#!/usr/bin/env python3
"""check_symbol_map.py SYMBOL_MAP.tsv NM_OF_DATA_OBJECT - every data symbol the corpus uses, whose row says it is defined in data.s, is a defined symbol of the
assembled data object (`nm obj/data.o` on the G5; also accepts `nm` of the linked image), and no row is marked NOT DEFINED. Prints the counts."""
import sys
rows = [l.rstrip('\n').split('\t') for l in open(sys.argv[1])][1:]
defined = set()
for l in open(sys.argv[2]):
    f = l.split()
    if len(f) == 3 and f[1] in 'TtDdSsBbAaCc':
        defined.add(f[2])
    elif len(f) == 3 and f[1] in ('U', 'u'):
        pass
missing = [r[0] for r in rows if r[7] == 'data.s' and r[0] not in defined]
notdef = [r[0] for r in rows if r[7] == 'NOT DEFINED']
explained = sum(1 for r in rows if r[7] not in ('data.s', 'NOT DEFINED'))
print('%d symbols in the map: %d defined in data.s and present in the object, %d missing, %d provided by the toolchain/linker/asm code (reason in the map), %d unexplained' % (len(rows), sum(1 for r in rows if r[7] == 'data.s') - len(missing), len(missing), explained, len(notdef)))
for n in (missing + notdef)[:15]:
    print('  ', n)
sys.exit(1 if missing or notdef else 0)
