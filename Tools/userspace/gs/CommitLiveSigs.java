import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.*;
import ghidra.program.model.pcode.*;
import ghidra.program.model.symbol.*;
import java.util.*;

// CommitLiveSigs.java - give every internal function a signature derived from its MACHINE CODE, then let the decompiler print calls with it.
//
// Ghidra's own signature recovery is unreliable on this code (a function that returns calloc()'s result is `void f(void)`, a wrapper that forwards its argument
// registers to a callee has fewer parameters than it really passes), and an unknown signature makes the decompiler DROP the register arguments of a call. Here:
//   parameters = the argument registers r3..r10 / f1..f13 that some path reads before writing (upward-exposed reads), closed over calls and tail jumps: a
//                register the function passes on untouched to a callee that reads it is the function's own parameter (pass-through);
//   return     = a value when some path to a `blr` has written r3 (or f1), closed over tail jumps.
// With an OLD_DUMP_DIR argument only the functions that the old dump shows being CALLED WITHOUT ARGUMENTS (`f();`) are committed: a committed signature changes how
// the decompiler prints every other call in the callers, sometimes for the worse (an import's third argument disappeared), so the change is kept as small as the
// defect. __thiscall methods are left to ghidra2c (the omitted object argument is the caller's own `this`).
// Indirect calls (bctrl) are not assumed to read anything. Stubs/externals/thunks keep an unknown signature. Run on a COPY of the project, then DecompAll.java.
public class CommitLiveSigs extends GhidraScript {
    static final int NI = 8, NF = 13;      // r3..r10, f1..f13
    Map<Function, boolean[]> liveIn = new HashMap<>();     // [0..7] r3..r10, [8..20] f1..f13
    Map<Function, boolean[]> retInfo = new HashMap<>();    // [0] returns r3, [1] returns f1
    List<Function> funcs = new ArrayList<>();

    int argIndex(Register r) {
        if (r == null) return -1;
        String n = r.getBaseRegister().getName();
        if (r.getName().length() >= 2 && r.getName().charAt(0) == 'f' && Character.isDigit(r.getName().charAt(1))) n = r.getName();   // f4's base register is the VSX register vs4
        try {
            if (n.length() >= 2 && n.charAt(0) == 'r') { int k = Integer.parseInt(n.substring(1)); if (k >= 3 && k <= 10) return k - 3; }
            if (n.length() >= 2 && n.charAt(0) == 'f' && Character.isDigit(n.charAt(1))) { int k = Integer.parseInt(n.substring(1)); if (k >= 1 && k <= NF) return NI + k - 1; }
        } catch (NumberFormatException e) {}
        return -1;
    }
    Register regOf(Varnode v) { return v.isRegister() ? currentProgram.getRegister(v.getAddress(), v.getSize()) : null; }

    boolean isStub(Function f) {
        ghidra.program.model.mem.MemoryBlock mb = currentProgram.getMemory().getBlock(f.getEntryPoint());
        return mb != null && mb.getName().toLowerCase().contains("stub");
    }
    Function target(Function caller, Address to) {
        Function c = currentProgram.getFunctionManager().getFunctionAt(to);
        if (c == null) return null;
        if (c.isThunk()) { Function e = c.getThunkedFunction(true); Function in = e == null ? null : internalByName.get(e.getName()); return in; }
        return c;
    }
    Map<String, Function> internalByName = new HashMap<>();
    String dbg = null;

