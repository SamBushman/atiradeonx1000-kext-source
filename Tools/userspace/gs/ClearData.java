// ClearData.java <hexaddr>... - removes the defined data item (type) at each address, leaving the bytes undefined and the labels in place.
// Ghidra's string analyzer typed 6 bytes of a machine-code template (GLEngine 0x10c098, an RTC chunk: 7d60212e 7c0004ac ...) as `string` "}`!.|"; the decompiler then
// printed the literal, the C compiled it into __cstring (NUL after 6 bytes) and _gleRTCAddAChunk copied a 2-word chunk instead of the stock's 9-word one.
// With no type the decompiler prints the label's address (&name), which link_corpus.py binds to the real __const bytes.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;

public class ClearData extends GhidraScript {
    @Override
    public void run() throws Exception {
        for (String s : getScriptArgs()) {
            Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(s.startsWith("0x") ? s.substring(2) : s);
            Data d = currentProgram.getListing().getDataContaining(a);
            if (d == null || !d.isDefined()) { println("CLEARDATA " + s + " nothing defined"); continue; }
            println("CLEARDATA " + s + " cleared " + d.getDataType().getName() + " len " + d.getLength() + " at " + d.getMinAddress());
            clearListing(d.getMinAddress(), d.getMaxAddress());
        }
    }
}
