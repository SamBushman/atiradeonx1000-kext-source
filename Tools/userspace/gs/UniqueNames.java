// Ghidra prints the DEMANGLED name at every call, and the demangler is not injective: overloads (`TInfoSinkBase::append`), template instances and
// the pool_allocator `basic_string` instances (printed as `std::string`) share one printed name, as do same-named C statics of different source files. The C
// corpus then binds every such call to the first function of that name (a wrong overload / the wrong class's method). This script gives every member of
// a colliding group a unique name BEFORE the decompile: the mangled Mach-O symbol when the function has one, else `<name>_<address>`.
// Externals (dyld import placeholders) that name the same symbol as an internal function take that function's new name.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.address.*;
import java.util.*;

public class UniqueNames extends GhidraScript {
    String mangledOf(Function f) {
        if (f.isExternal()) {
            ExternalLocation el = f.getExternalLocation();
            if (el != null) { String o = el.getOriginalImportedName(); if (o != null && o.startsWith("_")) return o; }
            return null;
        }
        String best = null;
        for (Symbol s : currentProgram.getSymbolTable().getSymbols(f.getEntryPoint())) {
            String n = s.getName();
            if (s.getSource() == SourceType.IMPORTED && n.startsWith("_")) { if (best == null || n.compareTo(best) < 0) best = n; }
        }
        return best;
    }
    Namespace libOf(Function f) {
        Namespace ns = f.getParentNamespace();
        while (ns != null && !(ns instanceof Library) && !ns.isGlobal()) ns = ns.getParentNamespace();
        return ns == null ? currentProgram.getGlobalNamespace() : ns;
    }
    @Override
    public void run() throws Exception {
        List<Function> all = new ArrayList<>();
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) if (!f.isThunk()) all.add(f);
        for (FunctionIterator ei = currentProgram.getFunctionManager().getExternalFunctions(); ei.hasNext();) { Function e = ei.next(); if (!all.contains(e)) all.add(e); }
        // entity = internal function (by address) or external (by mangled/imported name); an external whose name equals an internal's mangled symbol is that internal
        Map<String, Function> internalByMangled = new HashMap<>();
        Map<Function, String> mangled = new HashMap<>();
        Map<String, Integer> symCount = new HashMap<>();
        for (Function f : all) { String m = mangledOf(f); mangled.put(f, m); if (m != null && !f.isExternal()) symCount.merge(m, 1, Integer::sum); }
        for (Function f : all) {
            if (f.isExternal()) continue;
            for (Symbol s : currentProgram.getSymbolTable().getSymbols(f.getEntryPoint()))
                if (s.getSource() == SourceType.IMPORTED && s.getName().startsWith("_") && symCount.getOrDefault(s.getName(), 0) == 1) internalByMangled.put(s.getName(), f);   // a name two internal functions share (C statics) names no import
        }
        Map<String, List<Function>> groups = new LinkedHashMap<>();
        for (Function f : all) {
            if (f.isExternal() && mangled.get(f) != null && internalByMangled.containsKey(mangled.get(f))) continue;     // same entity as the internal function
            groups.computeIfAbsent(f.getName(true).replaceAll("^<EXTERNAL>::", "").replaceAll("^[^:]*\\.dylib::", ""), k -> new ArrayList<>()).add(f);
        }
        int renamed = 0, extRenamed = 0, skipped = 0;
        Map<Function, String> newName = new HashMap<>();
        for (Map.Entry<String, List<Function>> g : groups.entrySet()) {
            // distinct entities: dedupe externals that are the same import
            Map<String, Function> ents = new LinkedHashMap<>();
            for (Function f : g.getValue()) ents.putIfAbsent(f.isExternal() ? "E:" + mangled.get(f) : "I:" + f.getEntryPoint(), f);
            if (ents.size() < 2) continue;
            for (Function f : g.getValue()) {
                String m = mangled.get(f);
                String nn = (m != null && symCount.getOrDefault(m, 0) <= 1) ? m : (f.isExternal() ? (m != null ? m : null) : f.getName() + "_" + f.getEntryPoint().toString().replaceAll("^0*", ""));
                if (nn == null) { skipped++; continue; }
                newName.put(f, nn);
            }
        }
        for (Map.Entry<Function, String> e : newName.entrySet()) {
            Function f = e.getKey();
            try {
                if (f.isExternal()) { f.setParentNamespace(libOf(f)); f.setName(e.getValue(), SourceType.USER_DEFINED); extRenamed++; }
                else {
                    Symbol pri = null;
                    for (Symbol s : currentProgram.getSymbolTable().getSymbols(f.getEntryPoint())) if (s.getName().equals(e.getValue())) pri = s;
                    if (f.getName().equals(e.getValue()) && f.getParentNamespace().isGlobal()) continue;   // already named so
                    if (pri != null && pri != f.getSymbol()) pri.delete();               // the mangled symbol is already there as a secondary label: it becomes the function's own name
                    f.setParentNamespace(currentProgram.getGlobalNamespace()); f.setName(e.getValue(), SourceType.USER_DEFINED);
                    renamed++;
                }
            } catch (Exception ex) { println("FAIL " + f.getName(true) + " -> " + e.getValue() + ": " + ex); skipped++; }
        }
        // externals that are the same entity as a renamed internal function
        for (Function f : all) {
            if (!f.isExternal()) continue;
            String m = mangled.get(f);
            Function in = m == null ? null : internalByMangled.get(m);
            if (in != null && newName.containsKey(in) && !newName.containsKey(f)) {
                try { f.setParentNamespace(libOf(f)); f.setName(newName.get(in), SourceType.USER_DEFINED); extRenamed++; } catch (Exception ex) { println("FAIL ext " + f.getName(true) + ": " + ex); skipped++; }
            }
        }
        println("UNIQUENAMES groups renamed: internal " + renamed + " external " + extRenamed + " skipped " + skipped);
    }
}
