import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.pcode.HighFunctionDBUtil;

// Usage: -postScript SetCallSigs.java <callAddrHex>:<nInt>:<nDouble>...
// An indirect call or indirect TAIL call (`mtctr; bctr`: a slot of the context, a dispatch pointer) has no signature; for a `bctr` the decompiler guesses ("Treating indirect jump
// as call") and prints only the argument registers it can prove: GLEngine `_glVertex3f_Exec` loads f4 from ctx+0x24 and jumps through ctx+0x4884 with (ctx, f1, f2, f3, f4) but printed
// `(*fn)(param_1)`, `_glVertexAttrib2fvARB_Exec` printed (ctx, idx, ptr, x, y) and lost the two default components f3 / f4 the stock loads from ctx+0x20 / +0x24 - the rebuilt C passed
// whatever f3 / f4 held (found by the recording-callback fuzz, fnfuzz `fnrecv`/`fnrecw` slots). indirect_args.py / OverrideIndirectCalls.java / ExtendIndirectCalls.java count the
// integer registers of `bctrl` only. This script writes a call-site override at each given instruction: <nInt> integer arguments (r3..) followed by <nDouble> doubles (f1..).
// Run on a COPY of the project, then RedumpContaining.java on the functions (and AddDoubleParams.java first for a function that only forwards f1..fN to the call).
public class SetCallSigs extends GhidraScript {
    @Override
    public void run() throws Exception {
        for (String arg : getScriptArgs()) {
            String[] p = arg.split(":");
            Address a = toAddr(Long.parseLong(p[0].replace("0x", ""), 16));
            int nInt = Integer.parseInt(p[1]), nDbl = Integer.parseInt(p[2]);
            Function f = getFunctionContaining(a);
            Instruction ci = getInstructionAt(a);
            if (f == null || ci == null) { println("CALLSIG no function/instruction at " + p[0]); continue; }
            FunctionDefinitionDataType s = new FunctionDefinitionDataType("icall_" + a);
            ParameterDefinition[] ps = new ParameterDefinition[nInt + nDbl];
            for (int i = 0; i < nInt; i++) ps[i] = new ParameterDefinitionImpl("a" + i, Undefined4DataType.dataType, null);
            for (int i = 0; i < nDbl; i++) ps[nInt + i] = new ParameterDefinitionImpl("d" + i, DoubleDataType.dataType, null);
            s.setArguments(ps);
            s.setReturnType(Undefined4DataType.dataType);
            HighFunctionDBUtil.writeOverride(f, a, s);
            println("CALLSIG " + f.getName() + " @ " + a + " (" + ci.getMnemonicString() + "): " + nInt + " int + " + nDbl + " double");
        }
    }
}
