import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.util.task.ConsoleTaskMonitor;

// Usage: PatchTest.java <funcAddr> <bctr:target> ... : restore each bctr (0x4e800420), then patch them one at a time, decompiling after each
public class PatchTest extends GhidraScript {
    void put(Address a, int v) throws Exception { clearListing(a, a.add(3)); setInt(a, v); disassemble(a); }
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        Address fa = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(args[0].replace("0x", ""));
        for (int i = 1; i < args.length; i++) { Address b = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(args[i].split(":")[0].replace("0x", "")); put(b, 0x4e800420); }
        DecompInterface d = new DecompInterface(); d.openProgram(currentProgram); d.setSimplificationStyle("decompile");
        for (int i = 1; i < args.length; i++) {
            String[] p = args[i].split(":");
            Address b = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(p[0].replace("0x", ""));
            Address t = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(p[1].replace("0x", ""));
            put(b, 0x48000000 | (int) ((t.getOffset() - b.getOffset()) & 0x03fffffcL));
            Function f = getFunctionContaining(fa);
            DecompileResults r = d.decompileFunction(f, 120, new ConsoleTaskMonitor());
            println("after patching " + b + ": " + (r != null && r.decompileCompleted() ? "OK (" + r.getDecompiledFunction().getC().length() + " chars)" : "FAILED " + (r == null ? "" : r.getErrorMessage())));
            if (r == null || !r.decompileCompleted()) { d = new DecompInterface(); d.openProgram(currentProgram); d.setSimplificationStyle("decompile"); }
        }
    }
}
