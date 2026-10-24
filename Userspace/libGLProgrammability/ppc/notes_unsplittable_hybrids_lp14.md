# Joined ("...Or...", "...Then...") names that could not be split (lp14: part_000-003, part_006, part_012)

Every other joined name in these parts was split into per-role names (rows in `names_lpN_1.tsv`, gates lpN3 and later). The names below stay joined
because the *value* really is the union/overlay the name says, not because a split was skipped. Evidence per case; the gate (`Tools/userspace/lpnames/gate.sh`)
and `find_webs.py` are the arbiters.

## part_000 `_PPParserParseStatement`: `partLengthThenLabelStatus` (iVar1)
`iVar1` holds `_PPParserGetPart`'s token length, which is then passed to `_PPParserParseLabel`, whose result is assigned back to the same variable
in ONE comma expression: `(iVar1 = _PPParserParseLabel(parser,partBuf,iVar1), iVar1 != 3)`. The statement reads the length (rhs), defines the status (lhs) and
tests the status (rhs, after the comma) on one line. `lhs`/`rhs` side splitting of `apply_names.py` cannot separate the two rhs roles, and naming the whole
line either way leaves an uninitialised read (UNINIT) or a wrong-role read; find_webs reports it as a single web.

## part_002 `_CPPif` `cppStateOrIfLoc` (puVar7), `_CPPifdef` `elseTrackerOrUndefFlag` (uVar7), `_CPPerror` `tokenOrAtom` (iVar3)
Each is ONE def-use web (`find_webs.py` prints `1 webs`): the two definitions (cpp state word / if-location pointer; incremented else-tracker /
symbol undef flag; token / its atom) both reach the same use (a dead vararg forwarded to `_CPPelse`/`_CPPErrorToInfoLog`, or `_GetStringOfAtom`).
Two names for one web is a MERGE in the gate.

## part_003 `_yylex_CPP` `maxLengthOrResult` (param_2), `_DumpTokenStream` `tokenOrFormatArg` (iVar1)
`param_2` is a parameter (the buffer size on entry, reused as the returned length): only locals can be split. `tokenOrFormatArg`: the `sprintf` argument is either the
token character (`"%c"` path) or the atom string (`"%s "` paths): both definitions reach the same `_sprintf` use, one web.

