import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Instruction;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

// Usage: -postScript PatchConstSwitch.java <hexBctr>...
// For the constant-selector idiom (`lwz r0,K(rBase); add r0,r0,rBase; mtctr r0; bctr` + offset table) whose JumpTable override the decompiler will not
// honour (a guard on an unrelated variable defeats it), rewrite the analysed copy's `bctr` as the equivalent direct `b target`. Only the Ghidra
// project's copy of the bytes changes; the stock binary is untouched.
public class PatchConstSwitch extends GhidraScript {
    @Override
    public void run() throws Exception {
        Pattern lwzc = Pattern.compile("^(0x[0-9a-fA-F]+|-?\\d+)\\((r\\d+)\\)$");
        for (String arg : getScriptArgs()) {
            Address bctr = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(arg.replace("0x", ""));
            Instruction bi = getInstructionAt(bctr);
            if (bi == null || !bi.getMnemonicString().equals("bctr")) { println("SKIP " + arg); continue; }
            String base = null, ld = null; long k = -1;
            Instruction p = bi.getPrevious();
            for (int i = 0; i < 24 && p != null; i++, p = p.getPrevious()) {
                String m = p.getMnemonicString();
                if (m.equals("add") && base == null) {
                    String d = p.getDefaultOperandRepresentation(0), a = p.getDefaultOperandRepresentation(1), b = p.getDefaultOperandRepresentation(2);
                    if (d.equals(a) || d.equals(b)) { ld = d; base = d.equals(a) ? b : a; }
                } else if (base != null && k < 0 && m.equals("lwz") && p.getDefaultOperandRepresentation(0).equals(ld)) {
                    Matcher mm = lwzc.matcher(p.getDefaultOperandRepresentation(1));
                    if (mm.matches() && mm.group(2).equals(base)) k = Long.decode(mm.group(1));
                }
            }
            if (k < 0) { println("SKIP " + arg + " (not constant-selector)"); continue; }
            Address table = bctr.add(4);
            long w = getInt(table.add(k)) & 0xffffffffL;
            Address target = table.add(w);
            long delta = target.getOffset() - bctr.getOffset();
            int insn = 0x48000000 | (int) (delta & 0x03fffffcL);
            clearListing(bctr, bctr.add(3));
            setInt(bctr, insn);
            disassemble(bctr);
            println("PATCHED " + arg + " -> b " + target);
        }
    }
}
