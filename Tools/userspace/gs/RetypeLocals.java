import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.pcode.*;
import ghidra.program.model.symbol.SourceType;
import ghidra.util.task.ConsoleTaskMonitor;
import java.util.*;

// Usage: -postScript RetypeLocals.java <hexEntry>:<var>=<type>[,<var>=<type>...]...   (type: uint | uint* | ptr)
// Decompiler locals Ghidra typed `float` although they hold object pointers: GLDriver FUN_00180830 keeps its object list in a `float *` (pfVar5)
// and the pointers FUN_001043f0 returns in `float` locals, so the C converted every pointer to a float value and back (`fVar7 =
// (float)FUN_001043f0(...)`, `*(undefined4 *)((int)fVar7 + 0x98) = 0` - 24 bits of mantissa). The listed locals are committed with the given type
// (HighFunctionDBUtil) so the decompile treats them as words. Run on a COPY, then RedumpContaining.java on the functions.
public class RetypeLocals extends GhidraScript {
    DataType type(String t) {
        if (t.equals("uint")) return UnsignedIntegerDataType.dataType;
        if (t.equals("uint*")) return new PointerDataType(UnsignedIntegerDataType.dataType);
        return new PointerDataType(VoidDataType.dataType);
    }
    @Override
    public void run() throws Exception {
        DecompInterface dec = new DecompInterface(); dec.openProgram(currentProgram);
        for (String arg : getScriptArgs()) {
            String[] p = arg.split(":", 2);
            Function f = getFunctionAt(toAddr(Long.parseLong(p[0].replace("0x", ""), 16)));
            if (f == null) { println("RETYPELOCAL no function " + p[0]); continue; }
            Map<String, String> want = new HashMap<>();
            for (String kv : p[1].split(",")) { String[] q = kv.split("="); want.put(q[0], q[1]); }
            // commit one at a time: names can shift after each change, so decompile again for every variable
            for (Map.Entry<String, String> e : want.entrySet()) {
                DecompileResults r = dec.decompileFunction(f, 600, new ConsoleTaskMonitor());
                HighFunction hf = r.getHighFunction();
                if (hf == null) break;
                HighSymbol hs = null;
                Iterator<HighSymbol> it = hf.getLocalSymbolMap().getSymbols();
                while (it.hasNext()) { HighSymbol s = it.next(); if (s.getName().equals(e.getKey())) hs = s; }
                if (hs == null) { println("RETYPELOCAL " + f.getName() + ": no local " + e.getKey()); continue; }
                HighFunctionDBUtil.updateDBVariable(hs, null, type(e.getValue()), SourceType.USER_DEFINED);
                println("RETYPELOCAL " + f.getName() + " " + e.getKey() + " -> " + e.getValue());
            }
        }
    }
}
