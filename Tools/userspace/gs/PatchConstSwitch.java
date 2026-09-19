import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Instruction;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

// Usage: -postScript PatchConstSwitch.java <hexBctr>...
// For the constant-selector idiom (`lwz r0,K(rBase); add r0,r0,rBase; mtctr r0; bctr` + offset table) whose JumpTable override the decompiler will not
// honour (a guard on an unrelated variable defeats it), rewrite the analysed copy's `bctr` as the equivalent direct `b target`. Only the Ghidra
// project's copy of the bytes changes; the stock binary is untouched.
public class PatchConstSwitch extends GhidraScript {
    @Override
    public void run() throws Exception {
        Pattern lwzc = Pattern.compile("^(0x[0-9a-fA-F]+|-?\\d+)\\((r\\d+)\\)$");
        // a JumpTable override under a patched (no longer indirect) instruction kills the decompiler process: drop the function's overrides first
        java.util.HashSet<String> done = new java.util.HashSet<>();
        for (String arg : getScriptArgs()) {
            Address a0 = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(arg.replace("0x", ""));
            ghidra.program.model.listing.Function f0 = getFunctionContaining(a0);
            if (f0 == null || !done.add(f0.getEntryPoint().toString())) continue;
            java.util.ArrayList<ghidra.program.model.symbol.Symbol> del = new java.util.ArrayList<>();
            ghidra.program.model.symbol.SymbolIterator it = currentProgram.getSymbolTable().getChildren(f0.getSymbol());
            while (it.hasNext()) { ghidra.program.model.symbol.Symbol s = it.next(); if (s.getName().equals("override")) del.add(s); }
            for (ghidra.program.model.symbol.Symbol s : del) { ghidra.program.model.symbol.SymbolIterator i2 = currentProgram.getSymbolTable().getChildren(s); java.util.ArrayList<ghidra.program.model.symbol.Symbol> k = new java.util.ArrayList<>(); while (i2.hasNext()) k.add(i2.next()); for (ghidra.program.model.symbol.Symbol c : k) { ghidra.program.model.symbol.SymbolIterator i3 = currentProgram.getSymbolTable().getChildren(c); java.util.ArrayList<ghidra.program.model.symbol.Symbol> g = new java.util.ArrayList<>(); while (i3.hasNext()) g.add(i3.next()); for (ghidra.program.model.symbol.Symbol x : g) x.delete(); c.delete(); } s.delete(); }
            println("removed override namespaces of " + f0.getName() + ": " + del.size());
        }
        for (String arg : getScriptArgs()) {
            Address bctr = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(arg.replace("0x", ""));
            Instruction bi = getInstructionAt(bctr);
            if (bi == null || !bi.getMnemonicString().equals("bctr")) { println("SKIP " + arg); continue; }
            String base = null, ld = null; long k = -1;
            Instruction p = bi.getPrevious();
            for (int i = 0; i < 24 && p != null; i++, p = p.getPrevious()) {
                String m = p.getMnemonicString();
                if (m.equals("add") && base == null) {
                    String d = p.getDefaultOperandRepresentation(0), a = p.getDefaultOperandRepresentation(1), b = p.getDefaultOperandRepresentation(2);
                    if (d.equals(a) || d.equals(b)) { ld = d; base = d.equals(a) ? b : a; }
                } else if (base != null && k < 0 && m.equals("lwz") && p.getDefaultOperandRepresentation(0).equals(ld)) {
                    Matcher mm = lwzc.matcher(p.getDefaultOperandRepresentation(1));
                    if (mm.matches() && mm.group(2).equals(base)) k = Long.decode(mm.group(1));
                }
            }
            if (k < 0) { println("SKIP " + arg + " (not constant-selector)"); continue; }
            Address table = bctr.add(4);
            long w = getInt(table.add(k)) & 0xffffffffL;
            Address target = table.add(w);
            long delta = target.getOffset() - bctr.getOffset();
            int insn = 0x48000000 | (int) (delta & 0x03fffffcL);
            clearListing(bctr, bctr.add(3));
            setInt(bctr, insn);
            disassemble(bctr);
            println("PATCHED " + arg + " -> b " + target);
        }
    }
}
