import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.AbstractFloatDataType;
import ghidra.program.model.data.DataType;
import ghidra.program.model.listing.*;
import ghidra.program.model.listing.Function.FunctionUpdateType;
import ghidra.program.model.symbol.SourceType;
import java.util.*;

// Usage: -postScript DarwinStorage.java [apply]
// Ghidra's PowerPC cspec is SysV: GPR and FPR arguments are counted separately and the 9th FPR argument goes to the stack. Darwin's PPC ABI
// gives every argument a slot in the GPR sequence as well - a float takes one word, a double two (the GPRs it shadows are skipped) - and passes
// f1..f13 in registers. So a signature with an integer after a float, or more than 8 float arguments, has the wrong storage: GLDriver's
// `ecvt(double, int, int*, int*)` call passed ndigit/decpt/sign in r3/r4/r5 where the stock passes them in r5/r6/r7, and the decompiler never saw
// &decpt/&sign reach the call (the minus sign and the negative-exponent path of the caller were pruned as unreachable).
// Lists every function (imports and PIC stubs included) whose storage differs from the Darwin assignment; with `apply`, rewrites it
// (CUSTOM_STORAGE, types and names unchanged). Run on a COPY of the project, then RedumpContaining.java on the callers.
public class DarwinStorage extends GhidraScript {
    @Override
    public void run() throws Exception {
        boolean apply = getScriptArgs().length > 0 && getScriptArgs()[0].equals("apply");
        int n = 0, applied = 0;
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            Parameter[] ps = f.getParameters();
            if (ps.length == 0) continue;
            boolean hasFp = false;
            for (Parameter p : ps) if (p.getDataType() instanceof AbstractFloatDataType) hasFp = true;
            if (!hasFp) continue;
            List<Parameter> out = new ArrayList<>();
            int g = 0, fr = 0; boolean differs = false, intMoved = false; StringBuilder sb = new StringBuilder();
            for (Parameter p : ps) {
                DataType dt = p.getDataType(); int len = Math.max(4, dt.getLength());
                VariableStorage vs;
                if (dt instanceof AbstractFloatDataType) {
                    if (fr < 13) vs = new VariableStorage(currentProgram, currentProgram.getRegister("f" + (1 + fr)));
                    else vs = new VariableStorage(currentProgram, 0x38 + 4 * g, dt.getLength());
                    fr++; g += (len + 3) / 4;
                } else if (len <= 4) {
                    vs = g < 8 ? new VariableStorage(currentProgram, currentProgram.getRegister("r" + (3 + g))) : new VariableStorage(currentProgram, 0x38 + 4 * g, 4);
                    g++;
                } else { differs = false; out = null; break; }   // 64-bit integers / structs: left alone
                if (!vs.equals(p.getVariableStorage())) { differs = true; if (!(dt instanceof AbstractFloatDataType)) intMoved = true; }
                sb.append(" ").append(p.getName()).append(":").append(p.getVariableStorage()).append("->").append(vs);
                out.add(new ParameterImpl(p.getName(), dt, vs, currentProgram, SourceType.USER_DEFINED));
            }
            if (out == null || !differs) continue;
            n++;
            println("DARWIN " + f.getEntryPoint() + " " + f.getName(true) + sb);
            // only an integer argument in the wrong register changes what callers pass; float-only differences (fparam_9..13 that Ghidra put on the
            // SysV stack) are listed, not applied - they are never read (Userspace/README.md)
            if (apply && intMoved) { f.updateFunction(f.getCallingConventionName(), f.getReturn(), out, FunctionUpdateType.CUSTOM_STORAGE, true, SourceType.USER_DEFINED); applied++; }
        }
        println("DARWIN " + n + " functions differ, " + applied + " rewritten");
    }
}
