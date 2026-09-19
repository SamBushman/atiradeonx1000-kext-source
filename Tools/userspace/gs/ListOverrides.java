import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;
public class ListOverrides extends GhidraScript {
    @Override
    public void run() throws Exception {
        for (String x : getScriptArgs()) {
            Address ad = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(x.replace("0x", ""));
            Function f = getFunctionContaining(ad);
            println("function " + f.getName() + " @ " + f.getEntryPoint() + " ns=" + f.getParentNamespace().getName());
            SymbolIterator it = currentProgram.getSymbolTable().getChildren(f.getSymbol());
            while (it.hasNext()) { Symbol s = it.next(); if (s.getName().equals("override")) { SymbolIterator it2 = currentProgram.getSymbolTable().getChildren(s); while (it2.hasNext()) { Symbol s2 = it2.next(); println("    " + s2.getName() + " @ " + s2.getAddress() + " " + s2.getSymbolType()); SymbolIterator it3 = currentProgram.getSymbolTable().getChildren(s2); while (it3.hasNext()) { Symbol s3 = it3.next(); println("       " + s3.getName() + " @ " + s3.getAddress()); } } }
 if (s.getName().contains("jmp") || s.getName().contains("override") || s.getName().contains("Switch") || s.getName().startsWith("switch")) println("  " + s.getName() + " @ " + s.getAddress() + " type=" + s.getSymbolType()); }
        }
    }
}
