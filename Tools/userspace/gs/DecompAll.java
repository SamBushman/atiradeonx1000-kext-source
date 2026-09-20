import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.util.task.ConsoleTaskMonitor;
import java.io.File;
import java.io.FileWriter;

// Usage: -postScript DecompAll.java <outDir> [minAddrHex] [maxAddrHex]
// Writes <outDir>/<entry>.txt for every (non-external, non-thunk) function, and <outDir>/INDEX.tsv (entry, size, name).
public class DecompAll extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String outDir = args[0];
        long lo = args.length > 1 ? Long.parseLong(args[1].replace("0x",""), 16) : 0;
        long hi = args.length > 2 ? Long.parseLong(args[2].replace("0x",""), 16) : Long.MAX_VALUE;
        new File(outDir).mkdirs();
        DecompInterface decomp = new DecompInterface();
        decomp.openProgram(currentProgram);
        decomp.setSimplificationStyle("decompile");
        FileWriter idx = new FileWriter(new File(outDir, "INDEX.tsv"), true);
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        int n = 0, fail = 0;
        while (it.hasNext()) {
            Function fn = it.next();
            if (fn.isExternal() || fn.isThunk()) continue;
            long a = fn.getEntryPoint().getOffset();
            if (a < lo || a >= hi) continue;
            String hex = Long.toHexString(a);
            long size = fn.getBody().getNumAddresses();
            File outFile = new File(outDir, "0x" + hex + ".txt");
            if (outFile.exists()) continue;
            try (FileWriter fw = new FileWriter(outFile)) {
                fw.write("// Function: " + fn.getName(true) + " @ " + fn.getEntryPoint() + "\n");
                fw.write("// Signature: " + fn.getSignature() + "\n\n");
                DecompileResults res = decomp.decompileFunction(fn, 60, new ConsoleTaskMonitor());
                if (res == null || !res.decompileCompleted()) {
                    // a very large function (GLDriver FUN_00115fa0, 34 KB) exceeds the default payload/instruction limits: retry once with generous ones
                    DecompInterface big = new DecompInterface();
                    DecompileOptions o = new DecompileOptions();
                    o.setMaxPayloadMBytes(256); o.setMaxInstructions(2000000);
                    big.setOptions(o); big.openProgram(currentProgram); big.setSimplificationStyle("decompile");
                    res = big.decompileFunction(fn, 1800, new ConsoleTaskMonitor());
                    big.dispose();
                }
                if (res != null && res.decompileCompleted()) fw.write(res.getDecompiledFunction().getC());
                else { fw.write("!! decompile failed\n"); fail++; }
            }
            idx.write("0x" + hex + "\t" + size + "\t" + fn.getName(true) + "\n");
            n++;
        }
        idx.close();
        println("DECOMPALL done " + n + " failed " + fail);
    }
}
