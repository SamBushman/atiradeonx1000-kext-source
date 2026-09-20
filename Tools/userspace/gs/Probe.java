import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
public class Probe extends GhidraScript {
    public void run() throws Exception {
        String pat = getScriptArgs()[0];
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            String on = null;
            if (f.isExternal() && f.getExternalLocation() != null) on = f.getExternalLocation().getOriginalImportedName();
            String nm = f.getName();
            if ((on != null && on.contains(pat)) || nm.contains(pat)) println("F at=" + f.getEntryPoint() + " blk=" + (currentProgram.getMemory().getBlock(f.getEntryPoint()) == null ? "-" : currentProgram.getMemory().getBlock(f.getEntryPoint()).getName()) + " thunk=" + f.isThunk() + " ext=" + f.isExternal() + " name=" + nm.substring(0, Math.min(60, nm.length())) + " orig=" + (on == null ? null : on.substring(0, Math.min(90, on.length()))) + " sig=" + f.getSignature().getPrototypeString() + " cc=" + f.getCallingConventionName());
        }
    }
}
