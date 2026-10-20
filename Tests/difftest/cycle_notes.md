# Estimated-cycle ratios (rebuilt / stock) - what was fixed, what remains

`difftest` reports `est. cycles stock N rebuilt M (xR)`: a coarse PowerPC 970 weighting of the instructions each side executed on the same inputs
(see `insn_cost` in `Tools/difftest/difftest.py`). It is a model, not a measurement. Two tools find where a ratio comes from:

* `Tools/difftest/profile_case.py CASEFILE FILTER [SEEDS]` - executed instructions by class (loads, stores, multiplies, divides, branches, nops), stock against rebuilt;
* `Tools/difftest/trace_case.py CASEFILE FILTER SEED [PREFIX]` - the executed instruction streams and a register-blind diff of them (a multiset diff for long runs).

## Causes found (GL side, Oct 2026)

1. **`FormatTableLookup_*` were calls.** Stock indexes `ati_format_info_table[format].field` in place; the rebuilt code called an out-of-line function that divided the
   byte offset by the entry size (0x1c) for every field read. The accessors are header inlines now (`Headers/ATIRadeonX1000Registers.h`) that add the byte offset.
   `build_scissor` 2.41 -> 0.98, `write_r500_3d_blit_state_packet` 1.70 -> 1.02, the format-table loops of `process_command_buffer` opcodes 0x2d/0x31/0x33/0x3f 1.3-1.45 -> 1.03-1.10.
2. **Every `M<T>` read was volatile.** Ordinary memory (objects, command buffers) was compiled by the shipped compiler as plain loads and stores it could combine; the volatile
   accessors made the rebuilt code reload each field it used twice (and forbade combining stores). Sources that do not program hardware are now built with
   `-DGH_PLAIN_MEMORY` (`M` -> `MN`, non-volatile; `Headers/GhidraCompat.h`, `Tools/build_kext.sh`); the files that reference the MMIO base, the byte-reversed register
   intrinsics or the I/O barriers, and every `ATIRadeonX1000_*` file, keep volatile (`Tools/volatile_memory_sources.txt`). `Tools/check_plain_memory_loops.py` lists
   the loops of the plain files that have no call in the body and read memory in the condition - the only place a non-volatile read could turn a wait into a hang; all 21 are
   walks over the function's own lists or counted loops (reviewed Oct 20). 281 of 842 cases got faster by 0.02 or more with this, 4 slower by 0.02-0.08.
3. **Repeated reads and divides in a few functions** (`write_r500_zdecompress_restore_add_on_packet`, `write_r500_3d_blit_state_packet`, `build_surface_from_texture`,
   `process_kATIGLStreamFastClearColor`, `build_scissor`): the tiling word / bytes-per-pixel / format entry are loaded once into locals, the shift counts lose their `& 0x3f`
   (the PowerPC shift instructions use the low six bits themselves), the divides are signed like stock's `divw`, and the five read-modify-write stores of the packet's format
   word are written as a running value (stock: `rlwimi`).

## Remaining above 1.10 in the GL files (toolchain-level)

`ATIR500GLContext::process_command_buffer` opcodes: 1.10-1.17. The function is 3,400 lines; its register allocation differs from stock's:

* the prologue saves f15-f31 (17 floating-point registers) where stock saves f21-f31 (11): about 24 estimated cycles per call, 5-8 % of a short opcode path;
* `nop` padding appears about twice as often (gcc's G5 dispatch-group scheduling placed differently);
* the rest is spill placement. The variable splits of the naming work (`Locals5_*`) change how many values are live at once, so the allocator asks for more registers.

Matching stock exactly would mean un-splitting float temporaries (undoing names) for a change that is small against the cost of any single opcode (hundreds to 100k+ estimated
cycles). Not changed; the long opcodes (0x2d, 0x31, 0x32, 0x33, 0x3f) are at 1.03-1.10.
