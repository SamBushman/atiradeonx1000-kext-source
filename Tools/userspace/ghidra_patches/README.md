# Patched Ghidra decompiler (float compares)

`decompiler_float_compare_not_flippable.patch` (Ghidra 12.1.3 PUBLIC, `Decompiler/src/decompile/cpp/opcodes.cc`): `get_booleanflip` no longer reports
FLOAT_LESS / FLOAT_LESSEQUAL as flippable. Stock Ghidra rewrites `!(a < b)` into `b <= a` (RuleBooleanNegate and the block-structuring negations), which is
only true when neither operand is NaN: an unordered compare is false for BOTH. The stock GLEngine's gcc code keeps the distinction (`fcmpu; bge` skips on NaN,
`cror eq,lt,eq; bne` does not) so a flipped condition made the rebuilt code treat a NaN operand differently (`_gleVectorNormalizeNO`, `_glClearDepth_Exec`,
the `_gleInterpolClip*` family, ... found by fnfuzz with FNFUZZ_NANMODE=1). With the patch the decompiler prints `!(a < b)`.

Build (a minute, g++ + make): copy `Ghidra/Features/Decompiler/src/decompile` somewhere, `patch -p0 < decompiler_float_compare_not_flippable.patch` in the copy's
`cpp` directory parent, `make ghidra_opt -j8` in `cpp`, install the resulting `ghidra_opt` as `Ghidra/Features/Decompiler/os/linux_x86_64/decompile` (the unpatched binary:
md5 b69341805caa578be4dbd57ea1c086e2). Then re-run `DecompAll.java` with `DECOMP_PAREN_FLOAT=1 DECOMP_TYPED_CALLS=1 DECOMP_PRESERVED=1` (reproduces the committed
GLEngine dump function for function except the float-compare functions).
