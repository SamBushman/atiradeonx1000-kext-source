# difftest - does the rebuilt function do what the stock function does?

`difftest.py` runs ONE function of the stock `ATIRadeonX1000.kext` and the same function of a rebuilt kext, on the same inputs, in a PowerPC emulator
(Unicorn), and compares what they do. The generated code may differ in any way; the behaviour may not.

## What "the same" means (per function, per input)

1. **Calls**: every call to something outside the function - a kernel function, another function of the kext, a virtual method - has the same callee
   and the same arguments, in the same order. Callees are mocked: they are not run, they record the call and return a value that is the same on both sides
   (inside the callee's return domain: a `bool` callee returns 0 or 1, a pointer-returning one an object).
2. **Memory**: every write that outlives the call (through a pointer argument, into an object, into a global) leaves the same bytes. Writes to the
   function's own stack frame are not compared; a store that does not change a byte is not a difference. `--strict-order` also compares the order and
   width of ALL stores (debugging aid: harmless reordering and `stmw`-versus-`stw` differences fail it); `--strict-calls` also requires the memory a
   callee could observe (everything written so far) to be the same at every call.
3. **Return value**: the same (what is compared depends on the declared return type: `void` nothing, `bool` the low byte, ...).
4. **Ending**: both return (or both run out of budget / fault the same way), with the stack pointer and r14-r31 restored.
5. **Hardware registers**: every access to a register window is compared *strictly*: the same reads and writes, at the same offsets, with the same
   width and the same bytes, in the same order, interleaved identically with the calls (a callee may touch the hardware too). The code around the
   accesses may differ; what the hardware sees may not. A window is declared by the test world with `machine.mmio(size, model)`; the accelerator's
   register pointer (`+0x860`) must point into one (`accelerator_with_registers` in `Tests/difftest/common.py`). The optional `model` emulates the
   device (`RegisterFile` remembers writes and returns them on reads). The output shows `register accesses N` for a case, so a case that never
   touched its window is visible.
6. **Time**: reported as an instruction count of each side with the ratio. The emulator is not cycle-accurate, so this is a proxy; a ratio outside
   0.5-1.5 is flagged for a human, it is not a failure.

Each run also reports **coverage**: the fraction of the function's instructions executed by at least one run, for each side. A passing test with low
coverage proves little: improve the world (below).

## What the harness checks beyond the basics

* **Barriers**: `eieio`, `sync`, `lwsync` and `isync` inside the function become events in the same ordered stream as the register accesses and the calls, so a
  rebuilt function that drops or moves a barrier among its register accesses fails.
* **Device behaviour**: a register window can have a `model` (`Tests/difftest/common.py`: `RegisterFile`, `FlipFlopRegisters` - a rotation of answers so that
  both "wait until the bit clears" and "wait until it sets" loops end). A case with `replay=True` hands the register reads the stock function received back to
  the rebuilt one, in order, so the device cannot be the reason they differ; a different read PATTERN still fails.
* **Arguments**: integer, pointer, floating-point (raw bits) and stack-passed (9th word on) arguments of every mocked call are compared. A pointer into the
  kext's own image is compared by name (a C string by its text, a global by symbol and offset, a function by name), because the two builds lay the image out
  differently; a pointer to one of the function's own locals is compared by contents only when the case says how many bytes (`stack_args`).
* **Globals**: writes to the kext's own data are compared by symbol name and offset, not by address. `.comm` symbols of the rebuilt kext get storage
  like the kext linker would give them. Stored pointers to the kext's own data are compared by name; stored addresses of locals are masked.
* **Inlining**: a function that exists in only one image (the other build inlined it) is run for real on the side that has it; constructors and
  destructors run for real on both. Everything else is mocked.
* **Cost**: `est. cycles` weights each executed instruction by a coarse PowerPC 970 latency class (loads 3, multiplies 4, divides 20, FP 6, atomics 8, sync 30 ...).
  It is a model, not a measurement; a ratio outside 0.5-1.5 is flagged.
* **Speed**: `-j N` runs cases in N processes; `--case-seconds` bounds one case.

What is deliberately NOT in a single-function test: interrupts and other threads. The driver's locking is covered (every `IOLockLock/Unlock/Sleep/Wakeup` is a mocked
call that must match in order and arguments), and an interrupt handler is just another function that can be given a case, but a race between two threads
cannot be provoked by running one function; that is for the hardware soak tests.

## Running

    pip install --break-system-packages --target ~/.cache/kext-difftest/pkgs unicorn        # once
    sh Tools/difftest/build_rebuilt.sh [tiger-host]                                          # builds the working tree on the Tiger box; fetches build/difftest/rebuilt.bin and .dis
    STOCK_KEXT=/path/to/stock/ATIRadeonX1000.kext.bin sh Tests/difftest/run_all.sh [-j 24] [-f substring] [-v] [--json out.json] [--explain SEED]

`STOCK_KEXT` is the shipped kext binary (extract it from your own install); `REBUILT_KEXT` overrides the default `build/difftest/rebuilt.bin`.
Exit status 0 = every run identical.

