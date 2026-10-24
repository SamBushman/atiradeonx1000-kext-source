# libGLProgrammability: variables that stay one name because the gate (or the dataflow) forbids splitting them (lp15)

Scope: part_013, 014, 015, 017, 018, 019, 025, 026, 029. Everything else with an "A or B" name in those parts was split into per-role names
(`seg.py` rows; gates lpO1..lpO8). Evidence per name: `find_webs.py` (def-use webs) and the gate.

A split needs two different def-use webs. These variables are ONE web (or address-taken), so a second name would make the gate report DATAFLOW /
UNINIT. Each got one name for the slot instead of an "A or B" list.

| function | name | what the single slot holds | why one name |
|---|---|---|---|
| `_InterpreterTextureSamplerSampleTexel{1D,2D,3D}` | `lodBias` (parameter f1) | the TXB/LOD bias argument; the body overwrites it with the clamped level and forwards it to `...FromLevel` | it is a parameter (parameters cannot be split) and the forwarded call at the end receives both values along different paths |
| `_PPParserParseBranchCondition` | `conditionCode` | `_memcmp` result of each condition name, then the code 1..6; a TR match leaves 0 which IS the code | the 0 from the compare reaches `code << 0x1c`: one web |
| `_uw_update_context_1` | `scratchResult` | CFA slot pointer, then `_execute_stack_op` results; the last one is also the function's (spurious) return | one web (find_webs: 1 web) |
| `_execute_stack_op` | `decodedImmediate` | pick index / bra-skip offset / sleb128 operand | address taken (`&decodedImmediate` for `_read_sleb128`) |
| `_LinearizeFixOutputReads` | `tempDeclWord1Overlay` | stack slot `local_7c`: scan cursor, then word 1 of the temp declaration record at `&local_80` | address taken, contiguous with the record words (adding a declaration moves them) |
| `_FlattenIf` | `keyIteratorOverlay`, `keySizePairHeaderOverlay` | stack overlays `local_1a0`/`local_190`: RegInfo lookup key, HashSet iterator state, entry-copy record | address taken, contiguous words |
| `_PPCRuntimeCompilerCompileNO` | `argReg5`, `argReg8`, `argReg9`, `argReg10` | `in_r5/r8/r9/r10`: source-descriptor word loaded from the source record, later the code cursor / temp passed in the same argument register | each is one web because the final `_glpPushInstructions` call reads the register along every path |
| `_PPCRuntimeCompilerBackupRegister` | `vectorModeLoaded` | 0 and the `_memcmp` result in the descriptor-compare loop, then the vector-mode flag from `compiler+0x393` | find_webs: 1 web (the earlier definitions reach the later tests along paths that skip the load) |
| `_InterpreterRun` | `fragmentListHead` | `machine+0xa5c`, then (loop back edge) the new emulator instruction count; both reach only the dead 7th argument of `_InterpreterWriteFinalFragmentToBuffer` | one web |
| `_InterpreterEmulateOp` | `scratchF2`, `scratchF5`..`scratchF8` | FPR scratches forwarded as stale arguments to the texture sampler | one web each (named after the register) |

Not hybrids (one concept, the word "or" is part of it): `isPcrelOrAligned` (a bool testing "application is pcrel or aligned", set on
the two halves of the range test), `depthOrEqualPassed`, `regOrOffsetSlot` (libgcc's `reg_or_offset` field).

## part_014 `+ fparam_1` in SampleTexel (suspected decompile artifact)

Verdict: genuine. `lodBiasedClamped = lambda + textureObject.lodBias (+0x40) + f1`: f1 is the per-instruction LOD bias (TXB), the same value
`_InterpreterEmulateOp` passes as `texLodBias`. GL: lod = lambda + texture bias + program bias. Only the later reuse of the f1 parameter as
scratch (assigned `lodBiasedClamped`, then forwarded) is a compiler artifact; that is what `lodBias` documents.
