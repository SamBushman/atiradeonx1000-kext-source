# r04 data-label naming: what is done and what is left (GLDriver)

Done (names_r04_opcodeinfo.tsv, names_r04_swizzle_tables.tsv): 1,572 `data` rows - the 253 opcode-info function-local statics of Compiler__initStaticLocals
(guard, object, opcode/word0c/word10 fields, slot of opcodeInfoTable; name = the class in the existing *_atexit_dtor_opN names), 47 read-only select-word
constants named by their swizzle value, and 6 tables whose role the using function states.

Left: 346 distinct DAT_<addr> and 633 PTR_* names in part_*.c. Families seen while triaging, not named because their role is not stated by the code:
- columns of larger tables (texture format table at 0x1d9f34 stride 0x24, vertex-stream tables 0x1d91f0-0x1d9eb0, fragment opcode table 0x1dac34-0x1db344,
  gldInitStateDefaults defaults 0x1db2d4-0x1db938, ffvp register descriptors 0x1dbcd4-0x1dbdc0): each column is its own symbol; naming needs the table's record layout.
- select/mask words whose use is both (mask and select) or only by address (swizzle ?M / Saddr classes), and small integer tables (alpha index remap 0x1aa554-0x1aa570 etc.).
- bss globals of the context/command path and the 5-symbol __common group (0x1fc1f0-0x1fc2b0 region) - need a per-global reading.
- PTR_* nl-symbol-pointer slots (they name the object they point to; rename together with that object).
Not renamed, by design: anchors of the PIC/macro mirror frames' RHS are renamed with their objects automatically (decls.h #define lines follow).

Checks: Tools/userspace/datacheck.sh (link before/after, names mapped back: DATA-IDENTICAL, 1,677 symbols, 92 link files). Compile gate (G5) NOT run: ssh G5 refused
(host key changed - the G5 may be booted into the other OS); run `BIN=ATIRadeonX1000GLDriver sh Tools/userspace/lpnames/gate.sh r04 8cc784a9` once it is reachable.
