import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.listing.Function.FunctionUpdateType;
import ghidra.program.model.symbol.SourceType;
import java.util.*;

// Usage: -postScript FlattenStructParams.java <hexEntry>...
// libstdc++ template helpers take iterators (`__normal_iterator`, one pointer) and iterator tags (empty structs) BY VALUE. With those struct types in the
// committed signature the decompiler assigns the register storage of the call's arguments wrongly and says so ("WARNING: Heritage AFTER dead removal.
// Example location: r3 : <call>"): std::string(const char*) called _S_construct(strlen(s), end, ...) instead of (s, end, ...), and _S_create threw.
// For each given function - and every other function with the same name (the PIC stubs, which carry a copy of the signature) - every by-value
// structure/union parameter of 4 bytes or less becomes `undefined4` in the same argument slot (a 4-byte GPR on PowerPC). Run on a COPY of the
// project, then RedumpContaining.java on the callers.
public class FlattenStructParams extends GhidraScript {
    @Override
    public void run() throws Exception {
        Set<String> names = new HashSet<>();
        for (String arg : getScriptArgs()) {
            Function f = getFunctionAt(toAddr(Long.parseLong(arg.replace("0x", ""), 16)));
            if (f == null) { println("FLATTEN no function at " + arg); continue; }
            names.add(f.getName());
        }
        int nf = 0, np = 0;
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        while (it.hasNext()) {
            Function f = it.next();
            if (!names.contains(f.getName())) continue;
            Parameter[] ps = f.getParameters();
            List<Parameter> out = new ArrayList<>();
            boolean changed = false;
            for (Parameter p : ps) {
                DataType dt = p.getDataType();
                DataType base = dt instanceof TypeDef ? ((TypeDef) dt).getBaseDataType() : dt;
                boolean scalar = base instanceof Pointer || base instanceof AbstractIntegerDataType || base instanceof AbstractFloatDataType
                              || base instanceof Undefined || base instanceof ghidra.program.model.data.Enum || base instanceof DefaultDataType;
                // structs, unions, and the empty tag types (`forward_iterator_tag`: a 1-byte typedef whose parameter storage is UNASSIGNED - the actual
                // trigger of the heritage warning at every call of _S_construct<const char*>)
                boolean unassigned = p.getVariableStorage().isUnassignedStorage();
                if (((!scalar || (dt instanceof TypeDef && dt.getLength() < 4)) && dt.getLength() <= 4 && !(dt instanceof Undefined4DataType)) || unassigned) {
                    out.add(new ParameterImpl(p.getName(), Undefined4DataType.dataType, currentProgram, SourceType.USER_DEFINED));
                    changed = true; np++;
                } else {
                    out.add(new ParameterImpl(p.getName(), dt, currentProgram, SourceType.USER_DEFINED));
                }
            }
            if (!changed) continue;
            f.updateFunction(f.getCallingConventionName(), f.getReturn(), out, FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED);
            nf++;
            println("FLATTEN " + f.getEntryPoint() + " " + f.getName() + " -> " + f.getSignature().getPrototypeString());
        }
        println("FLATTEN " + nf + " functions, " + np + " by-value struct parameters flattened");
    }
}
