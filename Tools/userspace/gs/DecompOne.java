import ghidra.app.decompiler.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.util.task.ConsoleTaskMonitor;
import java.io.*;
// DecompOne.java OUT.txt HEXADDR [TIMEOUT_SECONDS] - decompile one function with a long timeout and report the decompiler's own error
public class DecompOne extends GhidraScript {
    public void run() throws Exception {
        String[] a = getScriptArgs();
        int to = a.length > 2 ? Integer.parseInt(a[2]) : 1200;
        DecompInterface d = new DecompInterface();
        DecompileOptions o = new DecompileOptions();
        o.setMaxPayloadMBytes(256); o.setMaxInstructions(2000000);
        d.setOptions(o);
        d.openProgram(currentProgram);
        Address ad = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(a[1]);
        Function f = getFunctionAt(ad);
        long t0 = System.currentTimeMillis();
        DecompileResults r = d.decompileFunction(f, to, new ConsoleTaskMonitor());
        try (FileWriter w = new FileWriter(a[0])) {
            w.write("// completed=" + r.decompileCompleted() + " timedout=" + r.isTimedOut() + " cancelled=" + r.isCancelled() + " ms=" + (System.currentTimeMillis() - t0) + "\n// error=" + r.getErrorMessage() + "\n");
            if (r.decompileCompleted()) w.write(r.getDecompiledFunction().getC());
        }
    }
}
