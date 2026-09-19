import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.pcode.JumpTable;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

// Usage: -postScript FixSwitches.java <hexBctr1> [<hexBctr2> ...]
// PowerPC/Darwin embedded jump tables: `[lwzx r0,rIdx,rBase | lwz r0,K(rBase)] ; add r0,r0,rBase ; mtctr r0 ; ... ; bctr` followed by a table of
// 32-bit offsets relative to the table start (= address of the word after the bctr). Ghidra's switch recovery gives up on some of them
// ("Could not recover jumptable ... Too many branches"); this writes the JumpTable override the decompiler honours.
//   lwzx  : n = MAX+1 from the guard `cmplwi crN,rX,MAX` found in the preceding instructions
//   lwz K : a constant selector: exactly one target, entry K/4
public class FixSwitches extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        int done = 0;
        for (String arg : args) {
            String hex = arg.startsWith("0x") ? arg.substring(2) : arg;
            Address bctr = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(hex);
            Instruction bi = getInstructionAt(bctr);
            Function fn = getFunctionContaining(bctr);
            if (bi == null || fn == null || !bi.getMnemonicString().equals("bctr")) { println("SKIP " + arg + " (no bctr/function)"); continue; }
            // walk back up to 16 instructions
            Instruction p = bi.getPrevious();
            String mode = null; long k = 0; int max = -1; String baseReg = null; String ldReg = null;
            Pattern lwzc = Pattern.compile("^(0x[0-9a-fA-F]+|-?\\d+)\\((r\\d+)\\)$");
            boolean sawAdd = false;
            for (int i = 0; i < 32 && p != null; i++, p = p.getPrevious()) {
                String m = p.getMnemonicString();
                if (m.equals("add") && !sawAdd) {
                    String d = p.getDefaultOperandRepresentation(0), a = p.getDefaultOperandRepresentation(1), b = p.getDefaultOperandRepresentation(2);
                    if (d.equals(a) || d.equals(b)) { ldReg = d; baseReg = d.equals(a) ? b : a; sawAdd = true; }
                } else if (sawAdd && mode == null && m.equals("lwzx") && p.getDefaultOperandRepresentation(0).equals(ldReg)) {
                    mode = "lwzx";
                } else if (sawAdd && mode == null && m.equals("lwz") && p.getDefaultOperandRepresentation(0).equals(ldReg)) {
                    Matcher mm = lwzc.matcher(p.getDefaultOperandRepresentation(1));
                    if (mm.matches() && mm.group(2).equals(baseReg)) { mode = "lwz"; k = Long.decode(mm.group(1)); }
                } else if ((m.equals("cmplwi") || m.equals("cmpwi")) && max < 0) {
                    try { max = (int) Long.decode(p.getDefaultOperandRepresentation(2).replace("0x", "0x")).longValue(); } catch (Exception e) { }
                }
            }
            if (mode == null) { println("SKIP " + arg + " (not the embedded-table idiom)"); continue; }
            Address table = bctr.add(4);
            int n;
            if (mode.equals("lwz")) n = (int) (k / 4) + 1; else if (max >= 0 && max < 512) n = max + 1; else n = 0;
            ArrayList<Address> dests = new ArrayList<>();
            long base = table.getOffset();
            if (n == 0) {
                // no guard: the case code starts right after the table, so the table ends where 4*n reaches the smallest offset seen so far
                long minW = 0x7fffffffL;
                for (int i = 0; i < 256; i++) {
                    long w = getInt(table.add(4L * i)) & 0xffffffffL;
                    if (4L * i >= minW) break;
                    if ((w & 3) != 0 || w > 0x4000 || w < 4L * (i + 1) && w < 4L) break;
                    if (w < minW) minW = w;
                    n++;
                }
            }
            if (n <= 0) { println("SKIP " + arg + " (no entries)"); continue; }
            boolean ok = true;
            for (int i = 0; i < n; i++) {
                if (mode.equals("lwz") && i != k / 4) { continue; }
                long w = getInt(table.add(4L * i)) & 0xffffffffL;
                Address t = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(base + w);
                if ((w & 3) != 0 || getInstructionAt(t) == null && !disassemble(t)) { ok = false; println("BAD target " + t + " for " + arg); break; }
                if (!dests.contains(t)) dests.add(t);
            }
            if (!ok || dests.isEmpty()) { println("SKIP " + arg + " (invalid table)"); continue; }
            JumpTable jt = new JumpTable(bctr, dests, true, 0);
            jt.writeOverride(fn);
            println("OK " + arg + " mode=" + mode + " n=" + dests.size() + " in " + fn.getName());
            done++;
        }
        println("FixSwitches: overrides written = " + done);
    }
}
