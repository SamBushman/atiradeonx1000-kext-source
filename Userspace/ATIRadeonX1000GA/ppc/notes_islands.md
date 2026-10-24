# GA branch islands (names_lpP_1.tsv)

26 PIC branch islands (32 bytes each, `mflr/bcl/mflr/addis/mtlr/addi/mtctr/bctr`) are named `<target>_island_<addr>`; test_coverage.tsv lists them as
"not a C function of the rebuilt image".

Known body inaccuracy: the corpus body of `_check_cxa_atexit_island_c24` (0xc24) is a full copy of `_check_cxa_atexit` (0x6f0), not the one-line
tail call the other islands show. Replacing it by `_check_cxa_atexit(cxaAtexitFn,cxaFinalizeFn); return;` was tried (gate islc24, 2026-10-24): the function
becomes ~100 bytes shorter, every later function's branch offsets shift, and verify_names reports NOT-EQUIVALENT (26 problems, LENGTH FUN_00000c24 plus
CODE branch-offset changes across part_000). The corpus is gated for layout, so the body is left as decompiled; the name and this note carry the truth.