    // analyse one function; returns true if liveIn/retInfo changed
    boolean analyse(Function f) throws Exception {
        Listing L = currentProgram.getListing();
        List<Instruction> ins = new ArrayList<>();
        InstructionIterator it = L.getInstructions(f.getBody(), true);
        while (it.hasNext()) ins.add(it.next());
        if (ins.isEmpty()) return false;
        Map<Address, Integer> idx = new HashMap<>();
        for (int i = 0; i < ins.size(); i++) idx.put(ins.get(i).getAddress(), i);
        int W = NI + NF;
        BitSet[] unwritten = new BitSet[ins.size()];     // regs possibly still holding their incoming value before instruction i
        BitSet[] r3w = new BitSet[ins.size()];           // bit0: r3 possibly written, bit1: f1 possibly written
        Deque<Integer> work = new ArrayDeque<>();
        BitSet all = new BitSet(W); all.set(0, W);
        unwritten[0] = (BitSet) all.clone(); r3w[0] = new BitSet(2);
        work.add(0);
        boolean[] live = liveIn.get(f), oldLive = live.clone();
        boolean[] ret = retInfo.get(f), oldRet = ret.clone();
        while (!work.isEmpty()) {
            int i = work.poll();
            Instruction in = ins.get(i);
            BitSet u = (BitSet) unwritten[i].clone(), rw = (BitSet) r3w[i].clone();
            // reads / writes from pcode
            BitSet writes = new BitSet(W); boolean r3Write = false, f1Write = false;
            for (PcodeOp op : in.getPcode()) {
                for (Varnode v : op.getInputs()) { int a = argIndex(regOf(v)); if (a >= 0 && u.get(a)) live[a] = true; }
                Varnode o = op.getOutput();
                if (o != null) { Register r = regOf(o); int a = argIndex(r); if (a >= 0) writes.set(a); if (r != null && r.getBaseRegister().getName().equals("r3")) r3Write = true; if (r != null && r.getName().equals("f1")) f1Write = true; }
            }
            FlowType ft = in.getFlowType();
            if (dbg != null && f.getName().equals(dbg)) println("DBG " + in.getAddress() + " " + in + " ft=" + ft + " flows=" + Arrays.toString(in.getFlows()));
            Function callee = null;
            boolean isCall = ft.isCall(), isTail = false;
            Address tgt = null;
            if (ft.isCall() || ft.isJump()) {
                for (Address fl : in.getFlows()) {
                    Function c = target(f, fl);
                    if (ft.isCall() && !ft.isConditional()) { callee = c != null ? c : callee; tgt = fl; }
                    else if (ft.isJump() && !f.getBody().contains(fl)) {
                        callee = c; isTail = true;      // an unconditional jump out of the function body: a tail call (imports and stubs included)
                    }
                }
            }
            if (ft.isCall() && ft.isTerminal()) { isTail = true; isCall = false; }          // `b other` recognised as a call+terminator: a tail call
            // call: the callee reads its live-in argument registers (if they still hold our incoming values, they are our parameters)
            if (callee != null && liveIn.containsKey(callee)) {
                boolean[] cl = liveIn.get(callee);
                for (int a = 0; a < W; a++) if (cl[a] && u.get(a)) live[a] = true;
            }
            if (isCall) {
                // volatile registers are clobbered by the call (r3..r10, f1..f13 all become "written"); r3 / f1 then hold the callee's result
                for (int a = 0; a < W; a++) u.clear(a);
                rw.set(0);                     // a call leaves something in r3 (a floating-point result would need the callee's own signature: not assumed)
            }
            for (int a = writes.nextSetBit(0); a >= 0; a = writes.nextSetBit(a + 1)) u.clear(a);
            if (r3Write) rw.set(0);
            if (f1Write) rw.set(1);
            // return points
            boolean isRet = ft.isTerminal() && !ft.isJump() && !ft.isCall();
            if (isRet) { if (rw.get(0)) ret[0] = true; if (rw.get(1)) ret[1] = true; }
            if (isTail) {
                // a tail jump to another function returns whatever that function returns; a target that is not analysed (an import stub, an external) is assumed to return a value
                boolean[] cr = callee == null ? null : retInfo.get(callee);
                if (cr == null) ret[0] = true; else { if (cr[0]) ret[0] = true; if (cr[1]) ret[1] = true; }
            }
            // successors
            List<Address> succ = new ArrayList<>();
            if (!isTail) {
                if (in.getFallThrough() != null && !(ft.isTerminal() && !ft.isConditional() && !ft.isCall())) succ.add(in.getFallThrough());
                if (ft.isJump() || ft.isConditional()) for (Address fl : in.getFlows()) if (f.getBody().contains(fl)) succ.add(fl);
                if (ft.isCall() && in.getFallThrough() != null && !succ.contains(in.getFallThrough())) succ.add(in.getFallThrough());
                if (ft.isJump() && in.getFlows().length == 0) { /* computed jump: switch targets recovered by overrides */ 
                    for (Reference r : in.getReferencesFrom()) if (r.getReferenceType().isJump() && f.getBody().contains(r.getToAddress())) succ.add(r.getToAddress()); }
            }
            for (Address s : succ) {
                Integer j = idx.get(s);
                if (j == null) continue;
                boolean changed = false;
                if (unwritten[j] == null) { unwritten[j] = (BitSet) u.clone(); r3w[j] = (BitSet) rw.clone(); changed = true; }
                else {
                    BitSet nu = (BitSet) unwritten[j].clone(); nu.or(u); BitSet nr = (BitSet) r3w[j].clone(); nr.or(rw);
                    if (!nu.equals(unwritten[j]) || !nr.equals(r3w[j])) { unwritten[j] = nu; r3w[j] = nr; changed = true; }
                }
                if (changed) work.add(j);
            }
        }
        return !Arrays.equals(oldLive, live) || !Arrays.equals(oldRet, ret);
    }

