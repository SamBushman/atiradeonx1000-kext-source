# Differential emulation: stock vs rebuilt GLDriver (#81)

Runs a function of the stock bundle and the same function of a rebuilt bundle in a PPC emulator (unicorn) on the SAME fake context and compares what they do.
The rebuilt bundle must come from the real link stage (`relink.sh NAME` = `link_corpus.py` -> G5 `build.sh` -> local `rebuilt_NAME.{bin,nm}`); a build from the raw
`part_*.c` + raw `decls.h` is NOT representative (that mistake produced #82/#83, since retracted: the link stage types data externs, mirrors frames, symbolises literals).

* `first.py FN NARGS SEEDS [SHOW]`  - the first diverging dispatch call per seed (dispatch table hooked: `*(ctx+0x3d4)+0x12e4..0x132c` are logging stubs; r3..r10 + the stack words
  the slot's callee takes are compared). `NOSTK=1` ignores the contents of stack arrays.
* `cat1.py FN SEEDS`                - one line of JSON: runs reached / identical / divergence categories (used over the 78 functions that call through the table:
  440 of 441 runs identical on the r6 build).
* `sites.py FN SEEDS`               - per hand-written stack-word site: aligned-equal / call-equal / CALL-DIFFERS / rebuilt-missing.
* `eff.py FN NARGS SEEDS`           - generic: return value, ctx/A/heap/stack-buffer writes and dispatch calls of any function. A sweep over all 3,900 functions is noisy (16 runs each,
  6 register args): pointer arguments that are not pointers, functions that read their caller's stack, dyld-bound pointer cells and vtable pointer stores make a difference
  that is not a defect. Treat its list as candidates only.

Setup (nothing is installed system-wide): `pip install --break-system-packages --target /tmp/upkgs unicorn`; stock.bin = the G5's
`/System/Library/Extensions/ATIRadeonX1000GLDriver.bundle/Contents/MacOS/ATIRadeonX1000GLDriver` (fat, the ppc slice is used); `RBIN` / `RNM` point at the rebuilt image and its `nm -n`.
Emulator details that matter: zero-fill sections are zeroed; non-lazy pointers to symbols defined in the image are filled from the indirect symbol table (imports get a name-keyed sentinel);
dyld stubs and calls to address 0 return 0; a data read from the image's own code marks the run as meaningless (`bad_read`); the fake context has a valid caps block
(`A+4 -> +0x10 -> bytes at +0x2d48`), without which loops that read `((unsigned char *)0x2d48)[p + 4]` run on garbage.

## Hardware differential (G5, gdb): `hwdiff.py`, `hwdiff2.py`, `hwseq.py`
`hwseq.py LIST STOPFUN` prints the ORDER in which the listed functions are entered until the first entry of STOPFUN, stock (`break *0x1008000+addr`; the driver loads at 0x1008000)
vs rebuilt (`break *FUN_x` - the EXACT entry: `break FUN_x` skips the prologue and misses small leaf functions), and the first divergence. `hwdiff2.py` compares hit counts
(`ignore N 1000000` counts without stopping). Traps: gdb-696 needs its script piped (`cat script | gdb`), not redirected; a missing symbol aborts numbering of later `commands`;
`pkill` does not exist on Tiger; software `watch` on the whole run takes hours.
