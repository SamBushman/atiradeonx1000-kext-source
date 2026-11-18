# Round 5 naming, agent N (r5_N.txt, 404 functions): placeholders left unnamed

Every `param_N`/`iVarN`/`uVarN`/`bVarN`/`fVarN`/`auStack_*`/`local_*` that was left in the 404 functions
of r5_N.txt, with the reason. A placeholder stays when no name can be true for every use (several
unrelated roles in one register, a write-only or dead variable, or a role that static reading of the
callers and callees does not establish), or when the gate showed that the rename changes register
allocation. `incomingStack_*`, `extraout_*`, `in_*` and `FUN_*` identifiers are out of scope for this
round and were not touched.

## Variables with too many unrelated roles to name truthfully

| function | variable | uses | why it stays |
|---|---|---|---|
| `_gleGetState` | `iVar13` | 23 | at least six unrelated roles across the switch cases: texture unit offset from ctx+0x5004/+0x53d4/+0x53d8, renderer index << 2 (ctx+0x85a8), ctx+0x500c/+0x5008 selector, and record base `ctx+0x53d4*0x10 + ...`; a joined name would have to list every case |
| `_gleEmptyImage` | `iVar6` | 28 | row length (ctx+0x31cc), width fallback, stride remainder, byte skip, bit counter, bit-remaining and pixel-byte stride all share the register; the web cannot be split by name |
| `_gleCheckTexImageArgs` | `bVar1` | 9 | mixed polarity: sometimes true means out of range, sometimes `internalformat == 0x2a10` / `== 0x86dc` means accepted; a single role name would be false for part of the uses |
| `_glReadBuffer_Exec` | `bVar1` | 7 | four different comparisons (`mode == 0x400`, `iVar3 == 0`, renderer info byte == 0, `mode == 0x406`) |
| `_glColorTable_Comp` | `bVar1` | 7 | format equality tests (`== 0x80e1`, `== 0x1907`) and range tests on format; different conditions per use |

## Dead or split-register artefacts (suspected decompiler defect, not named)

| function | variable | uses | note |
|---|---|---|---|
| `_gleRenderFlatTriangleStripFunc_body` | `iVar14` | 12 | holds -1/previous backFacing, the lit-vertex cursor, and a dead write `iVar14 = 3` that is the polygon vertex count of the literal `3` passed to `_gleClipPolyPlane`; `polygonVertexCount` is read after the short-circuit `\|\|` without being set on that path |
| `_gleSelectQuadsFunc_body` | `iVar9` | 6 | previous backFacing plus a dead write `iVar9 = 4` (quad vertex count); same short-circuit pattern with `polygonVertexCount` |

## Roles not established by static reading

| function | variable | uses | note |
|---|---|---|---|
| `_gleGetState` | `param_5` | 5 | out byte that is set to 0 at entry and never written again in the function; callers pass a 16 byte stack buffer (`auStack_b0` in `_glGetBooleanv_Exec`); meaning not proven |
| `_glGetBooleanv_Exec` | `auStack_b0` | 2 | the buffer passed as `_gleGetState` param_5, see above |
| `_glGetColorTable_Exec` | `puVar11`, `auStack_50`, `auStack_54`, `auStack_58`, `auStack_5c` | 5+2+2+2+2 | pointer and four out words of the unnamed pack-parameter callee (`ctx+0x31b0`) and of `_glgConvertType`; not decoded |
| `_gleInitDerivedState` | `fVar1` | 3 | holds `FLOAT_00108e80`, stored at ctx+0x10c; the constant is used as a shininess bound elsewhere but its role for ctx+0x10c is not shown |
| `_gleArrayIncAndStoreVertexLoop` | `param_4` | 3 | switch selector 1,3,5 / 7,0xe taken from a 4 bit descriptor field at the only caller; the enum meaning is not established |

## Gate-sensitive renames (register allocation changes)

The gate reports `instruction sequence differs` when these locals are renamed (the diff is a pure
register swap of the pixel pack/unpack buffer pointer); every name that was tried is reverted so the
placeholders stay:

| function | variable | name tried | gate |
|---|---|---|---|
| `_glGetConvolutionFilter_Exec` | `iVar2`, `iVar3` | `convolutionStateThenImageEndOffset` / `typeFormatCheck`; `glStateBlockThenImageEndOffset` / `hasValidTypeFormat` | N5_6, N5_7, N5_16 differ (r26 <-> r25) |
| `_glSeparableFilter2D_Exec` | `iVar3` | `typeFormatCheck`; `hasValidTypeFormat` | N5_9, N5_16 differ (r21 <-> r20) |

The same rename on `_glConvolutionFilter1D_Exec` (`hasValidTypeFormat`) passes the gate.
