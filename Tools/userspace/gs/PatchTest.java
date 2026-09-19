import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.util.task.ConsoleTaskMonitor;

// Usage: PatchTest.java <funcAddr> <bctr:target> ... : restore each bctr (0x4e800420), then patch them one at a time, decompiling after each
public class PatchTest extends GhidraScript {
    void put(Address a, int v) throws Exception { clearListing(a, a.add(3)); setInt(a, v); disassemble(a); }
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        Address fa = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(args[0].replace("0x", ""));
        for (int i = 1; i < args.length; i++) { Address b = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(args[i].split(":")[0].replace("0x", "")); put(b, 0x4e800420); }
        // the JumpTable overrides FixSwitches wrote for this function name the bctr sites; a patched (non-indirect) instruction under an override kills the decompiler
        {
            Function f0 = getFunctionContaining(fa);
            java.util.ArrayList<ghidra.program.model.symbol.Symbol> del = new java.util.ArrayList<>();
            ghidra.program.model.symbol.SymbolIterator it = currentProgram.getSymbolTable().getChildren(f0.getSymbol());
            while (it.hasNext()) { ghidra.program.model.symbol.Symbol s = it.next(); if (s.getName().equals("override")) del.add(s); }
            for (ghidra.program.model.symbol.Symbol s : del) { ghidra.program.model.symbol.SymbolIterator i2 = currentProgram.getSymbolTable().getChildren(s); java.util.ArrayList<ghidra.program.model.symbol.Symbol> k = new java.util.ArrayList<>(); while (i2.hasNext()) k.add(i2.next()); for (ghidra.program.model.symbol.Symbol c : k) { ghidra.program.model.symbol.SymbolIterator i3 = currentProgram.getSymbolTable().getChildren(c); java.util.ArrayList<ghidra.program.model.symbol.Symbol> g = new java.util.ArrayList<>(); while (i3.hasNext()) g.add(i3.next()); for (ghidra.program.model.symbol.Symbol x : g) x.delete(); c.delete(); } s.delete(); }
            println("removed override namespaces: " + del.size());
        }
        String[] styles = {"normalize", "firstpass", "register", "paramid", "decompile"};
        Address b0 = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(args[1].split(":")[0].replace("0x", ""));
        Address t0 = args[1].split(":")[1].startsWith("raw") ? b0 : currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(args[1].split(":")[1].replace("0x", ""));
        int w = args[1].split(":")[1].startsWith("raw") ? (int) Long.parseLong(args[1].split(":")[1].substring(3), 16) : 0x48000000 | (int) ((t0.getOffset() - b0.getOffset()) & 0x03fffffcL);
        put(b0, w);
        for (String st : styles) {
            DecompInterface d = new DecompInterface(); d.openProgram(currentProgram); d.setSimplificationStyle(st);
            Function f = getFunctionContaining(fa);
            DecompileResults r = d.decompileFunction(f, 120, new ConsoleTaskMonitor());
            println("style " + st + ": " + (r != null && r.getDecompiledFunction() != null ? "OK (" + r.getDecompiledFunction().getC().length() + " chars)" : "FAILED completed=" + (r != null && r.decompileCompleted()) + " " + (r == null ? "" : r.getErrorMessage())));
            d.dispose();
        }
    }
}
