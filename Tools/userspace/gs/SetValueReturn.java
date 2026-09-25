import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.Undefined4DataType;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;

// Usage: -postScript SetValueReturn.java <hexEntry>...
// Give each function a 4-byte return value (Undefined4, user-defined, so the decompiler keeps it). For functions whose own decompile printed `void`
// although the stock machine code leaves the result in r3 at `blr` and the callers read it (`std::string::_Rep::_S_create` returns the new _Rep*):
// with the return type left `undefined` the decompiler's own inference dropped the value, and the C returned whatever r3 happened to hold at -O0.
// Run on a COPY of the project, then RedumpContaining.java with the same addresses.
public class SetValueReturn extends GhidraScript {
    @Override
    public void run() throws Exception {
        int n = 0;
        for (String arg : getScriptArgs()) {
            Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(arg.replace("0x", ""));
            Function f = getFunctionAt(a);
            if (f == null) { println("SETRET no function at " + arg); continue; }
            f.setReturnType(Undefined4DataType.dataType, SourceType.USER_DEFINED);
            n++;
        }
        println("SETRET " + n + " functions given a 4-byte return value");
    }
}
