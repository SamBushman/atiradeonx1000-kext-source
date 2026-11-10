// A Mach-O local data symbol is a C `static`: two source files each define `static ... _gleVAPrologRTC[]`, and the stripped-of-nothing symbol table lists both names at
// different addresses (21 names in GLEngine's RTC code templates; each one is a different chunk of machine code). Ghidra prints a label's NAME at every reference, so the
// decompiled C says `&_gleVADoubleFlushDataRTC` for BOTH chunks and the link tree (link_corpus.py: one label per name, a later definition is skipped) binds every use to the
// FIRST address - the builders then copy the wrong template into the generated code (found by the RTC-builder mock, gleng_mock_rtcbuild: stock chunk 0x10c070 vs
// rebuilt 0x10b318). UniqueNames.java does the same for functions; this does it for data labels: every label whose name sits on two or more addresses of an initialised
// block gets `<name>_<address>` (all members, like UniqueNames). Prints the renames and, per renamed address, the entries of the functions that reference it
// (UNIQUEDATA_REFS entry...), which RedumpContaining.java then re-decompiles.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class UniqueDataNames extends GhidraScript {
    @Override
    public void run() throws Exception {
        SymbolTable st = currentProgram.getSymbolTable();
        Memory mem = currentProgram.getMemory();
        Map<String, List<Symbol>> byName = new LinkedHashMap<>();
        for (Symbol s : st.getAllSymbols(false)) {
            if (s.getSymbolType() != SymbolType.LABEL || s.isExternal()) continue;
            Address a = s.getAddress();
            if (!a.isMemoryAddress()) continue;
            MemoryBlock b = mem.getBlock(a);
            if (b == null || !b.isInitialized() || b.isExecute()) continue;      // data blocks only: a label in __text is a switch/case label
            if (currentProgram.getFunctionManager().getFunctionAt(a) != null) continue;      // functions: UniqueNames.java
            if (s.getName().matches("^(DAT|PTR|LAB|s|u|FLOAT|DOUBLE|lbl|switchD|caseD|SUB|FUN|thunk)(_.*)?")) continue;      // default names already carry the address
            byName.computeIfAbsent(s.getName(), k -> new ArrayList<>()).add(s);
        }
        int renamed = 0;
        TreeSet<String> entries = new TreeSet<>();
        for (Map.Entry<String, List<Symbol>> e : byName.entrySet()) {
            Set<Address> addrs = new TreeSet<>();
            for (Symbol s : e.getValue()) addrs.add(s.getAddress());
            if (addrs.size() < 2) continue;
            for (Symbol s : e.getValue()) {
                String nn = e.getKey() + "_" + s.getAddress().toString().replaceAll("^0*", "");
                println("UNIQUEDATA " + e.getKey() + " @ " + s.getAddress() + " -> " + nn);
                for (Reference r : getReferencesTo(s.getAddress())) {
                    Function f = getFunctionContaining(r.getFromAddress());
                    if (f != null) entries.add(Long.toHexString(f.getEntryPoint().getOffset()));
                }
                s.setName(nn, SourceType.USER_DEFINED);
                renamed++;
            }
        }
        println("UNIQUEDATA renamed " + renamed + " labels in " + entries.size() + " referencing functions");
        println("UNIQUEDATA_REFS " + String.join(" ", entries));
    }
}
