import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.util.task.ConsoleTaskMonitor;
import java.io.*;
import java.util.*;

// Usage: -postScript CreateOrphans.java <pads.tsv (start end owner)> <outDir>
// Creates a function (orph_<addr>) at each C++ exception landing pad start, decompiles it into <outDir>/0x<addr>.txt (+ INDEX.tsv, PADOWNERS.tsv).
public class CreateOrphans extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        File out = new File(args[1]); out.mkdirs();
        ArrayList<Function> old = new ArrayList<>();
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) if (f.getName().startsWith("orph_")) old.add(f);
        for (Function f : old) removeFunction(f);
        println("removed " + old.size() + " earlier eh_pad functions");
        DecompInterface d = new DecompInterface(); d.openProgram(currentProgram); d.setSimplificationStyle("decompile");
        try (BufferedReader br = new BufferedReader(new FileReader(args[0]));
             FileWriter idx = new FileWriter(new File(out, "INDEX.tsv"));
             FileWriter own = new FileWriter(new File(out, "PADOWNERS.tsv"))) {
            String l; int ok = 0, bad = 0;
            while ((l = br.readLine()) != null) {
                String[] f = l.split("\t");
                Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(f[0]);
                Function fn = getFunctionAt(a);
                if (fn != null && fn.getName().startsWith("orph_")) { removeFunction(fn); fn = null; }   // recreate with the noreturn flow
                if (fn == null) {
                    if (getInstructionAt(a) == null) disassemble(a);
                    fn = createFunction(a, "orph_" + f[0]);
                }
                if (fn == null) { println("FAILED create at " + f[0]); bad++; continue; }
                if (!fn.getEntryPoint().equals(a)) { println("entry mismatch at " + f[0]); bad++; continue; }
                fn.setName("orph_" + f[0], ghidra.program.model.symbol.SourceType.USER_DEFINED);
                DecompileResults r = d.decompileFunction(fn, 120, new ConsoleTaskMonitor());
                String hex = Long.toHexString(a.getOffset());
                try (FileWriter fw = new FileWriter(new File(out, "0x" + hex + ".txt"))) {
                    fw.write("// Function: " + fn.getName(true) + " @ " + fn.getEntryPoint() + "\n// Signature: " + fn.getSignature() + "\n\n");
                    if (r != null && r.decompileCompleted()) fw.write(r.getDecompiledFunction().getC()); else fw.write("!! decompile failed\n");
                }
                idx.write("0x" + hex + "\t" + fn.getBody().getNumAddresses() + "\t" + fn.getName(true) + "\n");
                own.write("0x" + hex + "\t" + f[2] + "\n");
                ok++;
            }
            println("CreateOrphans: " + ok + " ok, " + bad + " failed");
        }
    }
}