## Rebuilt vs stock: the intended divergences (bug-for-bug parity = the `Stock` git tag)

The rebuilt kext fixes defects of Apple's shipped code on its own failure paths (there is no compile-time switch: the faithful port is the git tag `Stock`). Difftest against the stock kext
therefore reports exactly these divergences, and nothing else (911 cases: 892 PASS, these 19 FAIL; bug-for-bug parity is what the `Stock` tag represents, not re-run since the macro was removed; `SWDSFunc [hand H2]` is the unreproduced load flake described below, not a divergence):

| case | divergence (all intended) | issue |
|---|---|---|
| `ATIR500DVDContext::doIDCT` (both worlds) | extra `_IOLockUnlock(accelerator lock)` on the BadArgument exit | #98 |
| `IOATIR500GLContext::get_data_buffer` (both worlds) | extra `_IOLockUnlock` on the third NoResources exit | #99 |
| `IOATIR500Surface::allocAllSlaveSwapBuffers` | stock TIMEOUT / wild read in the failure unwind, rebuilt releases the descriptors and returns 0 | #32 |
| `ATIRadeonX1000::start_xdct_engine [hand H2]` | poll timeout: stock returns 1 and sets `xdctEngineRunning`, rebuilt returns 0 and leaves it clear | #127 |
| `ATIR500DVDContext::set_macrovision` | stock calls `getFramebufferIndex()` with `this == NULL` (boundSurface unbound: panic, DAR 0xD64); rebuilt unlocks and returns 0xe00002bc like the other nine boundSurface methods | #146 |
| `IOATIR500DVDContext::write_buffer` | stock loads `boundSurface->buffers[]` before its own `boundSurface == 0` test (wild read); rebuilt tests first and returns 0xe00002cc | #146 |
| `ATIR5002DContext::process_command_buffer (no shared allocator yet, #152)` | stock reads `sharedAllocator->count` with the lazily-created allocator still NULL (DAR 0x14); rebuilt takes the existing `abortStream` exit | #152 |
| `IOATIR500Surface::move_buffer_to_backing_store`, `alloc_buffer_backing_store` (and the write-lock tail of `surface_lock_options`) when the buffer is not one of the surface's 23 slots (generic cases, `(own slot or scanout record, #123)`, `(attachment is a scanout record, #123)`) | stock converts the buffer pointer to a slot index by modular division and calls `dealloc_surface(bogus index)` (e.g. 0x666666f0), which frees a record that is not an allocator element; rebuilt skips the release when `index >= 0x17` | #123 |
| `ATIRadeonX1000::stop` | stock shuts the PCIe GART down and frees `pcieGartTable` before the base `stop()` releases the orphan textures, command buffers and data buffers that are still mapped in it (`removeFromPCIeGART` then stores through NULL + entry*4, DAR 0xC6C); rebuilt stops the collectors and releases those resources first (extra `free_texvert`/`freeAllCommandBuffers`/`freeAllDataBuffers` calls before `shutdownPCIeGART`) | #179 |
| GL `process_command_buffer`: `opcode 0x36`, `H1 high-bit operands, opcode 0x36`, `opcode 0x36 with a client-chosen pointer`, and the `random streams` case when it draws 0x36 | stock treats record word 1 as a kernel `VendorTransferBuffer *` and writes through it (`map_transfer_to_GART`, `+0xe`, `+0x5c`); rebuilt rejects the record via `abortStream` | #125 |

Root causes, not guards: each of these fixes the reason the bad value arises. #146 - boundSurface is legitimately empty before `set_surface` and after `remove_surface`, and the two methods lacked the precondition that every sibling enforces (write_buffer: the vendor's own check existed but the load was ordered before it). #152 - the shared allocator is created lazily by create_image/declare_image/create_transfer, so before that every image id is invalid, which the vendor already answers with abortStream. #125 - a client-supplied stream word must not be a kernel pointer; the only emitter of the record in the shipped GLDriver is never enabled. #179 - teardown order: resources that live in the GART must be released while the GART exists; the base class releases them after the derived class has already destroyed it. #123 - a panel surface's attachment buffer is the accelerator's scanout record (display-owned VRAM), not a surface slot; the slot index recovered from the pointer is meaningless for it and the vendor's own sibling code already tests `index < 0x17`. One case (`ATIRadeonX1000::SWDSFunc [hand H2]`) diverged on a single seed during two loaded `-j 8` full runs and passed 247/247 every time in isolation on the same binary; not related to these fixes.

For a bug-for-bug parity run, check out the `Stock` tag in a separate worktree (`git worktree add ../kext-stock Stock`) and build the rebuilt kext from that tree with the same `Tools/difftest/build_rebuilt.sh` (expected: every case PASSes; not yet re-verified against the tag). Fixes are unconditional in the main tree; do not add compile-time switches for new ones.

## Writing a case (`Tests/difftest/*_cases.py`)

    Case('IOATIR500Surface::set_scaling', world, ret='u32', stack_args={'tmpAllocVRAM': {1: 16}})

