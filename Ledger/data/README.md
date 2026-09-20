Non-code sections of the shipped kext (PPC slice), transcribed by `Tools/userspace/data_sections.py` (`sections.tsv`, `cstrings.c`, `TEXT___const.c`,
`DATA___data.c`, literals, constructor/destructor tables; relocation targets are annotated per word). `Tools/audit_kext_data.py STOCK OURS` compares the
data symbols of the shipped kext with our build: after this pass every stock data symbol is defined in our build under the stock's own symbol name
(the `methodDescs` function-local statics, `_Mode*Table`, `_FilterSetupArrayOfSets`, `_ati_format_info_table` (writable, `__data`, as stock),
`_samplesTable`, the `load_3d_blit` statics, `_ATIRadeonX1000_VERS_NUM/_STRING`), and no stock data content is missing.
Audit result (`python3 Tools/audit_kext_data.py STOCK OURS`, 2026-09-19, issue #62): stock-only data symbols 0; same-named symbols compared byte-for-byte
(relocated words wildcarded) 79, differing 1 (`_kmod_info`: the dry-run build's bundle id/version strings, expected); section (`__const`/`__data`/`__bss`/`__common`)
differences 0. What changed in #62: `shape_surface`'s `C.146` and the four other small tables at the end of the stock `__const` (`_samplesTable`, the three
`load_3d_blit` statics) are one contiguous asm block in stock order with stock symbol names and exact 28/56-byte sizes (`Sources/ATIR500Surface_ConstRun.cpp`; the
stock indexes them with 4-bit indices past their ends, so contiguity keeps the over-reads identical - the nine words beyond the last table are kept as the
ours-only `_load3dSamplesTablePastEnd`); the three DMA-blit statics are writable `__data` like stock; `_FilterSetupArrayOfSets` is the real 2432 bytes (76 sets) - the
earlier 4104-byte copy had the neighbouring vtable words baked in; the packets, microcode and `CO` are `__data`, the seven `methodDescs` tables `__TEXT,__const`,
`_gl_assert_wait_timeout_event` `__bss` and `_global_dummy_read_back_a_register` `__common`, all as in stock.
Remaining "size differs" lines are layout artifacts of the audit's size measure (distance to the next symbol), not content differences:
`_ATIRadeonX1000_VERS_NUM/_VERS_STRING` (stock: first two strings of `__cstring`, 6 bytes of padding after `4.1.9`; ours are placed by link order and the linker
merges the other objects' strings around them - content is byte-identical), and the 2D-base and Surface `methodDescs` tables (ours are followed by 152 bytes of
gcc-generated pointer-to-member constants from `OSMemberFunctionCast`, which the stock, having plain function addresses in its tables, does not have).
