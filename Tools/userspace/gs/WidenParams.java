import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.Undefined4DataType;
import ghidra.program.model.listing.*;
import ghidra.program.model.listing.Function.FunctionUpdateType;
import ghidra.program.model.symbol.SourceType;
import java.util.*;

// Usage: -postScript WidenParams.java <hexEntry>:<index>[,<index>...]...
// Parameters Ghidra typed narrower than their register (bool/char/short) although the function itself uses the whole register - its own decompile
// rebuilds it as `CONCAT31(in_register_0000000c, param_1)`. ParseOperand::GetAsSourceVar(bool) got the demangled `bool` on r3, which really carries
// the hidden struct-return pointer: every caller then printed that stack address cast to bool (`(bool)((char)&STACKARG(-0x90) + '@')`) and the
// rebuilt function wrote through 0xa0. The listed parameters become undefined4 (a full GPR); the others keep their types. Run on a COPY of the
// project, then RedumpContaining.java on the functions and their direct callers.
public class WidenParams extends GhidraScript {
    @Override
    public void run() throws Exception {
        int n = 0;
        // the PIC stubs carry a copy of the signature (CopySigToStubs) and callers through a stub print with it: widen every function of that name
        Map<String, Set<Integer>> byName = new HashMap<>();
        for (String arg : getScriptArgs()) {
            String[] p = arg.split(":");
            Function f0 = getFunctionAt(toAddr(Long.parseLong(p[0].replace("0x", ""), 16)));
            if (f0 == null) continue;
            Set<Integer> idx = new HashSet<>();
            for (String i : p[1].split(",")) idx.add(Integer.parseInt(i));
            byName.put(f0.getName(true), idx);   // namespace-qualified: TPPStreamCompiler::error must not widen TParseContext::error
        }
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            Set<Integer> idx = byName.get(f.getName(true).replaceFirst("^<EXTERNAL>::", ""));   // the function and its PIC stub
            if (idx == null) continue;
            List<Parameter> ps = new ArrayList<>();
            Parameter[] cur = f.getParameters();
            for (int i = 0; i < cur.length; i++)
                ps.add(new ParameterImpl(cur[i].getName(), idx.contains(i) ? Undefined4DataType.dataType : cur[i].getDataType(), currentProgram, SourceType.USER_DEFINED));
            f.updateFunction(f.getCallingConventionName(), f.getReturn(), ps, FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED);
            n++;
            println("WIDENPARAMS " + f.getName(true) + " @ " + f.getEntryPoint());
        }
        println("WIDENPARAMS " + n + " functions");
    }
}
