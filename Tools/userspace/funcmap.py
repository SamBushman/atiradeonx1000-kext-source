#!/usr/bin/env python3
"""funcmap.py DIR  - print `new<TAB>old` for every `func` row of DIR/names*.tsv (the compile gate maps candidate symbol names back to the Ghidra names)"""
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import apply_names as A
for f, n, old, new, tier, ev in A.load_funcs(sys.argv[1]):
    print('%s\t%s' % (new, old))
