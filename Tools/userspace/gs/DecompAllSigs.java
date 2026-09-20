import ghidra.app.decompiler.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.pcode.*;
import ghidra.program.model.symbol.SourceType;
import ghidra.util.task.ConsoleTaskMonitor;
import java.io.*;
import java.util.*;

// DecompAllSigs.java OUT_DIR [ORPHAN_DIR PAD_DIR] - like DecompAll.java (same OUT_DIR/0x<entry>.txt + INDEX.tsv), but in callee-before-caller order, and after dumping each function it
// COMMITS the parameter list / return type the decompiler showed for that function's body. Callers decompiled later then print their register arguments to it
// (`f(this, x)` instead of `f()`), while a function's own text is produced before its own signature is committed, so it does not change. Import stubs / externals /
// thunks keep an unknown signature (the decompiler infers those calls' arguments itself and does it well). MODIFIES the program: run on a copy of the project.
// Long timeout and payload limit: one GLDriver function decompiles to 3561 lines and exceeds the default response buffer.
public class DecompAllSigs extends GhidraScript {
    Set<Function> seen = new HashSet<>();
    Map<String, Function> internalByName = new HashMap<>();
    Map<String, List<Function>> externalsByName = new HashMap<>();
    List<Function> order = new ArrayList<>();

    // call AND tail-jump targets (a `b other_function` is printed by the decompiler as a call too)
    Set<Function> callees(Function f) {
        Set<Function> s = new LinkedHashSet<>();
        ghidra.program.model.address.AddressIterator ai = f.getBody().getAddresses(true);
        while (ai.hasNext()) {
            for (ghidra.program.model.symbol.Reference r : currentProgram.getReferenceManager().getReferencesFrom(ai.next())) {
                if (!r.getReferenceType().isFlow()) continue;
                Function c = currentProgram.getFunctionManager().getFunctionAt(r.getToAddress());
                if (c != null && c.isThunk()) {                              // a dyld stub of an exported symbol that lives in this very image: the real callee
                    Function ext = c.getThunkedFunction(true);
                    Function in = ext == null ? null : internalByName.get(ext.getName());
                    if (in != null) c = in;
                }
                if (c != null && c != f) s.add(c);
            }
        }
        return s;
    }

    void visit(Function f) throws Exception {
        // iterative DFS (call chains are deep)
        Deque<Object[]> st = new ArrayDeque<>();
        if (!seen.add(f)) return;
        st.push(new Object[]{f, callees(f).iterator()});
        while (!st.isEmpty()) {
            Object[] top = st.peek();
            Function cur = (Function) top[0];
            @SuppressWarnings("unchecked") Iterator<Function> it = (Iterator<Function>) top[1];
            boolean pushed = false;
            while (it.hasNext()) {
                Function c = it.next();
                if (c.isExternal() || c.isThunk()) continue;
                if (seen.add(c)) { st.push(new Object[]{c, callees(c).iterator()}); pushed = true; break; }
            }
            if (!pushed) { st.pop(); order.add(cur); }
        }
    }

