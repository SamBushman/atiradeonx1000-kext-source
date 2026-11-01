# r24 part B: anonymous `LD_` labels in GLDriver

Rows: `names_r24_targets.tsv` (1,325 `target` rows). Link output of the pre-r24 tree had 1,372 distinct `LD_<addr>` labels in data.s; 1,325 had no other name.

| Class | Count | Name | Tier |
|---|---|---|---|
| C strings (`__TEXT,__cstring`) with no Ghidra data name | 471 | `s_<first 32 chars, non-alnum -> _>_<addr>` (the corpus's existing s_ convention) | CONFIRMED (content) |
| RTTI name strings (`__const_coal` 0x1cc164..) | 356 | `<Class>__typeinfo_name_<addr>`, Class decoded from the Itanium name (`16MachineAssembler`) | CONFIRMED |
| RTTI records (`class_type_info`/`si_class_type_info`, 0x1f0f08..) | 356 | `<Class>__typeinfo_<addr>`, Class from the record's name pointer | CONFIRMED |
| hw/opcode-template token-stream arrays (0x1ab1e8..0x1af8xx) | 136 | `ilOpcodeTemplateStream_<addr>` | INFERRED (reached only from the vs/KhanPs/FudoPs hardware tables and opcode-template pointer tables; token semantics NOT decoded) |
| per-program-mode small arrays (0x1dbddc..0x1dbe98) | 6 | `ffvp{FixedSourceSelect,DestFile,SourceFile}Array_<addr>` | INFERRED (from the owning ByProgramMode pointer table) |

Gates: `datacheck.sh` DATA-IDENTICAL (92 link files, 1677 symbols); `apply_names --check` 0 errors. No C changed, so no compile gate needed.

## Left
- 47 `LD_` labels remain in data.s only as *aliases* beside an object that already has a name (e.g. `LD_1a4134` next to `s__001a4134`); `LD_1fa5e8` is an `.set` alias of `zeroWords4_001fa5e8`. Not unnamed objects; making pointer words use the real name would be a link_corpus change that breaks datacheck's identity by design.
- Decode the `ilOpcodeTemplateStream_*` token language (0x13 begin .. 0x2a end; 0x37, 0x55/0x56, 0x20+swizzle words, 0x07, 0x0c...) and rename by instruction pattern.
