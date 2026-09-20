// NopMillicode.java LO HI [LO HI ...] - `bl` into the register-save millicode (an entry into the stfd f14..f31 chain) becomes a `nop` in the analysed copy.
// The millicode only stores callee-saved FPRs (the recompiled C function saves what it uses itself) and preserves r3..r10, but the decompiler models it as a call
// that clobbers the argument registers: the function's own arguments read back as `extraout_rN` / dropped call arguments.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class NopMillicode extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        int n = 0;
        List<Address> sites = new ArrayList<>();
        for (int i = 0; i + 1 < a.length; i += 2) {
            AddressSet rng = new AddressSet(toAddr(a[i]), toAddr(a[i + 1]));
            for (Address t : rng.getAddresses(true))
                for (Reference r : currentProgram.getReferenceManager().getReferencesTo(t)) {
                    Instruction in = currentProgram.getListing().getInstructionAt(r.getFromAddress());
                    if (in != null && in.getMnemonicString().equals("bl")) sites.add(r.getFromAddress());
                }
        }
        for (Address s : new LinkedHashSet<>(sites)) {
            clearListing(s, s.add(3));
            currentProgram.getMemory().setInt(s, 0x60000000);
            disassemble(s);
            n++;
        }
        println("NOPMILLICODE patched " + n + " call sites");
    }
}