## part_012
* `TPPStreamCompiler::constructElement` `argByteOffsetOrCopyResult` (iVar17): one web (`lw2.py`: w2 lines 143-290); `argCountThenLeftover` is `param_4` (a parameter).
* `TPPStreamCompiler::copyPropagateCompilerTemp` `scratchPtrOrWord` (puVar20), `streamOrLeftover` (uVar19): one def-use web each (see the rows' evidence).
* `constructFromOperand` `a6` is renamed `scratchR9` (one web, forwarded dead vararg). `TSymbolTableLevel::clone` `headerOrNewRefCount` (a6): a split at the refcount definition fails the gate (DATAFLOW "1 loads reached by different stores", lpN4) - the stale 7th-argument use is reached by both definitions.

## part_006 `yyparse`
yyparse keeps the yacc value stack in a union (`YYSTYPE`): a stack slot is a TPublicType (type, qualifier, ...) in one rule and a TParameter / TFunction in
another, and the compiler reuses ONE frame area for C++ temporaries of different types (a `TType`, a `TPublicType` and `std::string` objects built in the same
stack offsets in different grammar actions). The names below name that union/overlay exactly. Splitting them per rule needs per-case rows over a function
the decompiler turns into one giant switch; the evidence from `find_webs.py` is that the words are initialised through pointers (`&local_850`, `&local_840`...), so
each web is "reached from ENTRY" and a split yields new `-Wuninitialized` hits (`UNINIT yyparse 61 -> 63`, found by wt-lp1).

| name | Ghidra var | find_webs |
|---|---|---|
| `typeTmp1ArraySizeOrStr1Data` | `local_84c` | 7 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `typeTmp1BitsOrPubQualifier` | `local_82c` | 5 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `typeTmp1StructureOrPubSize` | `local_848` | 1 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `typeTmp1TypeNameOrStr2Alloc` | `local_840` | address-taken (TType__getCompleteString(&local_840,*(uint *)(pTVar56 + -0x5) |
| `typeTmp1VtableOrStr1Alloc` | `local_850` | address-taken ((**(code **)(**(int **)(pTVar56 + -0x7c) + 0x38))(&local_850) |
| `typeTmp1Word0cOrPubMatrix` | `local_844` | 1 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `typeTmp1Word14OrStr2Data` | `local_83c` | 6 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `typeTmp1Word18OrPubLine` | `local_838` | 32 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `typeTmp1Word20OrPubType` | `local_830` | address-taken ((**(code **)(**(int **)(pTVar56 + -0x50) + 0x38))(&local_830) |
| `typeTmp2ArraySizeOrPubUserDef` | `local_81c` | 4 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `typeTmp2BitsOrPub3Qualifier` | `local_7fc` | 2 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `typeTmp2StructureOrPubLine` | `local_818` | 1 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `typeTmp2TypeNameOrPubArray2` | `local_810` | 1 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `typeTmp2VtableOrPubArray` | `local_820` | address-taken ((**(code **)(**(int **)(pTVar56 + -0x7c) + 0x38))(&local_820) |
| `typeTmp2Word0cOrPubMatrix2` | `local_814` | 6 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `typeTmp2Word14OrPubUserDef2` | `local_80c` | 1 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `typeTmp2Word18OrPubLine2` | `local_808` | 10 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `typeTmp2Word20OrPub3Type` | `local_800` | address-taken (__ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&loca) |
| `typeTmp3ArraySizeOrPub3UserDef` | `local_7ec` | 9 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `typeTmp3BitsOrTypeTmp4Word14` | `local_7cc` | 1 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `typeTmp3MaxArraySizeOrTypeTmp4Word0c` | `local_7d4` | 4 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `typeTmp3StructureOrPub3Line` | `local_7e8` | 2 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `typeTmp3TypeNameOrTypeTmp4Vtable` | `local_7e0` | address-taken ((**(code **)(**(int **)(pTVar56 + -0x7c) + 0x38))(&local_7e0) |
| `typeTmp3VtableOrPub3Array` | `local_7f0` | address-taken (((unsigned char *)(local_7fc + -0xc),&local_7f0);) |
| `typeTmp3Word14OrTypeTmp4ArraySize` | `local_7dc` | 1 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `typeTmp3Word18OrTypeTmp4Structure` | `local_7d8` | 6 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `typeTmp3Word20OrTypeTmp4TypeName` | `local_7d0` | 4 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `typeTmp4BitsOrStr3Data` | `local_7bc` | 1 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `typeTmp5ArraySizeOrStr4Data` | `local_7ac` | 1 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `typeTmp5VtableOrStr4Alloc` | `local_7b0` | address-taken ((**(code **)(**(int **)(pTVar56 + -0x7c) + 0x38))(&local_7b0) |
| `functionCallHeaderTypeOrFunction` | `uVar57` | 71 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `functionCallHeaderWithParametersTypeOrFunction` | `uVar57` | 71 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `functionHeaderWithParametersTypeOrFunction` | `uVar57` | 71 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `functionPrototypeTypeOrFunction` | `uVar57` | 71 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `parameterDeclarationQualifierOrParamType` | `uVar28` | 44 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `parameterDeclarationQualifierOrParamType2` | `pTVar12` | 10 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `structDeclarationListTypeOrFunction` | `pTVar52` | 3 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `typeQualifierQualifierOrParamType` | `uVar57` | 71 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `typeSpecifierQualifierOrParamType` | `pTVar32` | 6 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `typeSpecifierQualifierOrParamType2` | `local_84c` | 7 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `typeSpecifierTypeOrFunction` | `pTVar3` | 101 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `yystateOrYylen` | `iVar48` | 4 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `yyvalQualifierOrParamType` | `local_86c` | 2 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
| `yyvalTypeOrFunction` | `local_870` | 2 webs, uses reached from function ENTRY (initialised through a pointer by a callee/ctor) |
