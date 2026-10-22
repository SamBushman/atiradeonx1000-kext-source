# GLDriver functions: subsystem classification and the identifications behind the new names (fork D8, round 3)

Starting point: 2,595 `FUN_` functions. After this fork 2,250 are still `FUN_` (345 renamed, `names_D8_func.tsv`). Every function (4,027 including the already
named ones) has a row in `subsystem_map.tsv` (address, current name, size, subsystem, basis). **Classification coverage of the remaining `FUN_` functions:
1,359 of 2,250 (60%)**; 891 are unclassified (leaf helpers with no labelled neighbours, or neighbours that disagree).

Counts of the `FUN_` functions per subsystem: compiler IR 823, command-ring emitters 147, kernel interface 125, R500 backend 117, GL state and hooks 54,
GLD API 36, string 20, locking/runtime 19, math 12, pixel conversion 5, shader dump 1, unclassified 891.

## How a function gets a subsystem (in order)
1. Its name already says (an existing real name: `_gld*`, `Class__method`, `pass_*`, R300/R520/Khan/Fudo/HwLimits/SchedModel, psn*/vs*, the names below).
2. Rules on its body: it calls `_io_connect_method_*` / `IOConnectMapMemory` / `IOServiceOpen` (kernel interface), `_glg*` imports (pixel conversion), libm (math),
   `str*` (string), `pthread_mutex`/`__keymgr` (locking/runtime), or writes `0xNN000000` ring packets through the ring cursor fields +0x1d8/+0x1dc/+0x1e0
   (command-ring emitter).
3. RTTI: it is listed in `class_methods.tsv` (it stores a class vtable or sits in a vtable slot) -> compiler IR.
4. Neighbours: the label held by at least 60% of its labelled callers and callees (not counting the leaf classes), iterated up to 12 rounds (about 1,300 functions
   by round 12). This step is the weakest: a function with one labelled neighbour inherits its label. The `basis` column says which step produced each label.

## Identifications (func rows in `names_D8_func.tsv`; tiers in the file)
* **253 static-object destructor stubs** (GCC `__tcf_N`; `<IrClass>__opcodeInfo_atexit_dtor_op<N>`, CONFIRMED). `FUN_00115fa0` builds one global `OpcodeInfo`
  object per opcode and registers each stub with `atexit` (`FUN_00002748`). The stub body is `DAT_<object> = PTR_DAT_<nl_symbol_ptr> + 8` (it restores the base
  vtable); the class in the name is the vtable stored into the same object by the initialiser, and N is the opcode number stored at object+8.
* **35 trivial functions** (CONFIRMED by the instruction words): 29 `blr` (`noop_<addr>`), 5 `li r3,0; blr` (`returnZero_<addr>`, one is dispatch slot 0x20),
  1 `li r3,1; blr` (`returnOne_<addr>`).
* **19 functions identical to code in the other images** (CONFIRMED): 13 C-runtime atexit/dyld shims (`_atexit`, `_run_routines`, `_get_globals`, ... same
  code as in the GA and VA binaries), the `_window_mode_to_ati_format` helper, `___stub_getrealaddr` and four `printf_LDBLStub` copies. Method: instruction words
  with branch targets and immediates masked, size >= 40 bytes, a single distinct name among the matches (`Tools`: scratch matcher, see below).
* **17 kernel-interface wrappers (CONFIRMED by selector and request type).** Selectors are those of the GL-context user client
  (`Sources/IOATIR500GLContext_ExternalMethods.cpp`): 8 finish, 9 wait_for_stamp, 10 new_texture, 11 delete_texture, 13 page_off_texture, 0x12 get_data_buffer,
  0x14 get_hw_info. The memory-backing setters send a request {type tag, args...} to selector 10; the type tag is the `new_texture` switch of the kernel:
  0 new_surface_texture, 1 new_global_texture, 2/3/7 new_texture (1/2/4 size arguments), 6 new_agpref_texture (address, size, limit). Names: `gld_set*Backing`,
  `gld_ensure*Backing` (reuse the current backing when its kind byte at +0x16 and arguments match, else recreate), `gld_wait*Stamp`, `gld_releaseQueryMemory`.
  The object kinds (buffer, texture, vertex array, query record) come from the callers (`_gldFinishObject`, `_gldGetQueryInfo`, FUN_00032100, FUN_0001dc10).
* **GL hooks** (fork X's and R4's identifications turned into names; INFERRED unless the GL enums fix them): `glAccum_impl` (CONFIRMED by the 0x100..0x104
  accumulation cases), `glBitmap_impl`, `glDrawPixels_impl`, `gld_drawPixelsDispatch`, `gld_drawPixelsFromClientSurface`, `glReadPixels_impl`,
  `gld_readPixelsViaBlit`, `glTexSubImage_impl`, `glGenerateMipmap_impl`, `gld_drawVertexArray`, `glFinish_impl` (dispatch+0x58), `glFlush_impl`,
  `glFlush_impl_withSurfaceUpdate` (dispatch+0x60), the ring helpers `gld_submitRing`, `gld_isStampRetired`, `gld_startPacket`, `gld_signalFence`.
* `gld_initContextHardwareState` (CONFIRMED: selector 0x14), `gld_testRendererAvailable` (selector 3 on a temporary connection),
  `gld_setIntegerEngineParam` (the pname switch behind `_gldSetInteger`).

## The dispatch table
`_gldInitDispatch` fills `dispatch[0..0x20]` with entries read through `__nl_symbol_ptr` (the `PTR_FUN_` constants hold the function addresses):
slot 0 `glAccum_impl` (FUN_00002ae0), 1 FUN_00020330 (state-dirty mask update), 2 `glReadPixels_impl`, 3 `gld_drawPixelsDispatch`, 4 FUN_00018120 (6 KB, not
identified), 5 `glBitmap_impl`, 0x13 FUN_00024970 (writes a 0x26000000 packet, clears cache lines), 0x14/0x15 FUN_000273a0/FUN_00026bf0 or
FUN_00026f80/FUN_00027150 (chosen by the byte at ctx+0x2b82; vertex-state paths), 0x19 `gld_signalFence`, 0x1a/0x1b FUN_0002b740/FUN_0002bbc0, 0x1c
`gld_drawVertexArray`, 0x1d FUN_000353a0, 0x1e `glTexSubImage_impl`, 0x1f `glGenerateMipmap_impl`, 0x20 `returnZero_1e270`.
`_gldUpdateDispatch` then rewrites +0x18..+0x3c, +0x58 (finish), +0x5c (flush) and +0x60 (flush variants) by the render flags.
The slot indices are not GL API indices (this is the GLD driver's own hook table), so the slots are named only where the target function is identified.

## Not done / limits
* 891 functions are unclassified; the 60% neighbour rule can be wrong for functions shared between subsystems (the compiler's allocator and bitset helpers
  are called from many places).
* FUN_00018120, FUN_00020330, FUN_00024970, FUN_000273a0/FUN_00026bf0/FUN_00026f80/FUN_00027150, FUN_0002b740/FUN_0002bbc0, FUN_000353a0 are dispatch targets
  whose role I could not establish from the body; they are classified (GL state and hooks) but not named.
* Cross-image matching used a scratch script (`xmatch.py` in the session scratchpad: loads each image with `Tools/userspace/machoutil.py`, masks branch targets and
  D-form immediates); only unique-name matches of >= 40 bytes were used. Shorter matches (getters such as `Binding__GetLocation` vs FUN_00134ab0) were not used:
  the same 8-byte body fits any struct getter.
* Names, parameters: the renamed wrappers keep their parameter names from the earlier forks; no new `local` rows.
