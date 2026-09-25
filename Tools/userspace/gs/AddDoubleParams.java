import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.DoubleDataType;
import ghidra.program.model.listing.*;
import ghidra.program.model.listing.Function.FunctionUpdateType;
import ghidra.program.model.symbol.SourceType;
import java.util.*;

// Usage: -postScript AddDoubleParams.java <hexEntry>:<count>...
// Functions whose decompile reads an FPR argument it does not declare (`in_f1`) although every stock caller loads it before the call
// (Tools/userspace/inreg_liveness.py ... fpr: "callers set it N/N"). GLDriver FUN_000cdc3c formats the double in f1 with ecvt; its C read an
// uninitialised `in_f1` and no caller passed the value. Appends <count> double parameters after the existing (integer) ones: with the integers
// first, Ghidra's SysV storage and Darwin's agree (f1.., the GPRs a double shadows come after the integers). Run on a COPY, then RedumpContaining
// on the function and its callers.
public class AddDoubleParams extends GhidraScript {
    @Override
    public void run() throws Exception {
        for (String arg : getScriptArgs()) {
            String[] p = arg.split(":");
            Function f = getFunctionAt(toAddr(Long.parseLong(p[0].replace("0x", ""), 16)));
            if (f == null) { println("ADDDOUBLE no function at " + p[0]); continue; }
            List<Parameter> ps = new ArrayList<>();
            int nf = 0;
            for (Parameter q : f.getParameters()) {
                ps.add(new ParameterImpl(q.getName(), q.getDataType(), currentProgram, SourceType.USER_DEFINED));
                if (q.getDataType() instanceof ghidra.program.model.data.AbstractFloatDataType) nf++;
            }
            for (int i = nf; i < Integer.parseInt(p[1]); i++) ps.add(new ParameterImpl("fparam_" + (i + 1), DoubleDataType.dataType, currentProgram, SourceType.USER_DEFINED));
            f.updateFunction(f.getCallingConventionName(), f.getReturn(), ps, FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED);
            StringBuilder sb = new StringBuilder();
            for (Parameter q : f.getParameters()) sb.append(" ").append(q.getName()).append("@").append(q.getVariableStorage());
            println("ADDDOUBLE " + f.getName(true) + sb);
        }
    }
}
