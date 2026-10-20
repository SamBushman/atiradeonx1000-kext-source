# Allocation-site audit (`new T`, `MetaClass::alloc`, init-failure and release paths)

Bug class (#187): under gcc 4.0.1 `-fapple-kext`, `new T()` / `new T` compiles to `OSObject::operator new` followed by an UNCONDITIONAL constructor call. If the
allocation fails the constructor writes through a null `this`. The shipped driver tests the allocation first (`bl operator new; cmpwi/or. r3; beq skip; bl ctor`).
Sibling flaw: a failed `init()` that releases the object but leaves the stored pointer (shipped code stores 0).

Method: every allocation site in `Sources/` and `Headers/` found by grep (`operator new`, `GH_ZN8OSObjectnwEm`, `new `, `OSDefine*Structors`, `->release()`), each compared with
the stock disassembly (`otool -tV` of the shipped kext) and the rebuilt disassembly of the image built from the tree.

| # | Site (function, file) | Stock | Rebuilt before | After | Test case |
|---|---|---|---|---|---|
| 1 | `ATIRadeonX1000::MetaClass::alloc` (macro `OSDefineMetaClassAndStructors`, `Sources/MetaClassRegistration.cpp`) | `operator new(0xc60)`; `beq` skip; ctor | **unconditional ctor call (defect)** | explicit null test (`ATI_DefineMetaClassAndStructors`) | `hand_cases_R2.py` (`_ZNK14ATIRadeonX10009MetaClass5allocEv`, allocation fails on odd seeds) |
| 2 | `ATIR500GLContext::MetaClass::alloc` | same shape (0x690) | **defect** | fixed | `hand_cases_R2.py` |
| 3 | `ATIR5002DContext::MetaClass::alloc` | same shape (0x12c) | **defect** | fixed | `hand_cases_R2.py` |
| 4 | `ATIR500DVDContext::MetaClass::alloc` | same shape (0x1e0) | **defect** | fixed | `hand_cases_R2.py` |
| 5 | `ATIR500Surface::MetaClass::alloc` | same shape (0xdbc) | **defect** | fixed | `hand_cases_R2.py` |
| 6 | `IOATIR500Shared::MetaClass::alloc` | same shape (0x28) | **defect** | fixed | `hand_cases_R2.py` |
| 7 | `ATIR500Memory::MetaClass::alloc` | same shape (0x14) | **defect** | fixed | `hand_cases_R2.py` |
| 8 | `IOATIR500Accelerator/GLContext/2DContext/DVDContext/Surface::MetaClass::alloc` (abstract) | `li r3,0; blr` | `li r3,0; blr` | unchanged (identical) | not needed (no allocation) |
| 9 | `ATIRadeonX1000::new_surface/new_2d_context/new_dvd_context/new_gl_context` (`ATIRadeonX1000_ContextFactories.cpp`) | allocation tested before ctor | explicit test (already correct) | unchanged | `hand_cases_A.py` (allocation fails on every third seed) |
| 10 | `ATIRadeonX1000::start`, `ATIR500Memory` (`ATIRadeonX1000_Start.cpp`) | tested; pool pointer stored as returned | fixed earlier (#187) | unchanged | `start` case (78/78) |
| 11 | `ATIRadeonX1000::start`, sensor object `OSObject::operator new(0x50)` (`ATIRadeonX1000_Start.cpp`) | explicit test in the decompile; init failure releases and clears the provider | explicit test (already correct) | unchanged | `start` case |
| 12 | `IOATIR500Accelerator::start`, `ATIR500Memory` | tested | fixed by fork H4 | unchanged | `hand_cases_H4.py` (200/200) |
| 13 | `IOATIR500GLContext::start`, `IOATIR500Shared` | tested; failed `init()` stores 0 in `clientHandle` | fixed by fork H5 | unchanged | `hand_cases_H5.py` (77/77) |
| 14 | `IOATIR5002DContext::create_shared`, `IOATIR500Shared` | tested; failed `init()` releases (vtable +0x18) then stores 0 at +0x88 | explicit test, stores 0 (already correct) | unchanged | `hand_cases_D.py` (allocation fails on every third seed) |
| 15 | `IOATIR500DVDContext::create_shared`, `IOATIR500Shared` | tested; failed `init()` releases then stores 0 at +0x84 | explicit test, stores 0 (already correct) | unchanged | `hand_cases_D.py` |

Other release paths looked at (`IOATIR5002DContext_Lifecycle.cpp`, `IOATIR5002DContext_Surface.cpp`, `ATIRadeonX1000_SmallMethods.cpp`): plain `->release()` calls on objects obtained from
the registry or created by the callee; no constructor expression, no stored pointer left dangling relative to the decompile. No `delete` expression and no `operator new[]`
exists in the kext sources.

Result: 7 defective sites (the macro-generated `MetaClass::alloc` of the seven concrete classes), all one root cause, fixed in `Sources/MetaClassRegistration.cpp`. Negative
control: on the image built without the fix the seven new cases FAIL (seeds 1, 3, 5, 7: stock returns, rebuilt reads a wild pointer, +40% estimated cycles); with the fix
all seven PASS.