    public void run() throws Exception {
        String[] args = getScriptArgs();
        String outDir = args[0];
        String orphDir = args.length > 1 ? args[1] : null, padDir = args.length > 2 ? args[2] : null;   // orph_* (code reached only through data) and eh_pad_* (C++ landing pads) go to their own dumps
        new File(outDir).mkdirs();
        if (orphDir != null) new File(orphDir).mkdirs();
        if (padDir != null) new File(padDir).mkdirs();
        FunctionIterator ints = currentProgram.getFunctionManager().getFunctions(true);
        Set<String> dup = new HashSet<>();
        while (ints.hasNext()) { Function f = ints.next(); if (f.isExternal() || f.isThunk()) continue; if (internalByName.containsKey(f.getName())) dup.add(f.getName()); internalByName.put(f.getName(), f); }
        for (String dn : dup) internalByName.remove(dn);
        FunctionIterator exts = currentProgram.getFunctionManager().getExternalFunctions();
        while (exts.hasNext()) { Function e = exts.next(); externalsByName.computeIfAbsent(e.getName(), k -> new ArrayList<>()).add(e); }
        FunctionIterator all = currentProgram.getFunctionManager().getFunctions(true);
        while (all.hasNext()) { Function f = all.next(); if (!f.isExternal() && !f.isThunk()) visit(f); }
        DecompInterface d = new DecompInterface();
        DecompileOptions o = new DecompileOptions();
        o.setMaxPayloadMBytes(256); o.setMaxInstructions(2000000);
        d.setOptions(o);
        d.openProgram(currentProgram);
        d.setSimplificationStyle("decompile");
        FileWriter idx = new FileWriter(new File(outDir, "INDEX.tsv"), true);
        FileWriter oidx = orphDir != null ? new FileWriter(new File(orphDir, "INDEX.tsv"), true) : null, pidx = padDir != null ? new FileWriter(new File(padDir, "INDEX.tsv"), true) : null;
        int n = 0, fail = 0, committed = 0;
        for (Function fn : order) {
            long a = fn.getEntryPoint().getOffset();
            String hex = Long.toHexString(a);
            String nm = fn.getName();
            if (nm.startsWith("case_")) continue;                       // jump-table case bodies: part of their owner's decompile
            boolean orph = nm.startsWith("orph_"), pad = nm.startsWith("eh_pad_");
            if ((orph && orphDir == null) || (pad && padDir == null)) continue;
            String dir = orph ? orphDir : pad ? padDir : outDir;
            File outFile = new File(dir, "0x" + hex + ".txt");
            DecompileResults res = d.decompileFunction(fn, 1500, new ConsoleTaskMonitor());
            try (FileWriter fw = new FileWriter(outFile)) {
                fw.write("// Function: " + fn.getName(true) + " @ " + fn.getEntryPoint() + "\n");
                fw.write("// Signature: " + fn.getSignature() + "\n\n");
                if (res != null && res.decompileCompleted()) fw.write(res.getDecompiledFunction().getC());
                else { fw.write("!! decompile failed\n"); fail++; println("FAILED " + fn.getName() + " " + (res == null ? "" : res.getErrorMessage())); }
            }
            (orph ? oidx : pad ? pidx : idx).write("0x" + hex + "\t" + fn.getBody().getNumAddresses() + "\t" + fn.getName(true) + "\n");
            n++;
            boolean forwarder = false;
            if (res != null && res.decompileCompleted()) {
                // a register-forwarding wrapper (`(*fp)(param_1, ..., param_8)`): its 5-8 "parameters" are just every argument register, not a real prototype;
                // committing it would make every caller pass eight arguments
                String c = res.getDecompiledFunction().getC();
                java.util.regex.Matcher m = java.util.regex.Pattern.compile("\\(\\*[^;]*\\)\\(param_1,param_2,param_3,param_4,param_5[^;]*\\);").matcher(c);
                forwarder = m.find() && c.split("\n").length < 40;
            }
            if (forwarder) println("FORWARDER not committed: " + fn.getName());
            if (orph || pad) continue;
            if (!forwarder && res != null && res.decompileCompleted() && res.getHighFunction() != null) {
                try { HighFunctionDBUtil.commitParamsToDatabase(res.getHighFunction(), true, HighFunctionDBUtil.ReturnCommitOption.COMMIT, SourceType.ANALYSIS); committed++; }
                catch (Exception e) { println("COMMITFAIL " + fn.getName() + ": " + e); }
                // calls reach an exported function through a dyld stub whose target is an EXTERNAL placeholder of the same name: give the placeholder the committed signature
                List<Function> es = externalsByName.get(fn.getName());
                if (es != null && internalByName.get(fn.getName()) == fn) for (Function ext : es) {
                    try {
                        ext.setCallingConvention(fn.getCallingConventionName());
                        ext.replaceParameters(Arrays.asList(fn.getParameters()), Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.ANALYSIS);
                        ext.setReturnType(fn.getReturnType(), SourceType.ANALYSIS);
                    } catch (Exception e) { println("EXTFAIL " + fn.getName() + ": " + e); }
                }
            }
        }
        idx.close(); if (oidx != null) oidx.close(); if (pidx != null) pidx.close();
        println("DECOMPALLSIGS done " + n + " functions, " + committed + " signatures committed, " + fail + " failed");
    }
}
