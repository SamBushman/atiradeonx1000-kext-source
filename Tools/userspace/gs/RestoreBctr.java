import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
public class RestoreBctr extends GhidraScript {
    @Override
    public void run() throws Exception {
        for (String x : getScriptArgs()) {
            Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(x.replace("0x", ""));
            clearListing(a, a.add(3)); setInt(a, 0x4e800420); disassemble(a);
            println("restored bctr at " + a + " -> " + getInstructionAt(a));
        }
    }
}
