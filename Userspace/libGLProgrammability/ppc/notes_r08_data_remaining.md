# r08: libGLProgrammability DAT_ and label leftovers (fork H)

Before: 326 `DAT_` rows in link/symbol_map.tsv (316 referenced from the C parts), 21 labels left by r05. After: 20 `DAT_` rows (9 referenced from C), 2 labels.

## Named (new tables, no other files edited by hand)
* `names_r08_data.tsv` - 282 rows: 44 function-pointer slots (`ptrTo_<function>_<addr>`, CONFIRMED: the symbol map shows the target), 17 vtable-pointer slots (`<Class>VtablePtr_<addr>`, class taken from the constructors/destructors that store `slot + 8` into `this`), 6 empty-std::string-rep slots (`emptyStringRepPtr_<addr>`), 96 string-literal pointer slots, 11 `TBuiltInResource` fields of `GetResources__Resources`, 109 `_dwarf_reg_size_table` entries (`dwarfRegSizeTableEntry<N>_<addr>`), and the empty-rep refcount word.
* `names_r08_consts.tsv` - 23 `__TEXT,__const` initializer words/blocks (`laneUsedInit<N>`, `mergedLaneSelInit<N>`, the opcode/source-count table initializers of _DetectConstantLoopsSimple/_UnrollConstantLoopsSimple, three index initializers).
* `names_r08_misc.tsv` - 2 rows (one more empty-rep slot, the binop table end of _eval).
* `names_r08_labels.tsv` - the 21 labels r05 skipped (indirect calls, a switch, a loop test).

## Naming of the 96 string slots (mechanical)
`<first up to 5 words of the literal, camelCase>Str|FmtPtr_<addr>` (Fmt when the text has a `%` directive); texts without words use the directives (`%s` -> String, `%d` -> Int, `\n` -> Newline ...); the 8 `ERROR:`/`WARNING:` format strings of TPPStreamCompiler::error/warning are named by the roles the code gives them (`formatWithLocation`/`formatPlain`). The literal is the evidence; the name does not say what the message is for.

## Weakest names (INFERRED)
* `builtInResource<Field>_a7b7e8xx`: only `maxDrawBuffers` (+0x2c, read by IdentifyBuiltIns as the gl_FragData size) is tied to the code; the other ten follow the standard 3Dlabs TBuiltInResource order and the values (clip planes 6, attribs 16, uniform components 512, ...) fit it.
* `<Class>VtablePtr`: class from the ctor/dtor that stores the slot; not cross-checked against the vtable symbol itself.
* `*Init<N>_<addr>` constants: roles are the local arrays the compiler copies them into.

## Left unnamed
* `DAT_97c356fc/35718/35750`: `typeSpecifierInit = &DAT_...` default-object addresses in yyparse; layout unknown.
* `DAT_97c35734..3574c` (7), `DAT_97c3aa2c/34/38/3c`: no references in the C (rodata neighbours of the ones above).
* `DAT_97c35e08`, `DAT_97c36138`: offsets into bison tables used as `*(short *)(&DAT + idx)` (yytable/yypgoto neighbours); `DAT_97c37983`, `DAT_97c37d83`: flex `yy_ec`/`yy_meta` byte reads at table + 3; `DAT_97c35f58`: `scratchR9 = &DAT_97c35f58` in promoteConstantUnion. Each would need the whole table layout.
* `DAT_a7b7bf90`: address used both as the std::string empty-rep data area and as the base of `__default_alloc_template<true,0>::_S_free_list`; two roles at one address, not renamed.
* Labels `LAB_97b919a8` (before `} break;`) and `LAB_97c1aba8` (before `goto checkX3f;`): the next statement says nothing.
* `PTR_<symbol>_<addr>` import slots: left as r05 decided (the name already is the symbol).

## Checks
`apply_names.py --check` 0 errors; `datacheck.sh` (base = main with the label rows applied, so only data renames are compared): all 1,069 symbols and 16 link files equal; two label pairs at the same address (DAT_/SYM_) swap row order in symbol_map.tsv because their names sort differently, content identical after `sort`; compile gate on the G5 (Tiger 10.4.11) SPLIT-EQUIVALENT, 23 of 32 objects different, 23 parts compared, 0 problems, no quota/No space/compared 0 lines.
