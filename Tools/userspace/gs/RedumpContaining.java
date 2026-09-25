import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.util.task.ConsoleTaskMonitor;
import java.io.File;
import java.io.FileWriter;
import java.util.HashSet;

// Usage: -postScript RedumpContaining.java <outDir> <hexAddr>...   re-decompiles the function containing each address and overwrites <outDir>/0x<entry>.txt
public class RedumpContaining extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String outDir = args[0];
        DecompInterface decomp = new DecompInterface();
        ghidra.app.decompiler.DecompileOptions dopts = new ghidra.app.decompiler.DecompileOptions();
        dopts.grabFromProgram(currentProgram);
        dopts.setMaxPayloadMBytes(512);   // FUN_00115fa0's C exceeds the default response buffer
        decomp.setOptions(dopts);
        decomp.openProgram(currentProgram);
        decomp.setSimplificationStyle("decompile");
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
                // a very large function (GLDriver FUN_00115fa0, ~3500 lines of state-table initialisation) needs longer: retry once with 30 minutes
                if (res == null || !res.decompileCompleted()) res = decomp.decompileFunction(fn, 1800, new ConsoleTaskMonitor());
                if (res != null && res.decompileCompleted()) fw.write(res.getDecompiledFunction().getC());
                else { fw.write("!! decompile failed\n"); println("DECOMPILE ERROR: " + (res == null ? "null" : res.getErrorMessage())); }
            }
            println("redumped " + eh);
        }
    }
}
