// DefineWords.java <hexaddr> <count>... - defines `undefined4` data at COUNT consecutive words from each start address (an already defined item is left alone).
// Used for GLEngine's 16 AltiVec constant words 0x113e10..0x113e4f (__const, read by _glePreInitVectorTOC / _gleInitVectorConstants through lvx in the stock): with no data type the decompiler
// printed `_DAT_00113e10` / `_UNK_00113e14`, link_corpus.py gave an untyped label the default `unsigned char`, and the rebuilt code copied the FIRST BYTE of each word (0 instead of 0x1a / 0x1c / 0x1e ...).
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;

public class DefineWords extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        for (int i = 0; i + 1 < a.length; i += 2) {
            Address s = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(a[i].startsWith("0x") ? a[i].substring(2) : a[i]);
            int n = Integer.parseInt(a[i + 1]);
            for (int k = 0; k < n; k++) {
                Address w = s.add(4L * k);
                Data d = currentProgram.getListing().getDataAt(w);
                if (d != null && d.isDefined()) { println("DEFINEWORDS " + w + " already " + d.getDataType().getName()); continue; }
                currentProgram.getListing().createData(w, new Undefined4DataType());
                println("DEFINEWORDS " + w + " undefined4");
            }
        }
    }
}
