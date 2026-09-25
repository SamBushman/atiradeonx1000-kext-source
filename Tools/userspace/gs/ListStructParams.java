import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;
import ghidra.program.model.address.Address;
// ListStructParams.java OUT - functions with a by-value struct/union/tag parameter (<= 4 bytes) or a parameter with unassigned storage, and the
// entry points of every function that calls them (directly, or through a PIC stub/thunk of the same name)
public class ListStructParams extends GhidraScript {
    boolean bad(Parameter p) {
        DataType dt = p.getDataType();
        DataType base = dt instanceof TypeDef ? ((TypeDef) dt).getBaseDataType() : dt;
        boolean scalar = base instanceof Pointer || base instanceof AbstractIntegerDataType || base instanceof AbstractFloatDataType
                      || base instanceof Undefined || base instanceof ghidra.program.model.data.Enum || base instanceof DefaultDataType;
        return p.getVariableStorage().isUnassignedStorage() || ((!scalar || (dt instanceof TypeDef && dt.getLength() < 4)) && dt.getLength() <= 4 && !(dt instanceof Undefined4DataType));
    }
    public void run() throws Exception {
        String out = getScriptArgs()[0];
        Set<Function> targets = new LinkedHashSet<>();
        for (Function f : currentProgram.getFunctionManager().getFunctions(true))
            for (Parameter p : f.getParameters()) if (bad(p)) { targets.add(f); break; }
        Set<String> callers = new TreeSet<>();
        try (java.io.FileWriter w = new java.io.FileWriter(out)) {
            for (Function f : targets) {
                w.write("T\t0x" + Long.toHexString(f.getEntryPoint().getOffset()) + "\t" + f.getName() + "\n");
                for (Reference r : getReferencesTo(f.getEntryPoint())) {
                    if (!r.getReferenceType().isCall() && !r.getReferenceType().isJump()) continue;
                    Function c = getFunctionContaining(r.getFromAddress());
                    if (c != null) callers.add("0x" + Long.toHexString(c.getEntryPoint().getOffset()));
                }
                // callers of thunks (PIC stubs) of this function
                for (Address ta : f.getFunctionThunkAddresses(true) == null ? new Address[0] : f.getFunctionThunkAddresses(true))
                    for (Reference r : getReferencesTo(ta)) { Function c = getFunctionContaining(r.getFromAddress()); if (c != null) callers.add("0x" + Long.toHexString(c.getEntryPoint().getOffset())); }
            }
            for (String c : callers) w.write("C\t" + c + "\n");
        }
        println("LISTSP " + targets.size() + " functions with struct/tag/unassigned params, " + callers.size() + " callers");
    }
}
