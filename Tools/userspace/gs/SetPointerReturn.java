import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;

// Usage: -postScript SetPointerReturn.java <hexEntry>...
// Functions returning an object pointer whose callers' decompile typed the result `float` (GLDriver FUN_001043f0: FUN_00180830 kept the returned
// objects in float locals, so the C converted each pointer to a float value and back - 24 bits of mantissa). A `void *` return type outweighs the
// float inference. Run on a COPY, then RedumpContaining.java on the callers.
public class SetPointerReturn extends GhidraScript {
    @Override
    public void run() throws Exception {
        for (String a : getScriptArgs()) {
            Function f = getFunctionAt(toAddr(Long.parseLong(a.replace("0x", ""), 16)));
            if (f == null) continue;
            f.setReturnType(new PointerDataType(VoidDataType.dataType), SourceType.USER_DEFINED);
            println("PTRRET " + f.getName());
        }
    }
}
