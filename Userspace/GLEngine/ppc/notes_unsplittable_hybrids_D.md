# Round 2 naming, agent D (parts 000-018): variables that could not be split

A register-allocated variable that carries two roles in one web (the decompiler could not
separate them and the gate shows that splitting changes register allocation) gets a joined
name that lists both roles. Entries:

| function | variable | name | roles |
|---|---|---|---|
| `_glBitmap_Exec` | `param_4` | `xorigShadowThenScratch` | r6 on entry is the unused GPR shadow slot of the float argument xorig (PPC32 Darwin ABI reserves GPR slots for float/double arguments); later the function reuses r6 as scratch for call arguments (`_gleOffsetLimitImage`, `_gleUpdateFramebufferCompleteness`). |

Functions whose names were attempted and dropped because the gate showed a register-allocation
change (they stay at the committed placeholder names, no name is false):

- `_gleCreateSharedState`, `_gleGetAttrib` (D2_2): splitting webs moved registers.
- `_glePPParse` (D2_5): callee-result names for the _PP*Create results moved registers.
- `_glCopyTexImage2D_Exec` (D2_7): the dispatchFlags rename moved registers (r28 -> r26).
