import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.pcode.*;
import ghidra.util.task.ConsoleTaskMonitor;
import java.util.*;

// Usage: -postScript OverrideIndirectCalls.java OUT.tsv [hexEntry... | ALL]
// An indirect call (`bctrl`: a virtual call, a function pointer) has no signature, so the decompiler prints only the arguments it can prove and
// often none: `(**(code **)(*piVar8 + 8))()` for a virtual call whose object the machine code passes in r3. Compiled at -O0 the call then passes
// whatever r3..r10 happen to hold. For every indirect call printed with NO arguments this script
//   1. writes a call-site override with eight 4-byte arguments (r3..r10) and decompiles again;
//   2. keeps the arguments up to the last one that carries a value defined in the caller (computed, a parameter of the caller, a constant) and drops
//      the trailing ones that are only the caller's own untouched input registers (`in_rN`: registers the caller never set - no argument there);
//   3. rewrites the override with exactly that many arguments (none: the override is removed).
// OUT.tsv lists function, call address, argument count. Run on a COPY of the project, then RedumpContaining.java with the functions listed.
public class OverrideIndirectCalls extends GhidraScript {
    DecompInterface dec;
    HighFunction decomp(Function f) {
        DecompileResults r = dec.decompileFunction(f, 600, new ConsoleTaskMonitor());
        return r.getHighFunction();
    }
    List<PcodeOpAST> indirectCalls(HighFunction hf) {
        List<PcodeOpAST> out = new ArrayList<>();
        Iterator<PcodeOpAST> it = hf.getPcodeOps();
        while (it.hasNext()) { PcodeOpAST op = it.next(); if (op.getOpcode() == PcodeOp.CALLIND) out.add(op); }
        return out;
    }
    FunctionDefinitionDataType sig(String name, int n) {
        FunctionDefinitionDataType s = new FunctionDefinitionDataType(name);
        ParameterDefinition[] ps = new ParameterDefinition[n];
        for (int i = 0; i < n; i++) ps[i] = new ParameterDefinitionImpl("a" + i, Undefined4DataType.dataType, null);
        s.setArguments(ps);
        s.setReturnType(Undefined4DataType.dataType);
        return s;
    }
    // a value the caller really provides. Only a raw input register of the caller that is not one of its formal parameters counts as "not set"
    // (followed through COPY / INDIRECT / phi); everything else is kept - an extra argument is harmless (the callee ignores the register), a missing
    // one is not.
    boolean defined(Varnode v, Set<Varnode> seen) {
        if (v == null || !seen.add(v)) return false;
        if (v.isConstant()) return true;
        PcodeOp d = v.getDef();
        if (d == null) return !v.isInput() || v.getHigh() instanceof HighParam;
        int oc = d.getOpcode();
        if (oc == PcodeOp.COPY || oc == PcodeOp.INDIRECT || oc == PcodeOp.CAST) return defined(d.getInput(0), seen);
        if (oc == PcodeOp.MULTIEQUAL) { for (int i = 0; i < d.getNumInputs(); i++) if (defined(d.getInput(i), seen)) return true; return false; }
        return true;
    }
    // arguments are set up right before the call: the highest of r3..r10 written between the previous call (or the function entry, at most 40
    // instructions back) and the bctrl gives the count; r3 always counts when step 2 found it defined (the object of a virtual call is often set up
    // earlier). Registers merely still holding an older value are not arguments.
    int windowArgs(Address call) {
        int hi = 0;
        ghidra.program.model.listing.Instruction ins = getInstructionAt(call);
        Function f = getFunctionContaining(call);
        for (int k = 0; k < 40 && ins != null; k++) {
            ins = ins.getPrevious();
            if (ins == null || (f != null && !f.getBody().contains(ins.getAddress()))) break;
            String mn = ins.getMnemonicString();
            if (mn.startsWith("bl") || mn.equals("bctrl")) break;
            for (Object o : ins.getResultObjects()) {
                if (o instanceof ghidra.program.model.lang.Register) {
                    String rn = ((ghidra.program.model.lang.Register) o).getName();
                    if (rn.matches("r([3-9]|10)")) hi = Math.max(hi, Integer.parseInt(rn.substring(1)) - 2);
                }
            }
        }
        return hi;
    }
    void refine(String in, String out) throws Exception {
        int n = 0, changed = 0;
        try (java.io.FileWriter w = new java.io.FileWriter(out)) {
            for (String line : java.nio.file.Files.readAllLines(java.nio.file.Paths.get(in))) {
                String[] c = line.split("\t");
                int old = Integer.parseInt(c[3]);
                if (old == 0) { w.write(line + "\n"); continue; }
                Address a = toAddr(Long.parseLong(c[2], 16));
                Function f = getFunctionAt(toAddr(Long.parseLong(c[0].replace("0x", ""), 16)));
                // a tail jump (`bctr`) passes the function's own arguments through untouched: nothing is set up before it, keep step 2's count
                ghidra.program.model.listing.Instruction ci = getInstructionAt(a);
                boolean tail = ci != null && ci.getMnemonicString().equals("bctr");
                int k = tail ? old : Math.max(1, Math.min(old, windowArgs(a)));
                HighFunctionDBUtil.writeOverride(f, a, sig("icall_" + a, k));
                if (k != old) changed++;
                n++;
                w.write(c[0] + "\t" + c[1] + "\t" + c[2] + "\t" + k + "\n");
            }
        }
        println("OVERRIDEIND refine: " + n + " calls, " + changed + " argument counts reduced to the registers set before the call");
    }
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String out = args[0];
        dec = new DecompInterface();
        dec.openProgram(currentProgram);
        if (args.length > 2 && args[1].equals("REFINE")) { refine(args[2], out); return; }
        List<Function> fns = new ArrayList<>();
        if (args.length < 2 || args[1].equals("ALL")) { for (Function f : currentProgram.getFunctionManager().getFunctions(true)) if (!f.isThunk() && !f.isExternal()) fns.add(f); }
        else for (int i = 1; i < args.length; i++) { Function f = getFunctionAt(toAddr(Long.parseLong(args[i].replace("0x", ""), 16))); if (f != null) fns.add(f); }
        int nCalls = 0, nFixed = 0, nFns = 0;
        try (java.io.FileWriter w = new java.io.FileWriter(out)) {
            for (Function f : fns) {
                monitor.checkCancelled();
                HighFunction hf = decomp(f);
                if (hf == null) continue;
                // every indirect call: Ghidra's own argument count for a call without a signature is a guess (a virtual TType::setType printed with 2 of
                // its 5 arguments); `printed` keeps what it showed as a lower bound
                List<Address> empty = new ArrayList<>();
                Map<Address, Integer> printed = new HashMap<>();
                for (PcodeOpAST op : indirectCalls(hf)) { empty.add(op.getSeqnum().getTarget()); printed.put(op.getSeqnum().getTarget(), op.getNumInputs() - 1); }
                if (empty.isEmpty()) continue;
                nCalls += empty.size();
                for (Address a : empty) HighFunctionDBUtil.writeOverride(f, a, sig("icall_" + a, 8));
                HighFunction hf2 = decomp(f);
                if (hf2 == null) continue;
                Map<Address, Integer> keep = new HashMap<>();
                for (PcodeOpAST op : indirectCalls(hf2)) {
                    Address a = op.getSeqnum().getTarget();
                    if (!empty.contains(a)) continue;
                    int n = 0;
                    for (int i = 1; i < op.getNumInputs(); i++) if (defined(op.getInput(i), new HashSet<>())) n = i;
                    keep.put(a, n);
                }
                boolean any = false;
                for (Address a : empty) {
                    int n = keep.getOrDefault(a, 0);
                    ghidra.program.model.listing.Instruction ci = getInstructionAt(a);
                    boolean tail = ci != null && ci.getMnemonicString().equals("bctr");
                    if (!tail) n = Math.max(1, Math.min(n, windowArgs(a)));   // registers set up before the call (see windowArgs)
                    n = Math.max(n, printed.getOrDefault(a, 0));
                    if (n == 0) {
                        // no argument after all: drop the override again
                        HighFunctionDBUtil.writeOverride(f, a, sig("icall_" + a, 0));
                    } else {
                        HighFunctionDBUtil.writeOverride(f, a, sig("icall_" + a, n));
                        any = true; nFixed++;
                    }
                    w.write("0x" + Long.toHexString(f.getEntryPoint().getOffset()) + "\t" + f.getName() + "\t" + a + "\t" + n + "\n");
                }
                if (any) nFns++;
            }
        }
        println("OVERRIDEIND " + nCalls + " argument-less indirect calls, " + nFixed + " given arguments, in " + nFns + " functions");
    }
}
