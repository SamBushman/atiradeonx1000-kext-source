import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.ParameterImpl;
import ghidra.program.model.pcode.*;
import ghidra.program.model.symbol.SourceType;
import ghidra.util.task.ConsoleTaskMonitor;
import java.util.*;
import java.util.regex.*;

// Usage: -postScript OverrideVariadicCalls.java <hexEntry>...
// printf-family calls print only the variadic arguments the decompiler can prove, so a call such as sprintf(buf, "%d:%d", line, column) came out as
// sprintf(buf, "%d:%d", line) - the column register (r6, set by the caller) was dropped. For every call in the given functions to one of the functions
// below whose format argument is a literal string, this writes a call-site signature override (the "Override Signature" of the listing) with exactly
// the arguments the format consumes: `int` for integer/pointer/char conversions, `double` for e/f/g (FPRs). Run on a COPY of the project, then
// RedumpContaining.java with the same entries.
public class OverrideVariadicCalls extends GhidraScript {
    static final Map<String, Integer> FMT_INDEX = new HashMap<>();
    static {
        FMT_INDEX.put("printf", 0); FMT_INDEX.put("_printf", 0);
        FMT_INDEX.put("sprintf", 1); FMT_INDEX.put("_sprintf", 1);
        FMT_INDEX.put("fprintf", 1); FMT_INDEX.put("_fprintf", 1);
        FMT_INDEX.put("snprintf", 2); FMT_INDEX.put("_snprintf", 2);
        FMT_INDEX.put("syslog", 1); FMT_INDEX.put("_syslog", 1);
        FMT_INDEX.put("asprintf", 1); FMT_INDEX.put("_asprintf", 1);
    }
    static final Pattern CONV = Pattern.compile("%(?!%)[-+ #0]*(\\*|\\d*)(?:\\.(\\*|\\d+))?(hh|h|ll|l|L|q|z|j|t)?([diouxXeEfgGcspn])");

    String readCString(Address a) throws Exception {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 4096; i++) { byte b = getByte(a.add(i)); if (b == 0) break; sb.append((char) (b & 0xff)); }
        return sb.toString();
    }
    Address constAddr(Varnode v) {
        if (v == null) return null;
        if (v.isConstant()) return toAddr(v.getOffset());
        PcodeOp d = v.getDef();
        if (d == null) return null;
        int oc = d.getOpcode();
        if (oc == PcodeOp.COPY || oc == PcodeOp.CAST) return constAddr(d.getInput(0));
        if (oc == PcodeOp.PTRSUB && d.getInput(0).isConstant() && d.getInput(0).getOffset() == 0 && d.getInput(1).isConstant()) return toAddr(d.getInput(1).getOffset());
        return null;
    }
    @Override
    public void run() throws Exception {
        DecompInterface dec = new DecompInterface();
        dec.openProgram(currentProgram);
        int nCalls = 0, nOver = 0;
        for (String arg : getScriptArgs()) {
            Function f = getFunctionAt(toAddr(Long.parseLong(arg.replace("0x", ""), 16)));
            if (f == null) { println("OVERRIDEVA no function at " + arg); continue; }
            DecompileResults r = dec.decompileFunction(f, 600, new ConsoleTaskMonitor());
            HighFunction hf = r.getHighFunction();
            if (hf == null) { println("OVERRIDEVA decompile failed " + f.getName()); continue; }
            Iterator<PcodeOpAST> it = hf.getPcodeOps();
            List<Object[]> todo = new ArrayList<>();
            while (it.hasNext()) {
                PcodeOpAST op = it.next();
                if (op.getOpcode() != PcodeOp.CALL) continue;
                Function callee = getFunctionAt(op.getInput(0).getAddress());
                if (callee == null) continue;
                Function real = callee.isThunk() ? callee.getThunkedFunction(true) : callee;
                Integer fi = FMT_INDEX.get(real.getName());
                if (fi == null) continue;
                nCalls++;
                Address fa = constAddr(op.getNumInputs() > 1 + fi ? op.getInput(1 + fi) : null);
                if (fa == null) { println("OVERRIDEVA " + f.getName() + " call at " + op.getSeqnum().getTarget() + ": format not a literal"); continue; }
                String fmt = readCString(fa);
                List<DataType> extra = new ArrayList<>();
                Matcher m = CONV.matcher(fmt);
                while (m.find()) {
                    if ("*".equals(m.group(1))) extra.add(IntegerDataType.dataType);
                    if ("*".equals(m.group(2))) extra.add(IntegerDataType.dataType);
                    char c = m.group(4).charAt(0);
                    boolean ll = "ll".equals(m.group(3)) || "q".equals(m.group(3));
                    if ("eEfgG".indexOf(c) >= 0) extra.add(DoubleDataType.dataType);
                    else if (ll) extra.add(LongLongDataType.dataType);
                    else extra.add(IntegerDataType.dataType);
                }
                int given = op.getNumInputs() - 2 - fi;
                if (given >= extra.size()) continue;
                todo.add(new Object[] { op.getSeqnum().getTarget(), real, fi, extra, fmt, given });
            }
            for (Object[] t : todo) {
                Address call = (Address) t[0]; Function real = (Function) t[1]; int fi = (Integer) t[2];
                @SuppressWarnings("unchecked") List<DataType> extra = (List<DataType>) t[3];
                FunctionDefinitionDataType sig = new FunctionDefinitionDataType(real.getName() + "_at_" + call.toString());
                List<ParameterDefinition> ps = new ArrayList<>();
                PointerDataType cp = new PointerDataType(CharDataType.dataType);
                for (int i = 0; i < fi; i++) ps.add(new ParameterDefinitionImpl("p" + i, i == 0 && fi > 0 && !real.getName().contains("snprintf") && !real.getName().contains("printf") ? IntegerDataType.dataType : cp, null));
                if (real.getName().contains("fprintf")) ps.set(0, new ParameterDefinitionImpl("stream", new PointerDataType(VoidDataType.dataType), null));
                if (real.getName().contains("snprintf")) ps.set(1, new ParameterDefinitionImpl("size", UnsignedLongDataType.dataType, null));
                ps.add(new ParameterDefinitionImpl("format", cp, null));
                for (int i = 0; i < extra.size(); i++) ps.add(new ParameterDefinitionImpl("a" + i, extra.get(i), null));
                sig.setArguments(ps.toArray(new ParameterDefinition[0]));
                sig.setReturnType(IntegerDataType.dataType);
                sig.setVarArgs(false);
                HighFunctionDBUtil.writeOverride(f, call, sig);
                nOver++;
                println("OVERRIDEVA " + f.getName() + " " + call + " " + real.getName() + " \"" + t[4] + "\" args " + t[5] + " -> " + extra.size());
            }
        }
        println("OVERRIDEVA " + nCalls + " printf-family calls seen, " + nOver + " overridden");
    }
}
