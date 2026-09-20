// CopySigToStubs.java - a call to a function of this image that lives in a coalesced/weak section goes through a dyld PIC stub, which Ghidra makes a function of
// its own (same name, `unknown` calling convention, a one-parameter guess). The decompiler prints a call's arguments from the STUB's signature, so every such call
// lost the arguments the real function takes. Give each stub the signature of the real function of the same name.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.SourceType;
import java.util.*;

public class CopySigToStubs extends GhidraScript {
    boolean isStub(Function f) {
        MemoryBlock mb = currentProgram.getMemory().getBlock(f.getEntryPoint());
        return mb != null && mb.getName().toLowerCase().contains("stub");
    }
    @Override
    public void run() throws Exception {
        Map<String, Function> bySym = new HashMap<>();       // any symbol at a real function's entry (the mangled one included) -> function
        Map<String, List<Function>> byName = new HashMap<>();  // plain name -> functions (overloads and same-named methods of other classes share it)
        List<Function> stubs = new ArrayList<>();
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            if (f.isExternal()) continue;
            if (f.isThunk() || isStub(f)) { stubs.add(f); continue; }
            byName.computeIfAbsent(f.getName(), k -> new ArrayList<>()).add(f);
            for (ghidra.program.model.symbol.Symbol sy : currentProgram.getSymbolTable().getSymbols(f.getEntryPoint())) bySym.putIfAbsent(sy.getName(), f);
        }
        int n = 0, none = 0, bad = 0;
        for (Function s : stubs) {
            Function r = null;
            Function e = s.isThunk() ? s.getThunkedFunction(true) : null;
            if (e != null && e.getExternalLocation() != null) {
                String on = e.getExternalLocation().getOriginalImportedName();
                if (on != null) r = bySym.get(on);
            }
            if (r == null) r = bySym.get(s.getName());
            if (r == null) { List<Function> l = byName.get(s.getName()); if (l != null && l.size() == 1) r = l.get(0); }   // only when the name is unambiguous
            if (r == null) { none++; continue; }
            try {
                Function target = s.isThunk() ? s.getThunkedFunction(true) : s;    // a thunk shows the signature of what it thunks (the import placeholder)
                if (target == null) { none++; continue; }
                List<Variable> ps = new ArrayList<>();
                for (Parameter p : r.getParameters()) ps.add(new ParameterImpl(p.getName(), p.getDataType(), currentProgram));
                target.setCustomVariableStorage(false);
                target.setCallingConvention("__stdcall");
                target.replaceParameters(ps, Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED);
                target.setReturnType(r.getReturnType(), SourceType.USER_DEFINED);
                n++;
            } catch (Exception ex) { bad++; println("FAIL " + s.getName() + ": " + ex); }
        }
        println("COPYSIGTOSTUBS stubs " + stubs.size() + " updated " + n + " without a real function " + none + " failed " + bad);
    }
}
