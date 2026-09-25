import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.util.task.ConsoleTaskMonitor;
import java.io.File;
import java.io.FileWriter;
import java.util.HashSet;

// RedumpKeepUnreachable.java OUT hexAddr... - RedumpContaining with the decompiler's "Eliminate unreachable code" option OFF. Ghidra's constant
// propagation can decide a block is dead when a flag it cannot see change (a local a callee updates through a pointer) gates it, and then drops the block
// ("WARNING: Removing unreachable block"): _glpPPShaderToProgramString lost the code that writes `TEMP scratch;` (issues #68, #72). With the option off
// every block of the machine code is printed.
public class RedumpKeepUnreachable extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String outDir = args[0];
        DecompInterface decomp = new DecompInterface();
        decomp.openProgram(currentProgram);
        decomp.setSimplificationStyle("decompile");
        ghidra.app.decompiler.DecompileOptions opts = new ghidra.app.decompiler.DecompileOptions();
        opts.grabFromProgram(currentProgram);
        opts.setEliminateUnreachable(false);
        decomp.setOptions(opts);
        HashSet<String> seen = new HashSet<>();
        for (int i = 1; i < args.length; i++) {
            String hex = args[i].startsWith("0x") ? args[i].substring(2) : args[i];
            Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(hex);
            Function fn = getFunctionContaining(a);
            if (fn == null) { println("no function containing " + args[i]); continue; }
            String eh = Long.toHexString(fn.getEntryPoint().getOffset());
            if (!seen.add(eh)) continue;
            File outFile = new File(outDir, "0x" + eh + ".txt");
            try (FileWriter fw = new FileWriter(outFile)) {
                fw.write("// Function: " + fn.getName(true) + " @ " + fn.getEntryPoint() + "\n");
                fw.write("// Signature: " + fn.getSignature() + "\n\n");
                DecompileResults res = decomp.decompileFunction(fn, 180, new ConsoleTaskMonitor());
                if (res != null && res.decompileCompleted()) fw.write(res.getDecompiledFunction().getC());
                else { fw.write("!! decompile failed\n"); println("DECOMPILE ERROR: " + (res == null ? "null" : res.getErrorMessage())); }
            }
            println("redumped " + eh);
        }
    }
}
