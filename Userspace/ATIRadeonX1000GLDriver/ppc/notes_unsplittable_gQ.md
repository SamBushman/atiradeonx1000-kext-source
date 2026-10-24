# GLDriver names that stay one name because the gate rejected a split (lp17 / tag gQ)

* `copyIndices16Swapped_dcbz` / `_dcbz_entry` `tempVec` (Ghidra auVar8): its four webs (realigned head vector, head merged under the misalignment mask, fourth
  loop output, next tail load) share one AltiVec register/frame slot; naming them apart gave `DATAFLOW _FUN_0001eae0 4 loads reached by different stores` (gate gQ8,
  NOT-EQUIVALENT). Merged back as `tempVec` (gate gQ10 SPLIT-EQUIVALENT).
* `gldPackColorForSurfaceFormat` `packedColor` (Ghidra fVar6): starts as the 8-bit alpha and several switch cases (case 2, the alpha-only format) leave it unchanged as the result,
  so alpha and the packed colour are ONE web; splitting alpha/packed gave `UNINIT 'packedColor' may be used uninitialized` + DATAFLOW (gate gQ13, NOT-EQUIVALENT).
  Kept as one result accumulator (gate gQ15 SPLIT-EQUIVALENT). The `dVar7` clamp/scale in-place lines split cleanly (redClamped / redScaled).
