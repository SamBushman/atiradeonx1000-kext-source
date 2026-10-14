# VCALL dropped-argument sweep (#169, #171)

The Ghidra-ported sources call virtual methods through the untyped `VCALL(vt, off)(args)` (a variadic `GhidraVFn`), so the compiler cannot catch an omitted argument. The shipped code often leaves arguments live in registers (implicit forwarding) and the decompile drops them.

* `vcall_arity_sweep.py` - parses every `VCALL(...)(...)` in `Sources/`, resolves the vtable slot against `Ledger/kext_ppc_vtables.txt`, prints sites that pass fewer arguments than a candidate callee declares. Many slots are shared by several classes: treat "every candidate needs more" as strong, the rest as leads.
* `stock_call_site.py "Class::method" OFFSET_HEX [CONTEXT]` - shows the argument setup before the matching `bctrl` in the stock kext (Capstone via `ppcdisasm.py`; needs `pip install capstone`). Always confirm a hit here, and check the callee really reads the register (false positives: callees with no/fewer parameters than the slot's other classes).

Limits: ~60% of sites have a local-variable receiver whose class cannot be resolved automatically. Run it again after porting new functions.
