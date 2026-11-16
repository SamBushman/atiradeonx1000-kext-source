Directed controls and static detectors used for #297-#299 (Nov 16). Paths inside point at the session's scratch layout (`~/g5logs/fnf_237/<img>/`): adapt `G`/`img` before use.
* `ctl_quant.py IMG` - gld_quantizePointSizeInt with f1 = +-2^23..2^25 edge values (stock vs rebuilt r3); the old image differs, a fixed image is identical.
* `ctl_v85.py IMG NAME...` - the vslot85_findOrEncodeConstantVector family with four equal float words; hooks the callee Program__findOrCreateConstInst and prints the 16-byte vector it receives.
* `fpprec.py` / `magprec.py` / `fpseq.py STOCK REBUILT LEDGER NM [names]` - single/double FP op counts and int-to-float magic-constant counts per function (capstone skipdata; over-reports: only "stock 0, rebuilt >0" is a reliable signal).
* `lastpc.py PKL NAME` - replay one saved trial and print the last instructions each image executed before its fault.
