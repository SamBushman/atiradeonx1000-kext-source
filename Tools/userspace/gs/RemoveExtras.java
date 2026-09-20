// RemoveExtras.java DUMP_DIR [DUMP_DIR ...] (each holds an INDEX.tsv: the functions to keep) - restore the function set the archived dump was made with: the project also holds the landing-pad (eh_pad_*) and orphan
// (orph_*) functions that CreatePads/CreateOrphans added later for the companion corpora. They change how the main functions print (a data reference into
// such a block turns into a call-like function name), so they are removed before the main dump; the companion dumps are made separately.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import java.util.*;
import java.io.*;

public class RemoveExtras extends GhidraScript {
    @Override
    public void run() throws Exception {
        Set<Long> keep = new HashSet<>();
        for (String dir : getScriptArgs()) {
            try (BufferedReader br = new BufferedReader(new FileReader(new File(dir + "/INDEX.tsv")))) {
                String l;
                while ((l = br.readLine()) != null) keep.add(Long.parseLong(l.split("\t")[0].replace("0x", ""), 16));
            }
        }
        List<Function> rm = new ArrayList<>();
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            if (f.isExternal() || f.isThunk()) continue;
            if (!keep.contains(f.getEntryPoint().getOffset())) rm.add(f);
        }
        List<ghidra.program.model.address.Address> at = new ArrayList<>();
        ghidra.program.model.address.AddressSet blocks = new ghidra.program.model.address.AddressSet();
        for (Function f : rm) { at.add(f.getEntryPoint()); blocks.add(f.getBody()); }
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) if (!f.isExternal() && !f.isThunk() && keep.contains(f.getEntryPoint().getOffset())) blocks.delete(f.getBody());
        for (Function f : rm) removeFunction(f);
        // the archived dump was made before those blocks were disassembled: turn them back into undefined bytes (a data reference into one printed `DAT_/UNK_...`)
        clearListing(blocks);
        // the function's own symbol goes with it, but the labels the block made (`case_5558`, `LAB_..._1`) would print where the archived dump printed `UNK_...`
        int syms = 0;
        for (ghidra.program.model.address.Address a : at)
            for (ghidra.program.model.symbol.Symbol s : currentProgram.getSymbolTable().getSymbols(a))
                if (s.getSource() != ghidra.program.model.symbol.SourceType.IMPORTED && (s.getName().startsWith("case_") || s.getName().startsWith("LAB_") || s.getName().startsWith("orph_") || s.getName().startsWith("eh_pad_"))) { s.delete(); syms++; }
        println("REMOVEEXTRAS deleted " + syms + " leftover labels");
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) if (f.getName().contains("Unwind_Resume")) f.setNoReturn(false);
        println("REMOVEEXTRAS removed " + rm.size() + " functions, kept " + keep.size());
    }
}
