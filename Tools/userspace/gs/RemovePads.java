import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import java.util.ArrayList;
public class RemovePads extends GhidraScript {
    @Override
    public void run() throws Exception {
        ArrayList<Function> l = new ArrayList<>();
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) if (f.getName().startsWith("eh_pad_")) l.add(f);
        for (Function f : l) removeFunction(f);
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) if (f.getName().contains("Unwind_Resume")) f.setNoReturn(false);
        println("removed " + l.size() + " pad functions; noreturn cleared");
    }
}
