# GLDriver names that stay one name because the gate rejected a split (lp17 / tag gQ)

* `copyIndices16Swapped_dcbz` / `_dcbz_entry` `tempVec` (Ghidra auVar8): its four webs (realigned head vector, head merged under the misalignment mask, fourth
  loop output, next tail load) share one AltiVec register/frame slot; naming them apart gave `DATAFLOW _FUN_0001eae0 4 loads reached by different stores` (gate gQ8,
  NOT-EQUIVALENT). Merged back as `tempVec` (gate gQ10 SPLIT-EQUIVALENT).
