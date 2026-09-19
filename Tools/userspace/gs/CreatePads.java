import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.util.task.ConsoleTaskMonitor;
import java.io.*;
import java.util.*;

// Usage: -postScript CreatePads.java <pads.tsv (start end owner)> <outDir>
// Creates a function (eh_pad_<addr>) at each C++ exception landing pad start, decompiles it into <outDir>/0x<addr>.txt (+ INDEX.tsv, PADOWNERS.tsv).
public class CreatePads extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        File out = new File(args[1]); out.mkdirs();
        // _Unwind_Resume never returns: without this the flow (and the decompile) runs on into the owner function's following code
        int nr = 0;
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            String n = f.getName();
            if (n.contains("Unwind_Resume")) { f.setNoReturn(true); nr++; if (f.isThunk() && f.getThunkedFunction(true) != null) f.getThunkedFunction(true).setNoReturn(true); }
        }
        println("noreturn set on " + nr + " Unwind_Resume functions");
        ArrayList<Function> old = new ArrayList<>();
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) if (f.getName().startsWith("eh_pad_")) old.add(f);
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
                if (fn != null && fn.getName().startsWith("eh_pad_")) { removeFunction(fn); fn = null; }   // recreate with the noreturn flow
                if (fn == null) {
                    if (getInstructionAt(a) == null) disassemble(a);
                    fn = createFunction(a, "eh_pad_" + f[0]);
                }
                if (fn == null) { println("FAILED create at " + f[0]); bad++; continue; }
                if (!fn.getEntryPoint().equals(a)) { println("entry mismatch at " + f[0]); bad++; continue; }
                fn.setName("eh_pad_" + f[0], ghidra.program.model.symbol.SourceType.USER_DEFINED);
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
            println("CreatePads: " + ok + " ok, " + bad + " failed");
        }
    }
}
