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

What remains joined in yyparse (MEASURED in lpN7-lpN10, replacing the earlier argued text):

* Address-taken base slots (cannot be split, `find_webs.py` refuses: `local_850 local_840 local_830 local_820 local_800 local_7f0 local_7e0 local_7b0`, eight, not nine):
  e.g. `local_850: address taken in "...(&local_850,*(int **)(pTVar56 + -0x7c))"`.
* Interior words (21 of them: the other `typeTmp*` names). `Tools/userspace/lpnames/splitarea.py` split every web of at most 3 lines off the big web of each
  interior word (test names `local_84c_wK`; the large web keeps the joined name through a final `*` row). Gates against 1b2f819:
  area A (`local_84c 848 844 83c 838 82c`) lpN7 SPLIT-EQUIVALENT, 0 problems (54 renames); area B (`local_81c 818 814 810 80c 808 7fc`) lpN8 SPLIT-EQUIVALENT (20 renames);
  area C (`local_7ec 7e8 7dc 7d8 7d4 7d0 7cc`) lpN9 SPLIT-EQUIVALENT (23 renames); area D (`local_7bc 7ac`) and the yyval words (`local_870 local_86c`) have no web of
  at most 3 lines with a definition besides the large one, so nothing to split (lpN10 had no row changes; it does not count as a test).
  So the earlier claim "a per-case split leaves reads with no visible definition" is FALSE for the small webs: the compiler's frame-slot mapping tolerates them. They are
  mechanically splittable (about 100 webs, mostly single `local_838 = 0` / `= pTVar3` stores). They are NOT renamed in the final tree because a role name per web needs the case's
  evidence (TType temp field vs TPublicType field vs std::string field) and I did not derive it per web; the test names would be worse than the joined names.
* The big web of every interior word (e.g. `local_84c` web 0: 136 lines, 34 definitions; `local_838` 32 webs of which 30 are 1-2 lines) is ONE def-use web
  (`find_webs.py`): its uses after the switch (the common `*yyvsp = yyval` copy-down) are reached by definitions from many cases, so no case-by-case naming of that web exists
  at the dataflow level: a use reached by two definitions needs one name. This is the measured basis for keeping a single name there; the joined name is the union of the two views of
  the word (the stack `TType` temporary and the `TPublicType` copy that the value-stack copy-down reads).
* NOT reproduced: wt-lp1's `UNINIT yyparse 61 -> 63` on the string-pair slots. Its split used `local_850`/`local_840`, which are address-taken (the tool refuses those), and its
  rows were not kept. Splitting the small webs of `local_84c`/`local_83c` (the interior half of that pair) did NOT raise any UNINIT (lpN7 problems: 0). The claim is therefore unverified and removed from the argument.
* Open work: give the ~100 splittable small webs role names from per-case evidence, then re-gate; the rows are on branch `lp14-test-splits` (commits after 1b2f819).

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