`world(machine, rng)` allocates the objects the function works on (`machine.alloc`, `w32`, `vtable(class)`), using only `rng` for random choices, and
returns the argument registers (`this` first). It runs once per side per seed, so it must make the same allocations in the same order. Everything it
leaves unset is zero (or seeded noise with `lazy='random'`). Helpers in `Tests/difftest/common.py`: `surface_world` (a surface with a vtable, an
accelerator, panel counts, list nodes and buffer pointers), `context_lists`, `texture_buffer`, `auto_args` (typed arguments from the mangled
signature). Useful options: `mock` (what callees return), `stack_args` (how many bytes a callee reads through a pointer to the caller's local),
`seeds`, `limit`, `signature` (choose between overloads), `plain_words` (the function stores numbers - sizes, offsets, packet words - so a stored word that
happens to fall inside the kext image's address range is compared as a number, not as a pointer to the kext's own data).

`surface_auto_cases.py` generates a generic case for every other method of the class. Read its output: a low `cov` or many `inconclusive` runs mean the
function needs a hand-written world in `surface_cases.py`.

## Reading a result

* `PASS` with decent coverage: the rebuilt function behaved like the stock one on every run.
* `FAIL`: the first difference of each failing seed is printed (`-v` for all). Check first whether it is real: a world that hands the function a garbage
  pointer (a store into the kext's own code, a read of machine code as data) makes the run **inconclusive**, not failed; aliasing between objects the real
  driver never aliases can still produce a difference that is not a defect. A real one is a defect of the rebuilt code, or of the port's declared
  signature (for instance a `bool` function whose stock counterpart returns a count).
* `inconclusive`: the run hit the instruction budget or read code as data. The input, not the code, needs fixing.

## How it works, and its limits

Both images are unlinked MH_OBJECT kexts based at address 0 whose local relocations are already resolved, so the raw bytes are mapped at 0. External
symbols are redirected to stubs through their relocation entries, and every other function of the image is mocked by overwriting its first instruction
with a branch to a stub, so only the function under test runs. Stub addresses come from one registry shared by both sides. Not modelled: hardware
behaviour beyond what a `model` supplies (status bits that change, read-after-write side effects, the index/data handshake), interrupts, other threads, exact timing, and floating-point arguments of callees (compared as absent). Argument
registers beyond a callee's declared arity are not compared; where the arity is unknown (a plain-C external missing from `EXTERN_ARITY`) three registers
are compared and the call is marked `[arity unknown]`.

## Negative controls

A harness that cannot fail is worthless. Binary-patch a copy of the rebuilt kext (a different return register, a different immediate in a call, a store
to the wrong offset, a register offset mask) and run the matching case with `--rebuilt`: it must FAIL. This was done for a return value, a call argument and a store when the
harness was written.

## Reading the generic cases

`all_classes_cases.py` gives every method of every class a generic world (a "pointer soup": objects whose words are small integers, zeros, typical values and
pointers to LATER objects of the pool, so chains are valid and end). They reach the code but not every branch, and some inputs drive a function out of bounds
of one of its tables, where the two builds' data layouts differ: that is an artifact of the input, not a defect (`--explain` prints the reads and stores to
check). NO-RESULT means no run finished (budget exceeded or a wild pointer): the function needs a hand-written world.
To look at the machine code of a function in both builds: `Tools/difftest/disassemble.sh` makes the dump, `Tools/difftest/disfn.py NAME` prints it.

## Where do the estimated cycles go? (`profile_case.py`, `trace_case.py`)

    python3 Tools/difftest/profile_case.py Tests/difftest/hand_cases_C.py "opcode 0x06" [SEEDS]        # instructions by class, stock vs rebuilt
    python3 Tools/difftest/trace_case.py   Tests/difftest/hand_cases_C.py "opcode 0x31" SEED [PREFIX]  # the executed streams + a register-blind diff

`Tests/difftest/cycle_notes.md` records what these found and what is left above x1.10.

## Words that look like addresses

A stored word that is an address into the kext image is compared by the name of its target (so two layouts compare). A plain number that happens to equal an address in ONE of
the two images is then named on that side only; a byte whose two sides stored the same raw bytes is therefore not reported as a difference ("memory left behind differs"
needs different raw bytes). Cases whose words are never addresses can still say `plain_words=True`.

### Negative control for that rule

    STOCK_KEXT=... python3 Tools/difftest/negative_control.py build/difftest/rebuilt.bin [IMAGE_WHERE_A_TOKEN_EQUALS_AN_IMAGE_ADDRESS]

Runs `WriteVertexArrayOffset` with `plain_words` off on (1) the image as built (must PASS), (2) the image with one `oris` binary-patched so the function stores a different constant (must FAIL
with "memory left behind differs": a real difference is still caught), and (3) optionally an image whose layout makes a stored token equal an address inside it (must PASS with the raw-bytes
rule and FAIL with `DT_CANON_ONLY=1`, the old rule). Oct 20 2026 result with the tip of wt-R1 and the earlier image `~/g5logs/R1/b1.bin` for (3): UNCHANGED PASS, MUTATED FAIL, COINCIDENCE raw PASS / canonical-only FAIL.
