import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.Undefined4DataType;
import ghidra.program.model.listing.*;
import ghidra.program.model.listing.Function.FunctionUpdateType;
import ghidra.program.model.symbol.SourceType;
import java.util.*;

// Usage: -postScript ExtendParams.java <hexEntry>:<count>...
// Functions whose own decompile reads an argument register it does not declare (`in_r4`): TIntermAggregate::setName(const TString&) is
// `addi r3,r3,0x54; b assign` - it passes the caller's r4 straight on, but its committed signature had one parameter, so the C read an uninitialised
// `in_r4`. The parameter list is extended to <count> arguments (appended as undefined4 in r(3+i); existing parameters keep their types). The counts
// come from Tools/userspace/param_used.py: the registers stock callers really set, or - for a function reached only indirectly (virtual methods) -
// every register its body reads. Run on a COPY of the project, then RedumpContaining.java on the functions and their direct callers.
public class ExtendParams extends GhidraScript {
    @Override
    public void run() throws Exception {
        int n = 0;
        // every function of that name: the PIC stubs carry a copy of the signature and callers through a stub print with it
        Map<String, Integer> byName = new HashMap<>();
        for (String arg : getScriptArgs()) {
            String[] p = arg.split(":");
            Function f0 = getFunctionAt(toAddr(Long.parseLong(p[0].replace("0x", ""), 16)));
            if (f0 != null) byName.put(f0.getName(), Integer.parseInt(p[1]));
        }
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            Integer wantI = byName.get(f.getName());
            if (wantI == null) continue;
            int want = wantI;
            if (f.getParameterCount() >= want) continue;
            List<Parameter> ps = new ArrayList<>();
            for (Parameter q : f.getParameters()) ps.add(new ParameterImpl(q.getName(), q.getDataType(), currentProgram, SourceType.USER_DEFINED));
            for (int i = f.getParameterCount(); i < want; i++) ps.add(new ParameterImpl("param_" + (i + 1), Undefined4DataType.dataType, currentProgram, SourceType.USER_DEFINED));
            f.updateFunction(f.getCallingConventionName(), f.getReturn(), ps, FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED);
            n++;
        }
        println("EXTENDPARAMS " + n + " functions extended");
    }
}
