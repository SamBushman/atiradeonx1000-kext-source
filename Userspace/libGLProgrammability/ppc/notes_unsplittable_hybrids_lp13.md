# libGLProgrammability: names that stay joined or overlaid (lp13, parts 004/005/007/008/009/011)

Evidence is measured: `find_webs.py` output on the base tree (`53da6b7`, renames of the variable taken back) and gate messages from `~/g5logs/lpM*.log`
(`gate.sh`, split_equiv + `-Wuninitialized`). "web count" = first line of `find_webs.py DIR FN VAR`.

## A. Gate rejected the split (measured)

| function / variable | name now | measured evidence |
|---|---|---|
| `ParseSymbolTable__FindNextParamSymbolByName` `iVar2` | `matchResult` | split into symbol cursor + strncmp result: gate **lpM1** `part_011: DATAFLOW _ParseSymbolTable__FindNextParamSymbolByName 1 loads reached by different stores; first at 107 lwz r0,64(r30) \| lwz r0,64(r30)`, `162 functions compared, 1 problems` |
| `TPoolAllocator__allocate` `iVar6` | `allocationResult` | split into entry offset + returned address: gate **lpM3** `part_005: DATAFLOW _TPoolAllocator__allocate 1 loads reached by different stores; first at 225 lwz r0,64(r30) \| lwz r0,96(r30)` and `UNINIT TPoolAllocator__allocate 0 -> 1`; find_webs: `iVar6: 1 webs` |
| `TIntermBinary__promote` stale r10 argument at the `case 0x1d..0x24` entry | `sizeInBytes` (not `leftIsMatrixQuery`/`operatorCode`) | gate **lpM5** `part_004: DATAFLOW _TIntermBinary__promote 1 loads reached by different stores; first at 1236 lwz r9,164(r30) \| lwz r9,232(r30)`, `UNINIT TIntermBinary__promote 15 -> 16`; `-Wuninitialized` named `'leftIsMatrixQuery'`, and with `operatorCode` `'operatorCode'`, as used uninitialized; the switch value is `nominalSize*4` (= `sizeInBytes`, like the other stale uses at the same case labels) |
| `TParseContext__executeInitializer` first split attempt | (fixed, not joined) | gate **lpM2** `part_005: DATAFLOW _TParseContext__executeInitializer 1 loads reached by different stores; first at 2149 lwz r2,292(r30)` + `UNINIT 10 -> 11`: the rhs of `x = *(x + 0x30)` had been left on the old name; fixed, gate lpM3 clean for this function |

## B. find_webs reports exactly one web (all defs reach the same uses)

| function / variable | name | find_webs (base `53da6b7`) |
|---|---|---|
| `TParseContext__parseMatrixFields` `uVar4` | `fieldTextLengthReg` | `uVar4: 1 webs` |
| `TParseContext__integerErrorCheck` `iVar1` | `basicTypeThenSize` | `iVar1: 1 webs`; also a one-line `if (x == 2 && (x = f(), x == 1))` |
| `TGenericLinker__AllocateTextureUnitsForVaryings` `uVar9` | `typeOrVec4Count` | find_webs refuses the function: `do without while`; the joined use is `while (x = GetVec4sForType(x), vec4Index < x)` |
| `TIntermAggregate__compileNode` `a2` | `lastCallArg3Ptr` | `a2: 1 webs  (some use reached from ENTRY)` |
| `TParseContext__constructorErrorCheck` `local_8c` | `savedR10` | `local_8c: 1 webs  (some use reached from ENTRY)` |
| `TParseContext__constructorErrorCheck` `iVar10` | `paramSizeResult` (r4 carrier); the other 3 webs are `paramTypeVtable` / `paramIsArray` / `argBasicType` | `iVar10: 4 webs`; web 0 spans lines 76-357 (`iVar10 = param_2`, every `extraout_r4_N` reload) |
| `Binding__SetNameFromArrayName` `iVar2` | `nameLengthCountdown` (+ `nameLen`, `clearIdx` split off) | `iVar2: 3 webs`: w0 `strlen` result, w1 lines 22-56 (length def .. checksum loop), w2 lines 37-42 (clear loop index); gate **lpM11** SPLIT-EQUIVALENT with the three names |
| `TGenericLinker__FixOutputReads` `local_9c` | `opChunkScratchWord` | find_webs refuses: `do without while`; halfword reads through `&` (3 address-of lines in the corpus text) |

