import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;
public class DumpRanges extends GhidraScript {
    public void run() throws Exception {
        String out = getScriptArgs()[0];
        try (FileWriter w = new FileWriter(out)) {
            FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
            while (it.hasNext()) {
                Function f = it.next();
                StringBuilder sb = new StringBuilder();
                for (AddressRange r : f.getBody().getAddressRanges()) sb.append(Long.toHexString(r.getMinAddress().getOffset())).append('-').append(Long.toHexString(r.getMaxAddress().getOffset() + 1)).append(';');
                w.write("0x" + Long.toHexString(f.getEntryPoint().getOffset()) + "\t" + f.getName(true) + "\t" + (f.isExternal() ? "ext" : f.isThunk() ? "thunk" : "fn") + "\t" + sb + "\n");
            }
        }
    }
}
