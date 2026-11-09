import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.pcode.*;
import ghidra.util.task.ConsoleTaskMonitor;
import java.io.*;
import java.util.*;

// Usage: -postScript ExtendIndirectCalls.java IN.txt OUT.txt
// IN.txt: `<callAddr>:<argCount>` lines from Tools/userspace/indirect_args.py (the GPR arguments the stock code gives each `bctrl`). Every indirect
// call the decompiler prints with FEWER arguments gets a call-site override with that many (OverrideIndirectCalls.java only widened calls printed
// with none: glprog changeAggrToTempConst's `getType(local_60)` lost the object in r4). A call with a float argument or result (an f register) is
// widened with the missing integer arguments only (the doubles are kept as double parameters); a float RESULT is left alone and listed. OUT.txt: the entries of the functions changed, for RedumpContaining.java.
public class ExtendIndirectCalls extends GhidraScript {
    FunctionDefinitionDataType sig(String name, int n, DataType ret) {
        FunctionDefinitionDataType s = new FunctionDefinitionDataType(name);
        ParameterDefinition[] ps = new ParameterDefinition[n];
        for (int i = 0; i < n; i++) ps[i] = new ParameterDefinitionImpl("a" + i, Undefined4DataType.dataType, null);
        s.setArguments(ps); s.setReturnType(ret);
        return s;
    }
    boolean isFloatReg(Varnode v) {
        if (v == null || !v.isRegister()) return false;
        ghidra.program.model.lang.Register r = currentProgram.getRegister(v.getAddress(), v.getSize());
        return r != null && r.getName().startsWith("f");
    }
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Map<Function, Map<Address, Integer>> want = new LinkedHashMap<>();
        for (String l : new BufferedReader(new FileReader(a[0])).lines().toArray(String[]::new)) {
            l = l.trim(); if (l.isEmpty() || l.startsWith("#")) continue;
            String[] p = l.split(":");
            Address ad = toAddr(Long.parseLong(p[0].replace("0x", ""), 16));
            Function f = getFunctionContaining(ad);
            if (f == null) continue;
            want.computeIfAbsent(f, k -> new HashMap<>()).put(ad, Integer.parseInt(p[1]));
        }
        DecompInterface dec = new DecompInterface(); dec.openProgram(currentProgram);
        PrintWriter out = new PrintWriter(new FileWriter(a[1]));
        int widened = 0, skipped = 0, funcs = 0;
        for (Map.Entry<Function, Map<Address, Integer>> e : want.entrySet()) {
            Function f = e.getKey();
            DecompileResults r = dec.decompileFunction(f, 600, new ConsoleTaskMonitor());
            HighFunction hf = r.getHighFunction();
            if (hf == null) { println("EXTENDIND no decompile " + f.getName()); continue; }
            boolean changed = false;
            Iterator<PcodeOpAST> it = hf.getPcodeOps();
            List<PcodeOpAST> calls = new ArrayList<>();
            while (it.hasNext()) { PcodeOpAST op = it.next(); if (op.getOpcode() == PcodeOp.CALLIND) calls.add(op); }
            for (PcodeOpAST op : calls) {
                Address ca = op.getSeqnum().getTarget();
                Integer n = e.getValue().get(ca);
                // the GPR arguments the call has: floating-point ones (an f register / float-typed value) travel in f1..f13 and do not count against the wanted GPR words;
                // a call that already has three doubles but not the object in r3 (`(*fn)(double,double,double)` for the stock's `bctrl` with r3 = ctx, f1..f3) is widened
                // with the missing integer arguments and keeps its floating-point ones (the override's integer parameters go to r3.., its doubles to f1..)
                int ng = 0; List<Integer> fsz = new ArrayList<>();
                for (int i = 1; i < op.getNumInputs(); i++) {
                    Varnode v = op.getInput(i);
                    HighVariable hv = v.getHigh();
                    if (isFloatReg(v) || (hv != null && hv.getDataType() instanceof AbstractFloatDataType)) fsz.add(v.getSize()); else ng++;
                }
                if (n == null || ng >= n) continue;
                boolean fret = isFloatReg(op.getOutput());
                if (fret) { println("EXTENDIND skip (float result) " + f.getName() + " " + ca + " " + ng + "->" + n); skipped++; continue; }
                DataType ret = op.getOutput() == null ? VoidDataType.dataType : Undefined4DataType.dataType;
                FunctionDefinitionDataType s = sig("ind_" + ca, n, ret);
                if (!fsz.isEmpty()) {
                    ParameterDefinition[] ps = new ParameterDefinition[n + fsz.size()];
                    ParameterDefinition[] gp = s.getArguments();
                    for (int i = 0; i < n; i++) ps[i] = gp[i];
                    for (int i = 0; i < fsz.size(); i++) ps[n + i] = new ParameterDefinitionImpl("f" + i, DoubleDataType.dataType, null);
                    s.setArguments(ps);
                }
                HighFunctionDBUtil.writeOverride(f, ca, s);
                widened++; changed = true;
            }
            if (changed) { out.println("0x" + f.getEntryPoint()); funcs++; }
        }
        out.close();
        println("EXTENDIND widened " + widened + " calls in " + funcs + " functions, skipped " + skipped + " (float)");
    }
}
