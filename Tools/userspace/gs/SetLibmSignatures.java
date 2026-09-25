import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.listing.Function.FunctionUpdateType;
import ghidra.program.model.symbol.SourceType;
import java.util.*;

// Usage: -postScript SetLibmSignatures.java
// The libm imports had no signature (Ghidra: `undefined name()`, result in r3), so every caller's decompile read the result from r3 or as an
// unassigned `extraout_f1`, and the corpus declared them `int` - the rebuilt images used garbage for every sqrt/pow/floor/sin... result (GLDriver's
// float formatter printed every exponent as `e00`). Gives each import and its PIC stub (every function of that name) the C prototype with Darwin
// storage: doubles/floats in f1, f2; an integer or pointer after a double in r5 (the double shadows r3/r4). Run on a COPY of the project, then
// RedumpContaining.java on the callers.
public class SetLibmSignatures extends GhidraScript {
    @Override
    public void run() throws Exception {
        Map<String, String> sig = new HashMap<>();
        for (String n : "log log10 log2 sqrt sin cos tan exp exp2 floor ceil fabs atan asin acos round trunc rint sinh cosh tanh cbrt nearbyint".split(" ")) { sig.put(n, "d:d"); sig.put(n + "f", "f:f"); }
        for (String n : "pow fmod atan2 hypot".split(" ")) { sig.put(n, "d:dd"); sig.put(n + "f", "f:ff"); }
        sig.put("frexp", "d:dp"); sig.put("ldexp", "d:di"); sig.put("modf", "d:dp"); sig.put("atof", "d:p"); sig.put("strtod", "d:pp");
        int n = 0;
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) apply(f, sig) ;
        for (Function f : currentProgram.getFunctionManager().getExternalFunctions()) apply(f, sig);
        println("LIBM " + count + " functions");
    }
    int count = 0;
    void apply(Function f, Map<String, String> sig) throws Exception {
        String nm = f.getName().replaceFirst("^_+", "");
        String s = sig.get(nm);
        if (s == null) return;
        String[] rp = s.split(":");
        DataType rt = rp[0].equals("d") ? DoubleDataType.dataType : FloatDataType.dataType;
        List<Parameter> ps = new ArrayList<>();
        int g = 0, fr = 0;
        for (char c : rp[1].toCharArray()) {
            DataType dt; VariableStorage vs;
            if (c == 'd' || c == 'f') {
                dt = c == 'd' ? DoubleDataType.dataType : FloatDataType.dataType;
                vs = new VariableStorage(currentProgram, currentProgram.getRegister("f" + (1 + fr)));
                fr++; g += c == 'd' ? 2 : 1;
            } else {
                dt = c == 'p' ? new PointerDataType(VoidDataType.dataType) : IntegerDataType.dataType;
                vs = new VariableStorage(currentProgram, currentProgram.getRegister("r" + (3 + g)));
                g++;
            }
            ps.add(new ParameterImpl("param_" + (ps.size() + 1), dt, vs, currentProgram, SourceType.USER_DEFINED));
        }
        ReturnParameterImpl ret = new ReturnParameterImpl(rt, new VariableStorage(currentProgram, currentProgram.getRegister("f1")), currentProgram);
        f.updateFunction(f.getCallingConventionName(), ret, ps, FunctionUpdateType.CUSTOM_STORAGE, true, SourceType.USER_DEFINED);
        count++;
        println("LIBM " + f.getEntryPoint() + " " + f.getName(true) + " " + f.getSignature().getPrototypeString());
    }
}
