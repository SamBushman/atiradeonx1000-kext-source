import ghidra.app.script.GhidraScript;
import ghidra.app.cmd.function.CreateFunctionCmd;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import java.util.*;

// Finds code Ghidra did not put in any function: disassembles PPC prologues (mflr r0 = 0x7c0802a6) in undefined text, and creates a
// function at every call target that is not yet a function. Repeats until stable. Prints coverage before/after.
public class FindMoreFuncs extends GhidraScript {
    long covered() {
        long c = 0; FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        while (it.hasNext()) c += it.next().getBody().getNumAddresses();
        return c;
    }
    public void run() throws Exception {
        String[] args = getScriptArgs();
        Memory mem = currentProgram.getMemory();
        MemoryBlock text = mem.getBlock("__text");
        if (text == null) text = mem.getBlock(".text");
        println("FMF before " + covered() + " of " + text.getSize());
        boolean ppc = currentProgram.getLanguage().getProcessor().toString().contains("PowerPC");
        int rounds = 0, made = 0;
        boolean changed = true;
        while (changed && rounds < 12) {
            changed = false; rounds++;
            Listing l = currentProgram.getListing();
            // 1. prologue scan in bytes not covered by any function
            if (ppc) {
                Address a = text.getStart();
                byte[] w = new byte[4];
                while (a != null && a.compareTo(text.getEnd()) < 0) {
                    if (getFunctionContaining(a) == null && (a.getOffset() & 3) == 0) {
                        mem.getBytes(a, w);
                        int v = ((w[0] & 0xff) << 24) | ((w[1] & 0xff) << 16) | ((w[2] & 0xff) << 8) | (w[3] & 0xff);
                        if (v == 0x7c0802a6) {   // mflr r0
                            if (l.getInstructionAt(a) == null) { disassemble(a); }
                            if (getFunctionAt(a) == null && l.getInstructionAt(a) != null) {
                                if (createFunction(a, null) != null) { made++; changed = true; }
                            }
                        }
                    }
                    try { a = a.add(4); } catch (Exception e) { break; }
                }
            }
            // 1b. gaps: after leading nops, a word whose opcode is not 0 and a following blr => code without an mflr prologue
            if (ppc) {
                AddressSet gaps = new AddressSet(text.getStart(), text.getEnd());
                for (Function fn : currentProgram.getFunctionManager().getFunctions(true)) gaps.delete(fn.getBody());
                for (AddressRange r : gaps.getAddressRanges()) {
                    if (r.getLength() < 12) continue;
                    long lo = r.getMinAddress().getOffset(), hi = r.getMaxAddress().getOffset() + 1;
                    lo = (lo + 3) & ~3L;
                    byte[] w = new byte[4]; boolean hasBlr = false;
                    long q = lo; Address start = null;
                    while (q + 4 <= hi) {
                        mem.getBytes(toAddr(q), w);
                        int v = ((w[0] & 0xff) << 24) | ((w[1] & 0xff) << 16) | ((w[2] & 0xff) << 8) | (w[3] & 0xff);
                        if (start == null && v != 0x60000000 && v != 0 && ((v >>> 26) != 0)) start = toAddr(q);
                        if (v == 0x4e800020) hasBlr = true;
                        q += 4;
                    }
                    if (start != null && hasBlr) {
                        if (l.getInstructionAt(start) == null) disassemble(start);
                        if (getFunctionContaining(start) == null && l.getInstructionAt(start) != null && createFunction(start, null) != null) { made++; changed = true; }
                    }
                }
            }
            // 2. call targets
            ReferenceManager rm = currentProgram.getReferenceManager();
            AddressIterator ai = rm.getReferenceDestinationIterator(text.getStart(), true);
            while (ai.hasNext()) {
                Address t = ai.next();
                if (!text.contains(t)) continue;
                boolean isCall = false;
                for (Reference r : rm.getReferencesTo(t)) if (r.getReferenceType().isCall()) { isCall = true; break; }
                if (isCall && getFunctionAt(t) == null && getFunctionContaining(t) == null) {
                    if (l.getInstructionAt(t) == null) disassemble(t);
                    if (createFunction(t, null) != null) { made++; changed = true; }
                }
            }
        }
        println("FMF after " + covered() + " made " + made + " rounds " + rounds);
    }
}
