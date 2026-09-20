Non-code sections of the shipped kext (PPC slice), transcribed by `Tools/userspace/data_sections.py` (`sections.tsv`, `cstrings.c`, `TEXT___const.c`,
`DATA___data.c`, literals, constructor/destructor tables; relocation targets are annotated per word). `Tools/audit_kext_data.py STOCK OURS` compares the
data symbols of the shipped kext with our build: after this pass every stock data symbol is defined in our build under the stock's own symbol name
(the `methodDescs` function-local statics, `_Mode*Table`, `_FilterSetupArrayOfSets`, `_ati_format_info_table` (writable, `__data`, as stock),
`_samplesTable`, the `load_3d_blit` statics, `_ATIRadeonX1000_VERS_NUM/_STRING`), and no stock data content is missing.
Known differences: `shape_surface`'s compiler constant `C.146` and `write_3dtexquad_cmds_for_copy_buffer_using_DMA`'s static (20 bytes writable in stock,
a larger const table in ours) are not reproduced byte-for-byte; the three `load_3d_blit` statics are 16-word arrays that include the words the stock code
reads past the 28-byte tables into their neighbours.
