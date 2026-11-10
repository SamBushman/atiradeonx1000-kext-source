import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.DataType;
import ghidra.program.model.data.DoubleDataType;
import ghidra.program.model.data.LongLongDataType;
import ghidra.program.model.data.VoidDataType;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Parameter;
import ghidra.program.model.listing.ParameterImpl;
import ghidra.program.model.symbol.SourceType;
import java.util.ArrayList;
import java.util.List;

// Usage: -postScript SetReturnType.java <double|longlong|void>:<hexEntry> ...
// Give a function the return type its stock callers read. Ghidra's PowerPC cspec returns an int in r3 only: a function whose result the callers take from f1 (a double) or from
// r3:r4 (a 64-bit value) had its return type left `undefined`, so every caller printed the value as an uninitialised `extraout_f1` / `extraout_r4` and the rebuilt caller used
// garbage. GLEngine: _gleMaterialShinePow / _gleLightExponentPow (callers read f1 right after the call: 20 sites) and ___ashldi3 (64-bit shift, callers read r4: 27 sites).
// `void`: the stock function computes no result (it ends in blr / a tail call with whatever the last callee left in r3 or f1) and no caller reads one; Ghidra's liveness-based signature
// (`undefined4` / `double`) made the decompiler return an unassigned `extraout_r3` / `extraout_f1` local, which the rebuilt code returns uninitialised and which stops gcc from tail-calling (GLEngine: 30 functions).
// Same machine code afterwards: only the callers' C changes. Existing parameters keep their types and storage. Run on a COPY of the project, then re-dump.
public class SetReturnType extends GhidraScript {
    @Override
    public void run() throws Exception {
        int n = 0;
        for (String arg : getScriptArgs()) {
            String[] p = arg.split(":");
            Function f = getFunctionAt(toAddr(Long.parseLong(p[1].replace("0x", ""), 16)));
            if (f == null) { println("SETRETURNTYPE no function at " + arg); continue; }
            DataType dt = p[0].equals("double") ? DoubleDataType.dataType : p[0].equals("longlong") ? LongLongDataType.dataType : p[0].equals("void") ? VoidDataType.dataType : null;
            if (dt == null) { println("SETRETURNTYPE unknown type " + p[0]); continue; }
            f.setReturnType(dt, SourceType.USER_DEFINED);
            println("SETRETURNTYPE " + f.getName() + " @ " + f.getEntryPoint() + " -> " + p[0] + " : " + f.getSignature().getPrototypeString());
            n++;
        }
        println("SETRETURNTYPE " + n + " functions");
    }
}
