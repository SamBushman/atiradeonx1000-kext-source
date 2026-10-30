# q05 (parts 019-026) - what is left and why (Oct 30)

Placeholder count (regex of Tools/userspace/lpnames/ph.py family over non-comment lines of part_019..026): 7813 at the start of the round -> 1284.

Remaining, by cause:
* `FUN_000fb3d4` (~540): the `pdVarNN` dword-pointer scratch variables (pdVar25, pdVar17, pdVar31, ...) are single huge def-use webs (55-56 uses each) because
  gotos join every definition; the definitions are unrelated roles (register number, created instruction, descriptor cursor, ...). A name would be a multi-role
  misnomer; line-range splitting needs the post-join uses to belong to one definition, which they do not (gate: DATAFLOW / UNINIT).
* `ILReader__nextInstruction` iVar4 (86): one web from the first definition to the post-switch use `iVar4+0x14`; unsplittable.
* `FUN_000e3b88` iVar14 (35): its slot is the lowest frame slot, the anchor of gcc's folded `addi rX,r30,56` array addressing; splitting it gives
  `ADDRESS-TAKEN split ... 56`.
* `Program__translateILStream`: `local_14c/local_164/auStack_154/auStack_16c` are `#define` overlays of fake-struct buffers; `piVar18`, `pvVar16`,
  `ppppppuVar49` webs join several definitions (named with the joined role); `FUN_00127608` etc. are callees owned by other ranges.
* `iVar8/iVar7` in Program__splitMixedSourceKinds, `iVar1` in Block__findSimplePredecessor, DominatorTree__free: block-list-link / query-result scratch reused
  in one web.
* `ildisPrint*`: string buffers built from `.rodata` copies (fake char arrays).

Tools added this round: `webview.py` (PLAIN webs with def/use lines), `namecheck.py` (duplicate/colliding new names BEFORE the 100 s apply), `fbody.py`,
`gatediag.py` (new uninit variable + reaching-store diff), `gate.sh` honours TMPDIR; `apply_names.py USE_DECL=before`.
