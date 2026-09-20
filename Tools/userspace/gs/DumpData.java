import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.data.*;
import java.io.*;
/* DumpData.java OUT.tsv - every defined data item of the program: address, memory block, primary symbol (or "-"), data type, length,
 * pointer target (address of the referenced item, "-" if not a pointer/reference), target symbol name. Used by Tools/userspace/link_corpus.py to type the
 * DAT_/PTR_/s_ data labels the decompiler output refers to. */
public class DumpData extends GhidraScript {
    public void run() throws Exception {
        String out = getScriptArgs()[0];
        Listing listing = currentProgram.getListing();
        SymbolTable st = currentProgram.getSymbolTable();
        try (FileWriter w = new FileWriter(out)) {
            DataIterator it = listing.getDefinedData(true);
            while (it.hasNext()) {
                Data d = it.next();
                Address a = d.getMinAddress();
                MemoryBlock b = currentProgram.getMemory().getBlock(a);
                Symbol s = st.getPrimarySymbol(a);
                String tgt = "-", tname = "-";
                if (d.isPointer()) {
                    Object v = d.getValue();
                    if (v instanceof Address) {
                        Address ta = (Address) v; tgt = Long.toHexString(ta.getOffset());
                        Symbol ts = st.getPrimarySymbol(ta); if (ts != null) tname = ts.getName(true);
                    }
                }
                w.write("0x" + Long.toHexString(a.getOffset()) + "\t" + (b == null ? "-" : b.getName()) + "\t" + (s == null ? "-" : s.getName(true)) + "\t" + d.getDataType().getName() + "\t" + d.getLength() + "\t" + tgt + "\t" + tname + "\n");
            }
        }
        // every label (also on undefined bytes), so that names the decompiler prints for plain labels (`TType::vtable`) can be found
        try (FileWriter w2 = new FileWriter(out + ".syms")) {
            SymbolIterator si = st.getAllSymbols(true);
            while (si.hasNext()) {
                Symbol s = si.next();
                if (s.getSymbolType() != SymbolType.LABEL || s.isExternal()) continue;
                Address a = s.getAddress();
                MemoryBlock b = currentProgram.getMemory().getBlock(a);
                if (b == null) continue;
                w2.write("0x" + Long.toHexString(a.getOffset()) + "\t" + b.getName() + "\t" + s.getName(true) + "\n");
            }
        }
    }
}