## C. Address-taken or overlapping frame storage (apply_names rule: address-taken locals cannot be split)

Measured by `grep` over the part files: declaration kind and number of lines that take the address of / cast the variable.

| name | declaration | address-of/cast lines | find_webs (base) |
|---|---|---|---|
| `typeTemp1Overlay` (OutputConstantUnion) | `undefined **x [4]` | 2 | `local_1c0: 1 webs` |
| `typeTempOverlay` (promote, promoteConstantUnion, addConstVectorNode, indirectNode) | `undefined **x [4]` | 7 | `local_70: 1 webs`, `local_c0: 1 webs`, `local_90: 1 webs`, `local_60: 1 webs` (each `some use reached from ENTRY`) |
| `operandDescOverlay` (TIntermBinary::compileNode) | `uint` first word of an 8-byte out-parameter | 19 | `local_80: 1 webs` |
| `allocatorOverlay` / `mapIterOverlay` / `mapEndOverlay` (extensionErrorCheck) | `int x [4]` / `int` / `int` | 2 / 3 / 3 | `local_1c0: 1 webs`, `local_1b0: 2 webs`, `local_1a0: address taken in "(&local_1a0,pTVar8,local_180,&local_70);"` |
| `binaryTypeWord4Overlay` (`local_190`) / `compareTypeWord4Overlay` (`local_160`) / `tailTypeWord4Overlay` (`local_100`) (fold) | stack TType words | 23 / 24 / 10 | find_webs refuses all three: `address taken in "__ZNSs4_Rep10_M_destroyERKSaIcE(...,&local_190);"` (same text with `&local_160`, `&local_100`) |
| `unaryTypeWord4Overlay` (`local_1c0`, fold) | stack TType word | 3 | `2 webs`: web 0 = declaration, the `puVar11[6] = local_1c0` read and the `(char *)&local_1c0` sprintf buffer; web 1 = the lone store `local_1c0 = 0` (no scalar use; the callee reads it back through `&unaryTypeVtbl`). Not split, not gated: the only separable web is a store whose reader is memory |
| `rightTypeOverlay` (`local_140`, fold) | `undefined **x [4]` | 5 | `local_140: 1 webs` |
| `stackTypeTypeNameOverlay` (`local_120`, arrayErrorCheck) | `undefined **` = stackType +0x10 typeName AND the vptr word of stackTypeB (base `&local_120`) | `&local_120` passed to `TType__setStructSize` / `TType__getCompleteString` | 6 webs; splitting it (lpM12) -> gate `part_005: ADDRESS-TAKEN split _TParseContext__arrayErrorCheck 488`, `151 functions compared, 1 problems`; kept as one name |

The other five words of the two overlapping stack TType temporaries (stackType base `local_130`, stackTypeB base `local_120`) were split by region
(A = file lines 487-742, B = 743-800; every B word is re-initialised at lines 748-757 before its first read): `local_11c` -> `stackTypeWord14` /
`stackTypeBArraySize`, `local_118` -> `stackTypeStructureSize` / `stackTypeBStructure`, `local_114` -> `stackTypeWord1c` / `stackTypeBFieldName`,
`local_110` -> `stackTypeWord20` / `stackTypeBTypeName`, `local_10c` -> `stackTypeBits` / `stackTypeBWord14`. Gate **lpM14** SPLIT-EQUIVALENT,
`part_005: 151 functions compared, 0 problems` (find_webs base counts: `local_10c` 4 webs, `local_118` 7, `local_11c` 4, `local_114` 4, `local_110` 5).
The first all-six attempt **lpM12** failed with the ADDRESS-TAKEN message above; **lpM13** failed to compile (duplicate declaration, `FAIL cand part_005.c`).

## D. Verified splits that replaced earlier joined names

`promote` `iVar7` (30 webs, gate lpM6), `executeInitializer` / `arraySetMaxSize` / `ParseSymbol` level lookups (lpM3..lpM6), `extensionErrorCheck` `iVar10`
(lpM2/lpM3), `TIntermUnary::compileNode` `uVar8` (5 webs: w1 operator code incl. the stale r10 argument, w2..w4 PP stream type; gate **lpM11**),
`fold` all 15 whole-function locals (lpM8 for 5, lpM9 for 6, lpM10 for 4; rules in `Tools/userspace/lpnames/classwebs.py` usage).
