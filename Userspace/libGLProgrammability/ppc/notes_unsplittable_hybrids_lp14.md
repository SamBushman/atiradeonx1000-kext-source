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
Split in lp14: `iVar48` -> `yystate` / `yytoken` / `yylen` (3 independent webs, gate lpN5 SPLIT-EQUIVALENT).
Renamed (they were per-rule value-stack segments whose symbol has a known `%union` member, so the "Or" was not needed): `functionPrototypeFunction`,
`functionCallHeaderFunction`, `functionCallHeaderWithParametersFunction`, `functionHeaderWithParametersFunction` (`interm.function`, +0x10),
`typeQualifierQualifier`, `typeSpecifierType`, `typeSpecifierQualifier`, `typeSpecifierQualifier2` (`interm.type`, +0x10 type / +0x14 qualifier),
`parameterDeclarationParamType`, `parameterDeclarationParamType2` (`interm.param`, +0x14 type), `structDeclarationListTypeList` (`interm.typeList`, +0x10).

What remains joined in yyparse is the frame-area overlay and the yyval union words:
* `yyvalTypeOrFunction` (`local_870`, yyval+0x10) and `yyvalQualifierOrParamType` (`local_86c`, yyval+0x14) are the words of the `%union` member the default action copies
  from `$1` (`yyval = yyvsp[1-yylen]`) before the case code runs: the same variable carries `type`, `function`, `param`... depending on the rule (notes_ttype_layout.md line 18);
  the main web spans every case (find_webs: 2 webs, the first with 60+ lines).
* The stack areas A..D (`local_850..local_82c`, `local_820..local_7fc`, `local_7f0..local_7cc`, `local_7bc/7b0/7ac`) hold C++ temporaries of different types built at the same frame
  offsets in different grammar actions: a `TType` (getType()/TType(TPublicType) target), a `TPublicType` copy, `std::string` objects (`getCompleteString()` results). The base slots are
  address-taken (`&local_850`, `&local_840`, `&local_830`, `&local_820`, `&local_800`, `&local_7f0`, `&local_7e0`, `&local_7b0`: listed below) and cannot be split; the interior words are
  the fields of those objects (written by constructors through the pointer, read as `local_83c`...), so a per-case split of the words alone would give each new variable a read with no
  visible definition. wt-lp1 tried the per-case split of the string-pair slots (`local_850/84c/840/83c`) and the gate reported `UNINIT yyparse 61 -> 63`.

| name | Ghidra var | find_webs |
|---|---|---|
| `typeTmp1ArraySizeOrStr1Data` | `local_84c` | 7 webs (field of an overlaid object) |
| `typeTmp1BitsOrPubQualifier` | `local_82c` | 5 webs (field of an overlaid object) |
| `typeTmp1StructureOrPubSize` | `local_848` | 1 webs (field of an overlaid object) |
| `typeTmp1TypeNameOrStr2Alloc` | `local_840` | address-taken base slot |
| `typeTmp1VtableOrStr1Alloc` | `local_850` | address-taken base slot |
| `typeTmp1Word0cOrPubMatrix` | `local_844` | 1 webs (field of an overlaid object) |
| `typeTmp1Word14OrStr2Data` | `local_83c` | 6 webs (field of an overlaid object) |
| `typeTmp1Word18OrPubLine` | `local_838` | 32 webs (field of an overlaid object) |
| `typeTmp1Word20OrPubType` | `local_830` | address-taken base slot |
| `typeTmp2ArraySizeOrPubUserDef` | `local_81c` | 4 webs (field of an overlaid object) |
| `typeTmp2BitsOrPub3Qualifier` | `local_7fc` | 2 webs (field of an overlaid object) |
| `typeTmp2StructureOrPubLine` | `local_818` | 1 webs (field of an overlaid object) |
| `typeTmp2TypeNameOrPubArray2` | `local_810` | 1 webs (field of an overlaid object) |
| `typeTmp2VtableOrPubArray` | `local_820` | address-taken base slot |
| `typeTmp2Word0cOrPubMatrix2` | `local_814` | 6 webs (field of an overlaid object) |
| `typeTmp2Word14OrPubUserDef2` | `local_80c` | 1 webs (field of an overlaid object) |
| `typeTmp2Word18OrPubLine2` | `local_808` | 10 webs (field of an overlaid object) |
| `typeTmp2Word20OrPub3Type` | `local_800` | address-taken base slot |
| `typeTmp3ArraySizeOrPub3UserDef` | `local_7ec` | 9 webs (field of an overlaid object) |
| `typeTmp3BitsOrTypeTmp4Word14` | `local_7cc` | 1 webs (field of an overlaid object) |
| `typeTmp3MaxArraySizeOrTypeTmp4Word0c` | `local_7d4` | 4 webs (field of an overlaid object) |
| `typeTmp3StructureOrPub3Line` | `local_7e8` | 2 webs (field of an overlaid object) |
| `typeTmp3TypeNameOrTypeTmp4Vtable` | `local_7e0` | address-taken base slot |
| `typeTmp3VtableOrPub3Array` | `local_7f0` | address-taken base slot |
| `typeTmp3Word14OrTypeTmp4ArraySize` | `local_7dc` | 1 webs (field of an overlaid object) |
| `typeTmp3Word18OrTypeTmp4Structure` | `local_7d8` | 6 webs (field of an overlaid object) |
| `typeTmp3Word20OrTypeTmp4TypeName` | `local_7d0` | 4 webs (field of an overlaid object) |
| `typeTmp4BitsOrStr3Data` | `local_7bc` | 1 webs (field of an overlaid object) |
| `typeTmp5ArraySizeOrStr4Data` | `local_7ac` | 1 webs (field of an overlaid object) |
| `typeTmp5VtableOrStr4Alloc` | `local_7b0` | address-taken base slot |
| `yyvalQualifierOrParamType` | `local_86c` | 2 webs (field of an overlaid object) |
| `yyvalTypeOrFunction` | `local_870` | 2 webs (field of an overlaid object) |
