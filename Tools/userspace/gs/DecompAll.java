import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.decompiler.ClangNode;
import ghidra.app.decompiler.ClangToken;
import ghidra.app.decompiler.ClangOpToken;
import ghidra.app.decompiler.ClangBreak;
import ghidra.program.model.pcode.PcodeOp;
import ghidra.program.model.pcode.PcodeOpAST;
import ghidra.program.model.pcode.Varnode;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.util.task.ConsoleTaskMonitor;
import java.io.File;
import java.io.FileWriter;

// Usage: -postScript DecompAll.java <outDir> [minAddrHex] [maxAddrHex]
// Writes <outDir>/<entry>.txt for every (non-external, non-thunk) function, and <outDir>/INDEX.tsv (entry, size, name).
public class DecompAll extends GhidraScript {

    // DECOMP_PAREN_FLOAT=1: Ghidra prints `x + (y + (z + w))` as `x + y + z + w` (its + and * tokens are marked associative, which is false for float arithmetic; the stock's
    // fused multiply-add chains are exactly this right-nested shape, GLEngine _gleMultMatrix) and the C compiler then reads it as ((x + y) + z) + w, a different rounding.
    // The decompiler's own expression tree is in the token markup: parenthesise a RIGHT operand that is itself an inline FLOAT_ADD/SUB (of a FLOAT_ADD) or FLOAT_MULT/DIV (of a
    // FLOAT_MULT). Sub/div print their own parentheses.
    static void flatten(ClangNode n, List<ClangToken> out) {
        if (n instanceof ClangToken) { out.add((ClangToken) n); return; }
        for (int i = 0; i < n.numChildren(); i++) flatten(n.Child(i), out);
    }
    static int fclass(int opc) {
        if (opc == PcodeOp.FLOAT_ADD || opc == PcodeOp.FLOAT_SUB) return 1;
        if (opc == PcodeOp.FLOAT_MULT || opc == PcodeOp.FLOAT_DIV) return 2;
        return 0;
    }
    static void collect(PcodeOp p, Set<PcodeOp> d, int depth) {
        if (p == null || depth > 40 || !d.add(p)) return;
        for (int i = 0; i < p.getNumInputs(); i++) { Varnode v = p.getInput(i); if (v != null && v.getDef() != null) collect(v.getDef(), d, depth + 1); }
    }
    // DECOMP_CALL_DEBUG=1: for every CALL/CALLIND op print its inputs' storage (register / size) and output, and the tokens that carry it
    String vn(Varnode v) {
        if (v == null) return "none";
        String sp = v.getAddress().getAddressSpace().getName();
        ghidra.program.model.lang.Register r = currentProgram.getLanguage().getRegister(v.getAddress(), v.getSize());
        if (r == null && v.isRegister()) r = currentProgram.getLanguage().getRegister(v.getAddress(), 0);
        return sp + ":" + (r != null ? r.getName() : Long.toHexString(v.getOffset())) + "/" + v.getSize();
    }
    void callDebug(ClangNode root) {
        List<ClangToken> toks = new ArrayList<>(); flatten(root, toks);
        Set<PcodeOp> seen = new HashSet<>();
        for (int i = 0; i < toks.size(); i++) {
            ClangToken t = toks.get(i); PcodeOp op = t.getPcodeOp();
            if (op == null || (op.getOpcode() != PcodeOp.CALLIND && op.getOpcode() != PcodeOp.CALL) || !seen.add(op)) continue;
            StringBuilder sb = new StringBuilder("CALLDBG " + PcodeOp.getMnemonic(op.getOpcode()) + " first-token[" + t.getText().replace("\n", "NL") + "] ");
            for (int k = 0; k < op.getNumInputs(); k++) { sb.append(" in").append(k).append("=").append(vn(op.getInput(k))); }
            sb.append(" out=").append(vn(op.getOutput()));
            System.out.println(sb);
            for (int k = Math.max(0, i - 3); k < Math.min(toks.size(), i + 70); k++) System.out.println("   tok " + k + " [" + toks.get(k).getText().replace("\n", "NL") + "] " + toks.get(k).getClass().getSimpleName() + (toks.get(k).getPcodeOp() == null ? "" : " op=" + PcodeOp.getMnemonic(toks.get(k).getPcodeOp().getOpcode())));
        }
    }
    // DECOMP_TYPED_CALLS=1: an indirect call `(**(code **)p)(args)` has no prototype in the C (typedef int code()), so gcc passes every argument by the K&R rules (a float becomes a double that
    // takes r3:r4 AND f1; the integer arguments shift up behind it) and reads an int result from r3. The stock's call took r3 = context, f1 = float and read the float result from f1 (GLEngine
    // _gleUpdateFogData: the rebuilt called the fog function with r3 = the float's bits, ctx in r5, and stored (float)r3). Ghidra's call op knows the REGISTERS (inputs r3..r10 / f1..f13, an 8-byte output =
    // a double result in f1): rebuild the call from them: cast the function pointer to a prototype whose positional ABI assignment gives exactly those registers (integers in ascending register order, doubles in
    // FPR order, a double consuming two GPR slots, filler 0 / 0.0 for registers the stock leaves alone) and a double return when the output is 8 bytes.
    String regName(Varnode v) {
        if (v == null || !v.getAddress().isRegisterAddress()) return null;
        ghidra.program.model.lang.Register r = currentProgram.getLanguage().getRegister(v.getAddress(), v.getSize());
        return r == null ? null : r.getName();
    }
    static String render(String[] txt, boolean[] gone, int[] open, int[] close, int a, int b) {
        StringBuilder s = new StringBuilder();
        for (int i = a; i <= b; i++) { if (gone[i]) continue; for (int c = 0; c < open[i]; c++) s.append('('); String x = txt[i]; s.append(x.startsWith("\n") ? " " : x); for (int c = 0; c < close[i]; c++) s.append(')'); }
        return s.toString().replaceAll("\\s+", " ").trim();
    }
    // DECOMP_EXTRA_DEBUG=1: for every INDIRECT op that defines a register output of a call (Ghidra prints such a value as `extraout_X`, an uninitialised local) print the call, the
    // register, the printed variable name and whether the call's own output is used
    void extraDebug(ghidra.app.decompiler.DecompileResults res, String fname) {
        ghidra.program.model.pcode.HighFunction hf = res.getHighFunction(); if (hf == null) return;
        Iterator<PcodeOpAST> it = hf.getPcodeOps();
        while (it.hasNext()) {
            PcodeOpAST op = it.next();
            if (op.getOpcode() != PcodeOp.INDIRECT) continue;
            Varnode o = op.getOutput(); Varnode iop = op.getInput(1); if (o == null || iop == null) continue;
            PcodeOp call = hf.getOpRef((int) iop.getOffset());
            String cn = call == null ? "null" : PcodeOp.getMnemonic(call.getOpcode());
            String hv = o.getHigh() == null ? "nohigh" : String.valueOf(o.getHigh().getName());
            boolean used = o.getDescendants().hasNext();
            Varnode co = call == null ? null : call.getOutput();
            System.out.println("EXTRADBG " + fname + " " + vn(o) + " name=" + hv + " used=" + used + " call=" + cn + " callout=" + (co == null ? "none" : vn(co) + (co.getDescendants().hasNext() ? " USED" : " unused")));
        }
    }
    String regsOf(PcodeOp op) { StringBuilder s = new StringBuilder("["); for (int k = 1; k < op.getNumInputs(); k++) { Varnode v = op.getInput(k); String rn = regName(v); s.append(rn != null ? rn : (v.getAddress().getAddressSpace().getName() + ":" + Long.toHexString(v.getOffset()))).append("/").append(v.getSize()).append(' '); } Varnode o = op.getOutput(); s.append("-> ").append(o == null ? "none" : o.getSize() + ""); return s.append("]").toString(); }
    static String ctxOf(List<ClangToken> toks, int i) { StringBuilder s = new StringBuilder(); for (int k = Math.max(0, i - 2); k < Math.min(toks.size(), i + 40); k++) { String x = toks.get(k).getText(); if (!x.trim().isEmpty()) s.append(x); } return s.toString(); }
    int typedCalls(List<ClangToken> toks, String[] txt, boolean[] gone, int[] open, int[] close, int[] skipped) {
        int n = toks.size(), done = 0;
        List<Integer> starts = new ArrayList<>(); Set<PcodeOp> seen = new HashSet<>();
        for (int i = 0; i < n; i++) { ClangToken t = toks.get(i); PcodeOp op = t.getPcodeOp(); if (op != null && op.getOpcode() == PcodeOp.CALLIND && seen.add(op) && t instanceof ClangOpToken && t.getText().trim().equals("*")) starts.add(i); }
        for (int si = starts.size() - 1; si >= 0; si--) {            // the later in the stream first: an inner call is rewritten before the arguments of the outer one are rendered
            int i = starts.get(si); PcodeOp op = toks.get(i).getPcodeOp();
            int nin = op.getNumInputs() - 1;
            boolean anyF = false, hasFReg = false, ok = nin > 0; int[] num = new int[Math.max(nin, 0)]; boolean[] isF = new boolean[Math.max(nin, 0)];
            // A call input's storage is where the VALUE lives (a callee-saved register, a constant, the entry parameter), not the argument register; Ghidra orders the inputs by its calling
            // model - the 8-byte (FPR) arguments first, f1.. in turn, then the 4-byte (GPR) ones, r3.. in turn - so the register is the position within the class.
            int cf = 0, ci = 0, lastSize = 8;
            for (int k = 1; k <= nin && ok; k++) {
                Varnode v = op.getInput(k);
                if (v.getSize() == 8) { if (lastSize == 4) ok = false; num[k - 1] = ++cf; isF[k - 1] = true; anyF = true; }
                else if (v.getSize() == 4) { num[k - 1] = 2 + (++ci); lastSize = 4; }
                else ok = false;
                if (cf > 13 || ci > 8) ok = false;
            }
            Varnode out = op.getOutput(); boolean fret = out != null && out.getSize() == 8;
            for (int k = 1; k <= nin; k++) if (op.getInput(k).getSize() == 8) hasFReg = true;
            boolean ev = hasFReg || fret;      // only calls with float evidence matter (an int-only call is compiled right by the K&R rules)
            if (nin == 0) { if (!fret) continue; ok = true; }
            if (!ok) { if (ev) { skipped[0]++; System.out.println("TYPEDSKIP bad-input-regs " + regsOf(op) + " " + ctxOf(toks, i)); } continue; }
            if (!anyF && !fret) continue;
            // the callee's closing paren
            int depth = 1, pc = -1; for (int p = i + 1; p < n; p++) { String x = toks.get(p).getText().trim(); if (x.equals("(")) depth++; else if (x.equals(")")) { depth--; if (depth == 0) { pc = p; break; } } }
            if (pc < 0) { skipped[0]++; System.out.println("TYPEDSKIP no-callee-close " + regsOf(op) + " " + ctxOf(toks, i)); continue; }
            // the callee: a loaded pointer cast `(code **)` / `(code *)`, or a plain function-pointer variable `(*pcVar1)` / `(*UNRECOVERED_JUMPTABLE)`
            int jt = -1; for (int j = i + 1; j < pc; j++) if (toks.get(j) instanceof ghidra.app.decompiler.ClangTypeToken && toks.get(j).getText().trim().equals("code")) { jt = j; break; }
            int cc = -1, stars = 0, vt = -1;
            if (jt >= 0) for (int k = jt + 1; k < Math.min(pc, jt + 12); k++) { String x = toks.get(k).getText().trim(); if (x.equals("*")) stars++; else if (x.equals(")")) { cc = k; break; } }
            else { for (int k = i + 1; k < pc; k++) { ClangToken tk = toks.get(k); String x = tk.getText().trim(); if (x.isEmpty()) continue; if (tk instanceof ghidra.app.decompiler.ClangVariableToken && tk.getHighVariable() != null) vt = k; break; } }
            if (jt >= 0 ? (cc < 0 || stars < 1 || stars > 2) : vt < 0) { skipped[0]++; System.out.println("TYPEDSKIP no-code-cast " + regsOf(op) + " " + ctxOf(toks, i)); continue; }
            int ao = -1; for (int q = pc + 1; q < Math.min(n, pc + 6); q++) { String x = toks.get(q).getText().trim(); if (x.equals("(")) { ao = q; break; } else if (!x.isEmpty()) break; }
            if (ao < 0) { skipped[0]++; System.out.println("TYPEDSKIP no-arg-open " + ctxOf(toks, i)); continue; }
            List<Integer> seps = new ArrayList<>(); depth = 1; int ac = -1;
            for (int r = ao + 1; r < n; r++) { ClangToken t = toks.get(r); String x = t.getText().trim();
                if (x.equals("(")) depth++; else if (x.equals(")")) { depth--; if (depth == 0) { ac = r; break; } }
                else if (x.equals(",") && depth == 1 && t.getPcodeOp() == op) seps.add(r); }
            if (ac < 0 || seps.size() + 1 != nin) { if (nin == 0 && ac == ao + 1 + 0) { } else { skipped[0]++; System.out.println("TYPEDSKIP arg-count " + ctxOf(toks, i)); continue; } }
            String[] at = new String[nin];
            for (int k = 0; k < nin; k++) { int a0 = k == 0 ? ao + 1 : seps.get(k - 1) + 1; int a1 = k == nin - 1 ? ac - 1 : seps.get(k) - 1; at[k] = render(txt, gone, open, close, a0, a1); }
            // the prototype: positional parameters whose ABI registers are the stock's
            List<int[]> ints = new ArrayList<>(), flts = new ArrayList<>();
            for (int k = 0; k < nin; k++) (isF[k] ? flts : ints).add(new int[]{num[k], k});
            ints.sort((x, y) -> x[0] - y[0]); flts.sort((x, y) -> x[0] - y[0]);
            boolean dup = false; for (int k = 1; k < ints.size(); k++) if (ints.get(k)[0] == ints.get(k - 1)[0]) dup = true; for (int k = 1; k < flts.size(); k++) if (flts.get(k)[0] == flts.get(k - 1)[0]) dup = true;
            if (dup) { skipped[0]++; System.out.println("TYPEDSKIP dup-reg " + regsOf(op) + " " + ctxOf(toks, i)); continue; }
            List<String> pt = new ArrayList<>(), av = new ArrayList<>(); int g = 3, nf = 1, fi = 0; boolean bad = false;
            for (int[] it : ints) {
                while (g < it[0]) {
                    if (fi < flts.size() && g + 2 <= it[0]) { int[] f = flts.get(fi++); while (nf < f[0]) { pt.add("double"); av.add("0.0"); nf++; g += 2; } pt.add("double"); av.add(at[f[1]]); nf++; g += 2; }
                    else { pt.add("int"); av.add("0"); g++; }
                }
                pt.add("int"); av.add(at[it[1]]); g++;
            }
            while (fi < flts.size()) { int[] f = flts.get(fi++); while (nf < f[0]) { pt.add("double"); av.add("0.0"); nf++; g += 2; } pt.add("double"); av.add(at[f[1]]); nf++; g += 2; }
            if (bad) { skipped[0]++; System.out.println("TYPEDSKIP too-many-regs " + ctxOf(toks, i)); continue; }
            String PT = pt.isEmpty() ? "void" : String.join(",", pt), RT = fret ? "double" : "int";
            if (jt >= 0) { txt[jt] = RT + " ("; txt[cc] = ")(" + PT + "))"; }
            else txt[vt] = "((" + RT + " (*)(" + PT + "))" + txt[vt] + ")";
            for (int k = ao + 1; k < ac; k++) { gone[k] = true; open[k] = 0; close[k] = 0; }
            gone[ao + 1] = false; txt[ao + 1] = String.join(", ", av);
            done++;
        }
        return done;
    }
    String parenthesised(ClangNode root, int[] count) {
        List<ClangToken> toks = new ArrayList<>(); flatten(root, toks);
        int n = toks.size(); int[] open = new int[n]; int[] close = new int[n];
        boolean doParen = System.getenv("DECOMP_PAREN_FLOAT") != null;
        for (int i = 0; i < n && doParen; i++) {
            ClangToken t = toks.get(i);
            if (!(t instanceof ClangOpToken)) continue;
            PcodeOp op = t.getPcodeOp(); if (op == null) continue;
            int oc = op.getOpcode();
            if (oc != PcodeOp.FLOAT_ADD && oc != PcodeOp.FLOAT_MULT) continue;     // - and / parenthesise their right operand themselves
            String tx = t.getText().trim();
            if (!(tx.equals("+") && oc == PcodeOp.FLOAT_ADD) && !(tx.equals("*") && oc == PcodeOp.FLOAT_MULT)) continue;
            Varnode r = op.getInput(1); if (r == null || r.getDef() == null) continue;
            PcodeOp p = r.getDef(); if (fclass(p.getOpcode()) != fclass(oc)) continue;
            // the right operand is an inline sub-expression when no variable token of r stands right after the operator
            int j = i + 1; while (j < n && (toks.get(j) instanceof ClangBreak || toks.get(j).getText().trim().isEmpty())) j++;
            if (j >= n) continue;
            if (toks.get(j).getVarnode() == r) continue;
            Set<PcodeOp> d = new HashSet<>(); collect(p, d, 0);
            int first = -1, last = -1;
            for (int k = j; k < n; k++) {
                ClangToken u = toks.get(k); PcodeOp uo = u.getPcodeOp();
                String ut = u.getText().trim();
                if (ut.equals(";") || ut.equals("{") || ut.equals("}")) break;     // an operand never crosses a statement (a loop-carried variable pulls the NEXT statement's ops into the slice)
                if (uo != null && !d.contains(uo)) break;
                if (uo != null) { if (first < 0) first = k; last = k; }
            }
            if (first < 0 || last < 0) continue;
            // the owned tokens can end inside an open subscript / paren (`param_2[1` + `]`): take the closers that balance the range
            int bs = 0, ps = 0;
            for (int k = j; k <= last; k++) { String x = toks.get(k).getText(); for (char ch : x.toCharArray()) { if (ch == '[') bs++; else if (ch == ']') bs--; else if (ch == '(') ps++; else if (ch == ')') ps--; } }
            while (bs > 0 || ps > 0) {
                int q = last + 1; while (q < n && toks.get(q).getText().trim().isEmpty() && !(toks.get(q) instanceof ClangBreak)) q++;      // (empty tokens sit between a subscript's number and its `]`)
                if (q >= n) break;
                String x = toks.get(q).getText().trim();
                if (x.equals("]") && bs > 0) { bs--; last = q; } else if (x.equals(")") && ps > 0) { ps--; last = q; } else break;
            }
            // a leading cast / paren token before `first` that belongs to the operand: start at j
            open[j]++; close[last]++; count[0]++;
            if (System.getenv("DECOMP_PAREN_DEBUG") != null && count[0] <= 2) { StringBuilder db = new StringBuilder("PARENDBG range " + j + ".." + last + " : "); for (int k = j; k <= Math.min(n - 1, last + 3); k++) db.append("[").append(toks.get(k).getText().replace("\n", "NL")).append(toks.get(k).getPcodeOp() == null ? "/null" : "/op").append("]"); System.out.println(db); }
        }
        String[] txt = new String[n]; boolean[] gone = new boolean[n];
        for (int i = 0; i < n; i++) { ClangToken t = toks.get(i); if (t instanceof ClangBreak) { StringBuilder w = new StringBuilder("\n"); for (int k = 0; k < ((ClangBreak) t).getIndent(); k++) w.append(' '); txt[i] = w.toString(); } else txt[i] = t.getText(); }
        int typed = 0;
        if (System.getenv("DECOMP_TYPED_CALLS") != null) { int[] sk = new int[1]; typed = typedCalls(toks, txt, gone, open, close, sk); count[1] = typed; count[2] = sk[0]; }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (gone[i]) continue;
            for (int c = 0; c < open[i]; c++) sb.append('(');
            sb.append(txt[i]);
            for (int c = 0; c < close[i]; c++) sb.append(')');
        }
        // safety net: every statement of the result must balance its parentheses/brackets, else the injection misplaced a closer: keep the decompiler's own text for this function
        int db = 0; boolean ok = true; ArrayDeque<Boolean> stk = new ArrayDeque<>();      // paren stack: true = the paren of a `for (a; b; c)` header, whose ; are not statement ends
        for (int i = 0; i < sb.length() && ok; i++) { char ch = sb.charAt(i);
            if (ch == '(') { int e = i; while (e > 0 && sb.charAt(e - 1) == ' ') e--; stk.push(e >= 3 && sb.substring(e - 3, e).equals("for") && (e == 3 || !Character.isLetterOrDigit(sb.charAt(e - 4)) && sb.charAt(e - 4) != '_')); }
            else if (ch == ')') { if (stk.isEmpty()) ok = false; else stk.pop(); }
            else if (ch == '[') db++; else if (ch == ']') { db--; if (db < 0) ok = false; }
            else if (ch == ';') { if (db != 0 || !(stk.isEmpty() || (stk.size() == 1 && stk.peek()))) ok = false; }
            else if (ch == '{' || ch == '}') { if (db != 0 || !stk.isEmpty()) ok = false; }
            if (!ok) { System.out.println("PARENFLOAT unbalanced near: " + sb.substring(Math.max(0, i - 260), Math.min(sb.length(), i + 40)).replace("\n", " | ")); } }
        if (!ok) { System.out.println("PARENFLOAT unbalanced, function left as the decompiler printed it"); count[0] = 0; count[1] = 0; return null; }
        return sb.toString();
    }
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String outDir = args[0];
        long lo = args.length > 1 ? Long.parseLong(args[1].replace("0x",""), 16) : 0;
        long hi = args.length > 2 ? Long.parseLong(args[2].replace("0x",""), 16) : Long.MAX_VALUE;
        new File(outDir).mkdirs();
        DecompInterface decomp = new DecompInterface();
        decomp.openProgram(currentProgram);
        decomp.setSimplificationStyle("decompile");
        FileWriter idx = new FileWriter(new File(outDir, "INDEX.tsv"), true);
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        int n = 0, fail = 0, parenFuncs = 0, parenSites = 0, typedFuncs = 0, typedSites = 0, callSkipped = 0;
        while (it.hasNext()) {
            Function fn = it.next();
            if (fn.isExternal() || fn.isThunk()) continue;
            long a = fn.getEntryPoint().getOffset();
            if (a < lo || a >= hi) continue;
            String hex = Long.toHexString(a);
            long size = fn.getBody().getNumAddresses();
            File outFile = new File(outDir, "0x" + hex + ".txt");
            if (outFile.exists()) continue;
            try (FileWriter fw = new FileWriter(outFile)) {
                fw.write("// Function: " + fn.getName(true) + " @ " + fn.getEntryPoint() + "\n");
                fw.write("// Signature: " + fn.getSignature() + "\n\n");
                DecompileResults res = decomp.decompileFunction(fn, 60, new ConsoleTaskMonitor());
                if (res == null || !res.decompileCompleted()) {
                    // a very large function (GLDriver FUN_00115fa0, 34 KB) exceeds the default payload/instruction limits: retry once with generous ones
                    DecompInterface big = new DecompInterface();
                    DecompileOptions o = new DecompileOptions();
                    o.setMaxPayloadMBytes(256); o.setMaxInstructions(2000000);
                    big.setOptions(o); big.openProgram(currentProgram); big.setSimplificationStyle("decompile");
                    res = big.decompileFunction(fn, 1800, new ConsoleTaskMonitor());
                    big.dispose();
                }
                if (res != null && res.decompileCompleted()) {
                    String c = res.getDecompiledFunction().getC();
                    if ((System.getenv("DECOMP_PAREN_FLOAT") != null || System.getenv("DECOMP_TYPED_CALLS") != null) && res.getCCodeMarkup() != null) {
                        if (System.getenv("DECOMP_CALL_DEBUG") != null) callDebug(res.getCCodeMarkup());
                        if (System.getenv("DECOMP_EXTRA_DEBUG") != null) extraDebug(res, fn.getName());
                        int[] cnt = new int[3]; String c2 = parenthesised(res.getCCodeMarkup(), cnt);
                        if (c2 != null && (cnt[0] > 0 || cnt[1] > 0)) { c = c2; if (cnt[0] > 0) { parenFuncs++; parenSites += cnt[0]; } if (cnt[1] > 0) { typedFuncs++; typedSites += cnt[1]; } }
                        callSkipped += cnt[2];
                    }
                    fw.write(c);
                }
                else { fw.write("!! decompile failed\n"); fail++; }
            }
            idx.write("0x" + hex + "\t" + size + "\t" + fn.getName(true) + "\n");
            n++;
        }
        idx.close();
        println("DECOMPALL done " + n + " failed " + fail + (System.getenv("DECOMP_PAREN_FLOAT") != null ? " paren-float functions " + parenFuncs + " sites " + parenSites : "") + (System.getenv("DECOMP_TYPED_CALLS") != null ? " typed-call functions " + typedFuncs + " sites " + typedSites + " skipped " + callSkipped : ""));
    }
}
