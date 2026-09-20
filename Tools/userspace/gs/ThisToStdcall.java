// Turn every __thiscall function into a __stdcall one whose first parameter is the object, so the decompiler prints the object at every call site
// (for __thiscall it prints `Class::method(args)` and drops the hidden `this`, which the C corpus then has to guess).
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.data.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class ThisToStdcall extends GhidraScript {
    @Override
    public void run() throws Exception {
        int n = 0, bad = 0, ne = 0, nm = 0;
        Map<String, List<Function>> ext = new HashMap<>();     // mangled import name -> external placeholders (overloads share a demangled name, so only the mangled name is safe)
        for (FunctionIterator ei = currentProgram.getFunctionManager().getExternalFunctions(); ei.hasNext();) {
            Function e = ei.next();
            ExternalLocation el = e.getExternalLocation();
            if (el == null) continue;
            for (String s : new String[]{el.getOriginalImportedName(), el.getLabel()}) if (s != null) ext.computeIfAbsent(s, k -> new ArrayList<>()).add(e);
        }
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            if (f.isExternal()) continue;
            if (!"__thiscall".equals(f.getCallingConventionName())) continue;
            List<Parameter> ps = new ArrayList<>();
            for (Parameter p : f.getParameters()) ps.add(p);
            List<ParameterImpl> keep = new ArrayList<>();
            for (Parameter p : ps) keep.add(new ParameterImpl(p.isAutoParameter() ? "this" : p.getName(), p.getDataType(), currentProgram));
            try {
                f.setCallingConvention("__stdcall");
                boolean auto = false;
                for (Parameter p : f.getParameters()) if (p.isAutoParameter()) auto = true;
                if (auto) { bad++; continue; }
                f.replaceParameters(keep, Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED);
                n++;
                Set<Function> es = new LinkedHashSet<>();
                for (Symbol sy : currentProgram.getSymbolTable().getSymbols(f.getEntryPoint())) { List<Function> l = ext.get(sy.getName()); if (l != null) es.addAll(l); }
                for (Function e : es) {
                    if (e == f) continue;
                    e.setCustomVariableStorage(false);
                    e.setCallingConvention("__stdcall");
                    e.replaceParameters(new ArrayList<>(keep), Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED);
                    e.setReturnType(f.getReturnType(), SourceType.USER_DEFINED);
                    ne++;
                }
                if (es.isEmpty()) nm++;
            } catch (Exception e) { bad++; println("FAIL " + f.getName() + " " + e); }
        }
        println("THISTOSTDCALL converted " + n + " problems " + bad + " externals updated " + ne + " methods with no external " + nm);
    }
}
