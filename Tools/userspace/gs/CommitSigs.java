import ghidra.app.decompiler.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.pcode.*;
import ghidra.program.model.symbol.SourceType;
import ghidra.util.task.ConsoleTaskMonitor;
// CommitSigs.java - commit, for every internal function, the parameter list and return type that the decompiler itself shows for its body ("decompile"
// simplification style: params that are used), so callers print their register arguments. Without a committed signature the decompiler prints a call to an
// internal function as `f()`, dropping r3 (= this / a pointer just loaded) and the rest; Ghidra's "Decompiler Parameter ID" analyzer over-counts
// (it invents params 4..8 for functions that use three), so it is not used. Run on a COPY of the project, then DecompAll.java.
public class CommitSigs extends GhidraScript {
    public void run() throws Exception {
        DecompInterface d = new DecompInterface();
        DecompileOptions o = new DecompileOptions();
        o.setMaxPayloadMBytes(256); o.setMaxInstructions(2000000);
        d.setOptions(o);
        d.openProgram(currentProgram);
        d.setSimplificationStyle("decompile");
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        int n = 0, bad = 0;
        while (it.hasNext()) {
            Function f = it.next();
            if (f.isExternal() || f.isThunk()) continue;
            ghidra.program.model.mem.MemoryBlock mb = currentProgram.getMemory().getBlock(f.getEntryPoint());
            if (mb != null && mb.getName().toLowerCase().contains("stub")) continue;      // dyld import stubs keep an unknown signature: the decompiler then infers the call's arguments itself
            DecompileResults r = d.decompileFunction(f, 300, new ConsoleTaskMonitor());
            if (r == null || !r.decompileCompleted() || r.getHighFunction() == null) { bad++; println("NODECOMP " + f.getName() + " " + f.getEntryPoint()); continue; }
            try {
                HighFunctionDBUtil.commitParamsToDatabase(r.getHighFunction(), true, HighFunctionDBUtil.ReturnCommitOption.COMMIT, SourceType.ANALYSIS);
                n++;
            } catch (Exception e) { bad++; println("COMMITFAIL " + f.getName() + ": " + e); }
        }
        println("COMMITSIGS done " + n + " committed, " + bad + " not");
    }
}
