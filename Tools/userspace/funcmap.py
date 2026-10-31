#!/usr/bin/env python3
"""funcmap.py DIR [--link] - print `new<TAB>old` for every `func` row of DIR/names*.tsv (the compile gate maps candidate symbol names back to the Ghidra names)

--link (datacheck.sh): leave out the EXPORTED rows. Those functions are labelled by their Mach-O name in the link whatever the C name is (link_corpus.fn_label), so the
link output of base and candidate already carries the same label and must not be mapped back to the fragment's old name."""
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import apply_names as A
funcs = A.load_funcs(sys.argv[1])
if '--link' in sys.argv[2:]:
    funcs = [r for r in funcs if r[4] != 'EXPORTED']
for new, old in A.func_roots(funcs).items():          # chained rows map to the Ghidra name
    print('%s\t%s' % (new, old))
