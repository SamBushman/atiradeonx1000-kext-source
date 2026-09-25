import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.listing.Function.FunctionUpdateType;
import ghidra.program.model.pcode.*;
import ghidra.program.model.symbol.SourceType;
import ghidra.util.task.ConsoleTaskMonitor;
import java.util.*;

// Usage: -postScript ForwardArgs.java <hexEntry>:<count>...
// Functions that pass their callers' argument registers on, untouched, to a call through a pointer (a virtual call, a callback, a `bctr` through
// a lazy pointer): GLDriver FUN_000e1564(ctx, size) calls ctx->alloc(ctx->allocctx, size) with the caller's r4 - every one of its 20 stock callers
// loads the size - but its signature had one parameter and the indirect call's override (OverrideIndirectCalls.java: a caller's untouched input
// register is "not set") one argument, so the rebuilt C allocated a garbage size. Found by Tools/userspace/hidden_params.py (argument registers
// live at entry beyond the declared parameters that stock callers set, reaching an indirect call). The parameters are extended to <count> (GPRs
// r3..) and every indirect call in the function gets an override with at least <count> arguments (an extra argument is harmless, a missing one is
// not). Run on a COPY, then RedumpContaining.java on the functions and their callers.
public class ForwardArgs extends GhidraScript {
    FunctionDefinitionDataType sig(String name, int n) {
        FunctionDefinitionDataType s = new FunctionDefinitionDataType(name);
        ParameterDefinition[] ps = new ParameterDefinition[n];
        for (int i = 0; i < n; i++) ps[i] = new ParameterDefinitionImpl("a" + i, Undefined4DataType.dataType, null);
        s.setArguments(ps); s.setReturnType(Undefined4DataType.dataType);
        return s;
    }
    @Override
    public void run() throws Exception {
        DecompInterface dec = new DecompInterface(); dec.openProgram(currentProgram);
        for (String arg : getScriptArgs()) {
            String[] p = arg.split(":");
            Function f = getFunctionAt(toAddr(Long.parseLong(p[0].replace("0x", ""), 16)));
            int want = Integer.parseInt(p[1]);
            if (f == null) { println("FORWARD no function at " + p[0]); continue; }
            if (f.getParameterCount() < want) {
                List<Parameter> ps = new ArrayList<>();
                for (Parameter q : f.getParameters()) ps.add(new ParameterImpl(q.getName(), q.getDataType(), currentProgram, SourceType.USER_DEFINED));
                for (int i = ps.size(); i < want; i++) ps.add(new ParameterImpl("param_" + (i + 1), Undefined4DataType.dataType, currentProgram, SourceType.USER_DEFINED));
                f.updateFunction(f.getCallingConventionName(), f.getReturn(), ps, FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED);
            }
            DecompileResults r = dec.decompileFunction(f, 600, new ConsoleTaskMonitor());
            HighFunction hf = r.getHighFunction();
            if (hf == null) { println("FORWARD no decompile " + f.getName()); continue; }
            StringBuilder sb = new StringBuilder();
            Iterator<PcodeOpAST> it = hf.getPcodeOps();
            List<PcodeOpAST> calls = new ArrayList<>();
            while (it.hasNext()) { PcodeOpAST op = it.next(); if (op.getOpcode() == PcodeOp.CALLIND) calls.add(op); }
            for (PcodeOpAST op : calls) {
                Address a = op.getSeqnum().getTarget();
                int n = Math.max(op.getNumInputs() - 1, want);
                HighFunctionDBUtil.writeOverride(f, a, sig("fwd_" + a, n));
                sb.append(" ").append(a).append(":").append(op.getNumInputs() - 1).append("->").append(n);
            }
            println("FORWARD " + f.getName() + " params=" + f.getParameterCount() + sb);
        }
    }
}
