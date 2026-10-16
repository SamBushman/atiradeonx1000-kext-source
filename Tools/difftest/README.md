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

## Running

    pip install --break-system-packages --target ~/.cache/kext-difftest/pkgs unicorn        # once
    sh Tools/difftest/build_rebuilt.sh [tiger-host]                                          # builds the working tree on the Tiger box, fetches the binary
    STOCK_KEXT=/path/to/stock/ATIRadeonX1000.kext.bin sh Tests/difftest/run_all.sh [-f substring] [-v] [--json out.json]

`STOCK_KEXT` is the shipped kext binary (extract it from your own install); `REBUILT_KEXT` overrides the default `build/difftest/rebuilt.bin`.
Exit status 0 = every run identical.

## Writing a case (`Tests/difftest/*_cases.py`)

    Case('IOATIR500Surface::set_scaling', world, ret='u32', stack_args={'tmpAllocVRAM': {1: 16}})

`world(machine, rng)` allocates the objects the function works on (`machine.alloc`, `w32`, `vtable(class)`), using only `rng` for random choices, and
returns the argument registers (`this` first). It runs once per side per seed, so it must make the same allocations in the same order. Everything it
leaves unset is zero (or seeded noise with `lazy='random'`). Helpers in `Tests/difftest/common.py`: `surface_world` (a surface with a vtable, an
accelerator, panel counts, list nodes and buffer pointers), `context_lists`, `texture_buffer`, `auto_args` (typed arguments from the mangled
signature). Useful options: `mock` (what callees return), `stack_args` (how many bytes a callee reads through a pointer to the caller's local),
`seeds`, `limit`, `signature` (choose between overloads).

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
