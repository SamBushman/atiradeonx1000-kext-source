import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.UnsignedIntegerDataType;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;

// Usage: -postScript RetypeParams.java <hexEntry>:<firstIndex>...
// Retypes the parameters from <firstIndex> on to `uint` (what ForwardArgs.java now creates): in an `undefined4` slot Ghidra prints a constant
// argument that equals an address as that symbol - FUN_000e1564's allocation size 0x1740 became `FUN_00001740`. Run on a COPY, then
// RedumpContaining.java on the callers.
public class RetypeParams extends GhidraScript {
    @Override
    public void run() throws Exception {
        for (String arg : getScriptArgs()) {
            String[] p = arg.split(":");
            Function f = getFunctionAt(toAddr(Long.parseLong(p[0].replace("0x", ""), 16)));
            if (f == null) continue;
            Parameter[] ps = f.getParameters();
            for (int i = Integer.parseInt(p[1]); i < ps.length; i++) ps[i].setDataType(UnsignedIntegerDataType.dataType, SourceType.USER_DEFINED);
            println("RETYPE " + f.getName() + " from " + p[1]);
        }
    }
}
