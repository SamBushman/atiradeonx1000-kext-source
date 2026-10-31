# r06 data-label naming: GA

names_r06_data.tsv: 22 `data` rows (11 DAT_ + 11 PTR_). Every DAT_/PTR_ label of the corpus is named; none left.
- DAT_0000e018 surface-format table; the offscreen/texture staging-buffer globals of _createOffscreenBuffer/_createTextureBuffer (pixel format, aligned width/height, row bytes, surface record).
- Pointer slots: __la_symbol_ptr slots `lazyPtrTo_<import>_<addr>` (CONFIRMED: the symbol map states the import), __nl_symbol_ptr slots `ptrTo_<target>_<addr>`; PTR_0000e690 (value 0, second argument of _atexit_common) `atexitDsoHandle_0000e690` (INFERRED).
- INFERRED, weakest: the two *SurfaceInfo records (0xe6e4, 0xe748): role taken from how the code uses them (first word -> kernel scalar, +0xc part -> dstDesc of _radeon3DCopySetup); the field layout of the record is not decoded.
Checks: Tools/userspace/datacheck.sh DATA-IDENTICAL (16 link files, 42 symbols); compile gate (G5, Tiger) SPLIT-EQUIVALENT, 2 objects different, 131 functions compared, 0 problems.
