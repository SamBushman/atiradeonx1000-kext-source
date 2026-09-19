import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.util.task.ConsoleTaskMonitor;
import java.io.File;
import java.io.FileWriter;

// Usage: -postScript DecompAt2.java <outDir> <hexAddr1> [hexAddr2] ...
public class DecompAt2 extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String outDir = args[0];
        new File(outDir).mkdirs();
        DecompInterface decomp = new DecompInterface();
        decomp.openProgram(currentProgram);
        decomp.setSimplificationStyle("decompile");
        for (int i = 1; i < args.length; i++) {
            String arg = args[i];
            String hex = arg.startsWith("0x") ? arg.substring(2) : arg;
            Address addr = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(hex);
            Function fn = getFunctionAt(addr);
            if (fn == null) fn = currentProgram.getFunctionManager().getFunctionContaining(addr);
            File outFile = new File(outDir, arg.replaceAll("[^A-Za-z0-9_]", "_") + ".txt");
            try (FileWriter fw = new FileWriter(outFile)) {
                if (fn == null) {
                    fw.write("!! no function at " + arg + "\n");
                    continue;
                }
                fw.write("// Function: " + fn.getName(true) + " @ " + fn.getEntryPoint() + "\n");
                fw.write("// Signature: " + fn.getSignature() + "\n\n");
                DecompileResults res = decomp.decompileFunction(fn, 120, new ConsoleTaskMonitor());
                if (res != null && res.decompileCompleted()) {
                    fw.write(res.getDecompiledFunction().getC());
                } else {
                    fw.write("!! decompile failed\n");
                }
            }
            println("WROTE[" + arg + "] -> " + outFile.getAbsolutePath());
        }
        decomp.dispose();
    }
}