    public void run() throws Exception {
        if (getScriptArgs().length > 1) dbg = getScriptArgs()[1];
        FunctionIterator fi = currentProgram.getFunctionManager().getFunctions(true);
        Set<String> dup = new HashSet<>();
        while (fi.hasNext()) {
            Function f = fi.next();
            if (f.isExternal() || f.isThunk() || isStub(f)) continue;
            String n = f.getName();
            if (n.startsWith("case_") || n.startsWith("orph_") || n.startsWith("eh_pad_")) { /* still analysed: they call/are called */ }
            funcs.add(f);
            liveIn.put(f, new boolean[NI + NF]); retInfo.put(f, new boolean[2]);
            if (internalByName.containsKey(n)) dup.add(n);
            internalByName.put(n, f);
        }
        for (String d : dup) internalByName.remove(d);
        int rounds = 0; boolean changed = true;
        while (changed && rounds < 30) {
            changed = false; rounds++;
            for (Function f : funcs) changed |= analyse(f);
            println("ROUND " + rounds + " changed=" + changed);
        }
        Set<String> only = null;
        String[] args = getScriptArgs();
        boolean extend = args.length > 0 && args[0].equals("EXTEND");
        if (extend) args = new String[0];
        if (args.length > 0) {
            only = new HashSet<>();
            java.util.regex.Pattern pat = java.util.regex.Pattern.compile("(?<![\\w:.>])([A-Za-z_~][\\w:~<>,*]*)\\(\\);");
            for (java.io.File df : new java.io.File(args[0]).listFiles()) {
                if (!df.getName().startsWith("0x")) continue;
                String txt = new String(java.nio.file.Files.readAllBytes(df.toPath()));
                java.util.regex.Matcher m = pat.matcher(txt);
                while (m.find()) only.add(m.group(1));
            }
            println("ONLY set from old dump: " + only.size() + " names");
        }
        int n = 0, bad = 0;
        FunctionIterator exts = currentProgram.getFunctionManager().getExternalFunctions();
        Map<String, List<Function>> extByName = new HashMap<>();
        while (exts.hasNext()) { Function e = exts.next(); extByName.computeIfAbsent(e.getName(), k -> new ArrayList<>()).add(e); }
        for (Function f : funcs) {
            boolean[] li = liveIn.get(f), ri = retInfo.get(f);
            if (args.length > 1 && f.getName().equals(args[1])) println("DEBUG " + f.getName() + " ret=" + ri[0] + "/" + ri[1] + " live=" + Arrays.toString(li));
            if (only != null) {
                if (!only.contains(f.getName(true)) && !only.contains(f.getName())) continue;
                if (f.getCallingConventionName() != null && f.getCallingConventionName().contains("thiscall")) continue;
            }
            if (extend) {
                // keep the typed signature the analysis stored; only add the parameters the machine code reads but the stored signature lacks (a stale, too short one drops
                // those arguments at every call), and give a `void` function the return value it produces
                if (f.isExternal() || f.isThunk() || isStub(f)) continue;
                int gi = 0, gf = 0;
                List<Variable> keep = new ArrayList<>();
                for (Parameter p : f.getParameters()) {
                    if (p.isAutoParameter()) { gi = -1000; break; }
                    keep.add(new ParameterImpl(p.getName(), p.getDataType(), currentProgram));
                    String tn = p.getDataType().getName();
                    if (tn.equals("float") || tn.equals("double")) gf++; else gi += Math.max(1, (p.getDataType().getLength() + 3) / 4);
                }
                if (gi < 0) continue;
                int wi = 0, wf = 0;
                for (int a = 0; a < NI; a++) if (li[a]) wi = a + 1;
                for (int a = 0; a < NF; a++) if (li[NI + a]) wf = a + 1;
                boolean grow = wi > gi || wf > gf;
                DataType oldRt = f.getReturnType();
                boolean needRet = (oldRt instanceof VoidDataType) && (ri[0] || ri[1]);
                if (!grow && !needRet) continue;
                for (int a = gi; a < wi; a++) keep.add(new ParameterImpl("param_" + (keep.size() + 1), Undefined4DataType.dataType, currentProgram));
                for (int a = gf; a < wf; a++) keep.add(new ParameterImpl("fparam_" + (a + 1), DoubleDataType.dataType, currentProgram));
                try {
                    f.setCustomVariableStorage(false);
                    if (f.getCallingConventionName() == null || f.getCallingConventionName().startsWith("unknown") || f.getCallingConventionName().equals("default")) f.setCallingConvention("__stdcall");
                    if (grow) f.replaceParameters(keep, Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED);
                    if (needRet) f.setReturnType(ri[1] ? DoubleDataType.dataType : Undefined4DataType.dataType, SourceType.USER_DEFINED);
                    n++;
                    List<Function> es = extByName.get(f.getName());
                    if (es != null && internalByName.get(f.getName()) == f) for (Function e : es) {
                        e.setCustomVariableStorage(false);
                        if (grow) e.replaceParameters(keep, Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED);
                        if (needRet) e.setReturnType(ri[1] ? DoubleDataType.dataType : Undefined4DataType.dataType, SourceType.USER_DEFINED);
                    }
                } catch (Exception e) { bad++; println("SETFAIL " + f.getName() + ": " + e); }
                continue;
            }
            int ni = 0, nf = 0;
            for (int a = 0; a < NI; a++) if (li[a]) ni = a + 1;
            for (int a = 0; a < NF; a++) if (li[NI + a]) nf = a + 1;
            List<Variable> ps = new ArrayList<>();
            int k = 1;
            for (int a = 0; a < ni; a++) ps.add(new ParameterImpl("param_" + (k++), Undefined4DataType.dataType, currentProgram));
            for (int a = 0; a < nf; a++) ps.add(new ParameterImpl("fparam_" + (a + 1), DoubleDataType.dataType, currentProgram));
            DataType rt = ri[1] ? DoubleDataType.dataType : ri[0] ? Undefined4DataType.dataType : VoidDataType.dataType;
            try {
                f.setCustomVariableStorage(false);
                f.setCallingConvention("__stdcall");
                f.replaceParameters(ps, Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED);
                f.setReturnType(rt, SourceType.USER_DEFINED);
                n++;
                List<Function> es = extByName.get(f.getName());
                if (es != null && internalByName.get(f.getName()) == f) for (Function e : es) {
                    e.setCallingConvention("__stdcall");
                    e.replaceParameters(ps, Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED);
                    e.setReturnType(rt, SourceType.USER_DEFINED);
                }
            } catch (Exception e) { bad++; println("SETFAIL " + f.getName() + ": " + e); }
        }
        println("COMMITLIVESIGS done " + n + " functions, " + bad + " failed, rounds=" + rounds);
    }
}
