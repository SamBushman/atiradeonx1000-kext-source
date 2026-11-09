import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.listing.Function.FunctionUpdateType;
import ghidra.program.model.symbol.Namespace;
import ghidra.program.model.symbol.SourceType;
import java.util.*;

// Usage: -postScript MoveEntries.java <hexOldEntry>:<hexTrueEntry>...
// Functions whose first instructions gcc scheduled before `mfspr r0,lr` (`cmpwi cr7,r4,0`, `mfcr r2; cmplwi cr7,r3,5`, `stmw ..; or. r28,r5,r5`):
// auto-analysis started the function at the `mfspr`, so the compare became an orphan and the decompile tested an uninitialised `in_cr7` /
// `in_cr0` (GLDriver FUN_0010b334 lost five of its six switch cases). The stock reaches them only at the true entry (data pointers). Each function
// is removed and re-created at the true entry (the instruction after the preceding blr / b / bctr); a default FUN_ name follows the new address,
// other names and the signature (return, parameters and their storage, calling convention) are carried over. Run on a COPY, then
// RedumpContaining.java on the new entries.
public class MoveEntries extends GhidraScript {
    @Override
    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        for (String arg : getScriptArgs()) {
            String[] p = arg.split(":");
            Address oldE = toAddr(Long.parseLong(p[0].replace("0x", ""), 16)), newE = toAddr(Long.parseLong(p[1].replace("0x", ""), 16));
            Function f = fm.getFunctionAt(oldE);
            if (f == null) { println("MOVE no function at " + oldE); continue; }
            String name = f.getName(); boolean dflt = name.startsWith("FUN_");
            String cc = f.getCallingConventionName(); boolean custom = f.hasCustomVariableStorage();
            Parameter ret = f.getReturn();
            List<Parameter> ps = new ArrayList<>();
            for (Parameter q : f.getParameters())
                ps.add(custom ? new ParameterImpl(q.getName(), q.getDataType(), q.getVariableStorage(), currentProgram, SourceType.USER_DEFINED)
                              : new ParameterImpl(q.getName(), q.getDataType(), currentProgram, SourceType.USER_DEFINED));
            Namespace ns = f.getParentNamespace();
            ghidra.program.model.address.AddressSet body = new ghidra.program.model.address.AddressSet(f.getBody());
            body.addRange(newE, oldE.subtract(1));   // the old body plus the instructions before the old entry
            fm.removeFunction(oldE);
            Function g = null;
            try { g = fm.createFunction(dflt ? null : name, newE, body, SourceType.USER_DEFINED); }
            catch (Exception ex) {   // e.g. OverlappingFunctionException: say what already occupies the new entry, restore the old function, go on with the next move
                Function at = fm.getFunctionContaining(newE);
                println("MOVE FAILED " + oldE + " -> " + newE + ": " + ex.getMessage() + " (function containing the new entry: " + (at == null ? "none" : at.getName(true) + " @ " + at.getEntryPoint() + " body " + at.getBody().getMinAddress() + ".." + at.getBody().getMaxAddress()) + ")");
                // another function's body (a sparse range) has absorbed the run before the old entry: take the run out of that body and create the function at the true entry
                if (at != null && !at.getEntryPoint().equals(newE) && at.getBody().contains(newE)) {
                    ghidra.program.model.address.AddressSet nb = new ghidra.program.model.address.AddressSet(at.getBody());
                    nb.deleteRange(newE, oldE.subtract(1));
                    try { at.setBody(nb); g = fm.createFunction(dflt ? null : name, newE, body, SourceType.USER_DEFINED); println("MOVE (run taken out of " + at.getName() + ") " + oldE + " -> " + newE); }
                    catch (Exception ex3) { println("MOVE retry FAILED " + oldE + " -> " + newE + ": " + ex3.getMessage()); }
                }
                if (g == null) {
                    try { fm.createFunction(name, oldE, new ghidra.program.model.address.AddressSet(f.getBody()), SourceType.USER_DEFINED); } catch (Exception ex2) { println("MOVE could not restore " + oldE + ": " + ex2.getMessage()); }
                    continue;
                }
            }
            if (g == null) { println("MOVE could not create at " + newE); continue; }
            if (!dflt && ns != null) g.setParentNamespace(ns);
            g.updateFunction(cc, ret, ps, custom ? FunctionUpdateType.CUSTOM_STORAGE : FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED);
            println("MOVE " + oldE + " -> " + newE + " " + g.getName(true) + " body " + g.getBody().getMinAddress() + ".." + g.getBody().getMaxAddress());
        }
    }
}
