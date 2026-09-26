import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.listing.Function.FunctionUpdateType;
import ghidra.program.model.symbol.SourceType;
import java.util.*;

// Usage: -postScript SetImportSignatures.java
// Imports without a signature: the decompiler prints only the arguments it happens to see at each call. GLDriver called
// `io_connect_method_scalarI_structureI(connect, 0)` where the stock passes all six arguments (the scalar-input array, its count, the struct and its
// size went to the kernel as whatever r5..r8 held); `IOConnectMapMemory`, CF, libSystem and the C++ runtime likewise
// (Tools/userspace/callarg_check.py). Gives every external function and its PIC stub (a thunk of it) the C prototype's argument count - integer or
// pointer words, r3..r10 then Darwin stack slots 0x38+ - and return (r3; none for void). Variadic ones (printf family) keep their per-call-site
// overrides (OverrideVariadicCalls.java); libm is SetLibmSignatures.java. Run on a COPY, then RedumpContaining.java on the call sites.
public class SetImportSignatures extends GhidraScript {
    static final Map<String, Integer> N = new HashMap<>();
    static final Set<String> VOID = new HashSet<>(Arrays.asList("free", "vfree", "exit", "abort", "longjmp", "CFRelease", "IOObjectRelease",
        "bcopy", "__cxa_guard_release", "__cxa_end_catch", "__cxa_rethrow", "__cxa_throw", "__cxa_free_exception", "_Unwind_Resume",
        "CFNotificationCenterAddObserver", "CFNotificationCenterRemoveObserver", "CFNotificationCenterPostNotification", "__eprintf",
        "CFPlugInAddInstanceForFactory", "CFPlugInRemoveInstanceForFactory", "pthread_setspecific_void"));
    static {
        String t = String.join(" ",
            "io_connect_method_scalarI_scalarO:6 io_connect_method_scalarI_structureI:6 io_connect_method_scalarI_structureO:6",
            "io_connect_method_structureI_structureO:6 IOConnectMapMemory:6 IOServiceOpen:4 IOServiceClose:1 IOConnectAddClient:2",
            "IOObjectRelease:1 IOObjectConformsTo:2 IOObjectGetClass:2 IOAccelFindAccelerator:3",
            "calloc:2 malloc:1 free:1 realloc:2 valloc:1 vfree:1 memset:3 memcpy:3 memmove:3 memcmp:3 bcopy:3 strlen:1 strcmp:2 strncmp:3",
            "strcpy:2 strcat:2 strchr:2 index:2 rindex:2 strlcpy:3 getenv:1 getpid:0 exit:1 abort:0 usleep:1 puts:1 fopen:2 fclose:1 fgets:3",
            "fread:4 fwrite:4 popen:2 pclose:1 fflush:1 atoi:1 dlopen:2 dlsym:2 setjmp:1 longjmp:2 pthread_mutex_init:2 pthread_mutex_lock:1",
            "pthread_mutex_unlock:1 pthread_mutex_destroy:1 pthread_mutexattr_init:1 pthread_mutexattr_settype:2 pthread_getspecific:1",
            "pthread_setspecific:2 getsectdatafromheader:4",
            "CFRelease:1 CFRetain:1 CFEqual:2 CFDictionaryCreate:6 CFDictionaryGetValue:2 CFNumberCreate:3 CFNumberGetValue:3",
            "CFStringCreateWithCString:3 CFNotificationCenterGetDistributedCenter:0 CFNotificationCenterAddObserver:6",
            "CFNotificationCenterRemoveObserver:4 CFNotificationCenterPostNotification:5 CFPlugInAddInstanceForFactory:1",
            "CFPlugInRemoveInstanceForFactory:1 CFUUIDCreateFromUUIDBytes:5 CFUUIDGetConstantUUIDWithBytes:17 CGDisplayIDToOpenGLDisplayMask:1",
            "_keymgr_get_and_lock_processwide_ptr:1 _keymgr_set_and_unlock_processwide_ptr:2 _keymgr_get_per_thread_data:1",
            "_keymgr_set_per_thread_data:2 NSIsSymbolNameDefinedWithHint:2 NSLookupAndBindSymbolWithHint:2 NSAddressOfSymbol:1",
            "__cxa_guard_acquire:1 __cxa_guard_release:1 __cxa_allocate_exception:1 __cxa_throw:3 __cxa_begin_catch:1 __cxa_end_catch:0",
            "__cxa_rethrow:0 __cxa_free_exception:1 __cxa_get_globals:0 __cxa_get_globals_fast:0 __cxa_call_unexpected:1 _Unwind_Resume:1",
            "__ashldi3:3 __lshrdi3:3 __ashrdi3:3 __eprintf:4 __isnanf:1",
            // GLDriver's imports from libGLProgrammability (their definitions there: registers each one reads) and libGLImage (not transcribed
            // here: all eight argument registers, so no argument can be dropped; an extra one is ignored)
            "glpPPShaderLinearize:2 glpPPShaderToProgram:3 glpFreePPShaderLinearize:1 glpFreePPShaderToProgram:1 glpUniformToFloat:4",
            "glgConvertType:8 glgProcessPixels:8 glgPixelCenters:8");
        for (String kv : t.split(" ")) { String[] p = kv.split(":"); N.put(p[0], Integer.parseInt(p[1])); }
    }
    int count = 0;
    void apply(Function f) throws Exception {
        String nm = f.getName().replaceFirst("^_", "");
        Integer n = N.get(nm);
        if (n == null) return;
        if (!f.isExternal() && !f.isThunk()) return;   // the image's own function of that name keeps its definition's signature
        List<Parameter> ps = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            VariableStorage vs = i < 8 ? new VariableStorage(currentProgram, currentProgram.getRegister("r" + (3 + i)))
                                       : new VariableStorage(currentProgram, 0x38 + 4 * (i - 8), 4);
            ps.add(new ParameterImpl("param_" + (i + 1), Undefined4DataType.dataType, vs, currentProgram, SourceType.USER_DEFINED));
        }
        Parameter ret = VOID.contains(nm) ? new ReturnParameterImpl(VoidDataType.dataType, VariableStorage.VOID_STORAGE, currentProgram)
                                          : new ReturnParameterImpl(Undefined4DataType.dataType, new VariableStorage(currentProgram, currentProgram.getRegister("r3")), currentProgram);
        f.updateFunction(f.getCallingConventionName(), ret, ps, FunctionUpdateType.CUSTOM_STORAGE, true, SourceType.USER_DEFINED);
        count++;
    }
    @Override
    public void run() throws Exception {
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) apply(f);
        for (Function f : currentProgram.getFunctionManager().getExternalFunctions()) apply(f);
        println("IMPORTSIG " + count + " functions");
    }
}
