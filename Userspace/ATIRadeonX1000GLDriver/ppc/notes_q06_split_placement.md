# Splitting fake-struct / address-taken frames: declaration placement (q06, Oct 30)

Trial on Program__packPsInputs (frame: local_98[4], local_94, local_90[4], local_80[4], local_70[6], local_58 addressed relative to each other;
gcc -O0 also folds `&local_98[i]` as `r30+<lowest slot>` + displacement).

Experiment (G5 gcc, split_equiv on part_032 only, one new scalar `interpAlloc` moved through all declaration positions, k = 0..29 before `local_80`):
* k = 0 (declared FIRST, apply_names default `USE_DECL=first`): MERGE `A172 stands for A165 and A168` - the new 4-byte slot lands at +168 between the bool at 164
  and the packed char array local_98 (165), pushing local_98 to 172.
* declared AFTER local_80/local_70/local_58 (`USE_DECL=end`): MERGE `slot 56 stands for 56 and 116` - the new slot becomes the lowest one (r30+56), which gcc
  also uses as the anchor of the `addi rX,r30,56 ; ... ; addi rX,rX,<disp>` address folding for local_98.
* k = 1..29 (anywhere between the first declaration and `local_90`/`local_80`): 0 problems.

Rule (implemented as `USE_DECL=beside` in Tools/userspace/apply_names.py, new decl directly after old's declaration): new scalar declarations go BEFORE the
fake-struct arrays and NOT first. With it the full split of packPsInputs (48 `use` rows, ~30 new declarations) is SPLIT-EQUIVALENT (gate q06_54).
Pitfalls hit: a segment must include every use of the web (`laneCount + iVar10 < 5` on the line that defines iVar10; the do/while condition line of the loop; the call
argument line after the loop) - the gate reports them as DATAFLOW / UNINIT, and the -O1 warning text names the variable and line.
