import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;

// Usage: -postScript ListStackParams.java   (read-only)
// Lists every function whose signature has a parameter in stack storage below 0x38. Ghidra's PowerPC cspec is SysV and places the 9th argument word
// at Stack[0x8]; Darwin passes it at 0x38(r1) (ExtendParams.java gives stack parameters explicit Darwin storage). Such a parameter makes callers
// print a value the stock caller never stored there and the callee read the wrong slot.
public class ListStackParams extends GhidraScript {
    @Override
    public void run() throws Exception {
        int n = 0;
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            StringBuilder sb = new StringBuilder();
            for (Parameter q : f.getParameters())
                if (q.isStackVariable() && q.getStackOffset() < 0x38) sb.append(" ").append(q.getName()).append("@").append(q.getVariableStorage());
            if (sb.length() == 0) continue;
            n++;
            println("STACKPARAM " + f.getEntryPoint() + " " + f.getName() + " n=" + f.getParameterCount() + sb);
        }
        println("STACKPARAM " + n + " functions");
    }
}
