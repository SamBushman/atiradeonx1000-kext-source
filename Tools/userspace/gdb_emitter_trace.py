#!/usr/bin/env python3
"""gdb_emitter_trace.py - issue #42: build a gdb-696 script that traces which STOCK GLDriver functions run during a GL program, so the GL call behind an opcode can be read off a backtrace.

The stock ATIRadeonX1000GLDriver bundle is loaded by libGL via NSLinkModule; in the programs of this project it maps at 0x1008000 (runtime = 0x1008000 + the function's address in the bundle, which is the
FUN_xxxxxxxx number of the Ghidra reconstruction). Recipe (memory: g5-ancient-gdb-technique and the #80 handoff): break NSLinkModule, run, finish/continue x3 until the bundle is loaded, delete that breakpoint,
then raw-address breakpoints (`break *0xADDR`, no symbol scan) whose command lists print a label and a short backtrace and continue (no nested `commands`, no `finish`, no conditions on hot functions).

Usage: gdb_emitter_trace.py PROGRAM "ARGS" LABEL=0xFUNCADDR [LABEL=0xFUNCADDR ...] > trace.gdb      (run on the G5:  gdb -batch -x trace.gdb 2>&1 > out.log, killed after a timeout)
Each hit prints:  TRACE <label> hit  followed by `bt 14` (raw return addresses; symbolicate offline with Tools/userspace/gdb_trace_symbolicate.py).
"""
import sys, os
BASE = 0x1008000
LIMIT = int(os.environ.get('GDBT_LIMIT', '20'))
prog, args = sys.argv[1], sys.argv[2]
items = []
regs = []
for a in sys.argv[3:]:           # LABEL=0xADDR  or  LABEL=0xADDR@r3,r4  (also print those registers in hex)
    lab, rest = a.split("=")
    ad, _, rg = rest.partition("@")
    items.append((lab, ad)); regs.append([r for r in rg.split(",") if r])
o = ["set confirm off", "set breakpoint pending on", "set width 0", "set height 0", "break NSLinkModule", "run %s" % args, "finish", "continue", "finish", "continue", "finish", "delete 1"]
o += ["set $n%d = 0" % i for i in range(len(items))]
for i, (label, addr) in enumerate(items):
    # the first 20 hits of each breakpoint print a backtrace (hit counts are in the TOTALS lines at the end); `if` inside commands is fine on this gdb, nested `commands` is not
    o += ["break *0x%x" % (BASE + int(addr, 16)), "commands", "silent", "set $n%d = $n%d + 1" % (i, i), "if $n%d < %d" % (i, LIMIT + 1), ('printf "TRACE %s hit %%d' % (label, ) + ''.join(' %s=%%x' % r for r in regs[i]) + '\\n", $n%d' % i + ''.join(', $%s' % r for r in regs[i])), "bt 12", "end", "continue", "end"]
if items:
    a0 = BASE + int(items[0][1], 16)
    o += ['printf "CHECK first function bytes at 0x%x:\\n"' % a0, "x/4wx 0x%x" % a0]
o += ["continue"] + ['printf "TOTAL %s hits %%d\\n", $n%d' % (items[i][0], i) for i in range(len(items))] + ['printf "TRACE_END\\n"', "quit"]
print("\n".join(o))
