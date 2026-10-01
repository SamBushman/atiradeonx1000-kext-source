import ghidra.app.decompiler.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.util.task.ConsoleTaskMonitor;
import java.io.*;
import java.nio.file.*;
import java.util.List;
// DecompList.java OUTDIR LISTFILE [TIMEOUT_S] - decompile every function whose hex entry address is listed (one per line) into OUTDIR/0x<addr>.txt
// (the format Tools/port_fn.py / replace_fn.py read as $SCRATCH/work/0xADDR.txt); a failure writes a "// completed=false" header instead.
public class DecompList extends GhidraScript {
    public void run() throws Exception {
        String[] a = getScriptArgs();
        int to = a.length > 2 ? Integer.parseInt(a[2]) : 600;
        new File(a[0]).mkdirs();
        DecompInterface d = new DecompInterface();
        DecompileOptions o = new DecompileOptions(); o.setMaxPayloadMBytes(256); o.setMaxInstructions(2000000);
        d.setOptions(o); d.openProgram(currentProgram);
        List<String> lines = Files.readAllLines(Paths.get(a[1]));
        for (String l : lines) {
            l = l.trim(); if (l.isEmpty()) continue;
            Address ad = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(l);
            Function f = getFunctionAt(ad);
            String name = "0x" + Long.toHexString(ad.getOffset()) + ".txt";
            try (FileWriter w = new FileWriter(new File(a[0], name))) {
                if (f == null) { w.write("// completed=false error=no function at " + l + "\n"); continue; }
                DecompileResults r = d.decompileFunction(f, to, new ConsoleTaskMonitor());
                w.write("// completed=" + r.decompileCompleted() + " timedout=" + r.isTimedOut() + "\n// error=" + r.getErrorMessage() + "\n");
                if (r.decompileCompleted()) w.write(r.getDecompiledFunction().getC());
            }
        }
    }
}
