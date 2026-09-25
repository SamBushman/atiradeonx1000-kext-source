import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.Undefined4DataType;
import ghidra.program.model.listing.*;
import ghidra.program.model.listing.Function.FunctionUpdateType;
import ghidra.program.model.symbol.SourceType;
import java.util.*;

// Usage: -postScript ExtendParams.java <hexEntry>:<count>[:nofp]...
// Functions whose own decompile reads an argument register it does not declare (`in_r4`): TIntermAggregate::setName(const TString&) is
// `addi r3,r3,0x54; b assign` - it passes the caller's r4 straight on, but its committed signature had one parameter, so the C read an uninitialised
// `in_r4`. The parameter list is extended to <count> arguments (appended as undefined4 in r(3+i); existing parameters keep their types). The counts
// come from Tools/userspace/param_used.py: the registers stock callers really set, or - for a function reached only indirectly (virtual methods) -
// every register its body reads. The same script gives functions that read incoming stack arguments (`in_stack_00000038`: the 9th+ argument
// words, 0x38(r1) of the caller) the parameters up to the highest word read (Tools/userspace/pipeline/b3/stackparams_*.txt); `nofp` first drops
// the float parameters Ghidra invented from FPRs the body only writes (_InterpreterLoadSource had eleven). The storage of each new parameter is
// printed so the stack slots can be checked. Run on a COPY of the project, then RedumpContaining.java on the functions and their direct callers.
public class ExtendParams extends GhidraScript {
    @Override
    public void run() throws Exception {
        int n = 0;
        // every function of that name: the PIC stubs carry a copy of the signature and callers through a stub print with it
        Map<String, Integer> byName = new HashMap<>();
        Set<String> noFp = new HashSet<>();
        for (String arg : getScriptArgs()) {
            String[] p = arg.split(":");
            Function f0 = getFunctionAt(toAddr(Long.parseLong(p[0].replace("0x", ""), 16)));
            if (f0 != null) byName.put(f0.getName(), Integer.parseInt(p[1]));
            if (f0 != null && p.length > 2 && p[2].equals("nofp")) noFp.add(f0.getName());
        }
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            Integer wantI = byName.get(f.getName());
            if (wantI == null) continue;
            int want = wantI;
            boolean dropFp = noFp.contains(f.getName());
            List<Parameter> ps = new ArrayList<>();
            for (Parameter q : f.getParameters()) {
                if (dropFp && q.getDataType() instanceof ghidra.program.model.data.AbstractFloatDataType) continue;
                ps.add(new ParameterImpl(q.getName(), q.getDataType(), currentProgram, SourceType.USER_DEFINED));
            }
            boolean hasFp = false;
            for (Parameter q : ps) if (q.getDataType() instanceof ghidra.program.model.data.AbstractFloatDataType) hasFp = true;
            if (!hasFp && ps.size() >= want && ps.size() == f.getParameterCount()) continue;
            // with float parameters, <count> counts the GPR parameters and new ones go in front of the floats: Darwin gives an int after a double
            // the GPR the double shadows (FUN_00002ae0 = the driver's glAccum(ctx, op, value) reads r3, r4, f1 - Ghidra had (param_1, double))
            int nInt = 0, firstFp = -1;
            for (int i = 0; i < ps.size(); i++) {
                if (ps.get(i).getDataType() instanceof ghidra.program.model.data.AbstractFloatDataType) { if (firstFp < 0) firstFp = i; }
                else nInt++;
            }
            if (firstFp >= 0) {
                if (nInt >= want) continue;
                for (int i = nInt; i < want; i++) ps.add(firstFp++, new ParameterImpl("param_" + (i + 1), Undefined4DataType.dataType, currentProgram, SourceType.USER_DEFINED));
            } else
            for (int i = ps.size(); i < want; i++) ps.add(new ParameterImpl("param_" + (i + 1), Undefined4DataType.dataType, currentProgram, SourceType.USER_DEFINED));
            boolean allInt = true;
            for (Parameter q : ps) if (q.getDataType() instanceof ghidra.program.model.data.AbstractFloatDataType || q.getLength() > 4) allInt = false;
            if (want > 8 && allInt) {
                // Ghidra's PowerPC cspec is SysV: its 9th argument word is Stack[0x8] (the saved-LR slot). Darwin passes it at 0x38(r1) - after the
                // 24-byte linkage area and the 32-byte home area of r3-r10 - so the storage is given explicitly: r3-r10, then 0x38 + 4k.
                List<Parameter> cs = new ArrayList<>();
                for (int i = 0; i < ps.size(); i++) {
                    Parameter q = ps.get(i);
                    VariableStorage vs = i < 8 ? new VariableStorage(currentProgram, currentProgram.getRegister("r" + (3 + i)))
                                               : new VariableStorage(currentProgram, 0x38 + 4 * (i - 8), 4);
                    cs.add(new ParameterImpl(q.getName(), q.getDataType(), vs, currentProgram, SourceType.USER_DEFINED));
                }
                Parameter ret = f.getReturn();
                f.updateFunction(f.getCallingConventionName(), ret, cs, FunctionUpdateType.CUSTOM_STORAGE, true, SourceType.USER_DEFINED);
            } else
            f.updateFunction(f.getCallingConventionName(), f.getReturn(), ps, FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED);
            n++;
            StringBuilder sb = new StringBuilder();
            for (Parameter q : f.getParameters()) sb.append(" ").append(q.getName()).append("@").append(q.getVariableStorage());
            println("EXTENDPARAMS " + f.getName() + " @ " + f.getEntryPoint() + ":" + sb);
        }
        println("EXTENDPARAMS " + n + " functions extended");
    }
}
