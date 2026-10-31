# r06 data-label naming: VA

names_r06_data.tsv: 91 `data` rows. Named: the 8 shader program blocks and the one shader constant block in __TEXT,__const (`<pass>ShaderProgram_<addr>` / `<pass>ShaderConstants_<addr>`; programs are the program-block argument of ava_emit_shader_constants), the 40 constant-register cells of the hue/saturation, brightness/contrast, deinterlace and subpicture passes (`<pass>ConstReg<N><X|Y|Z|W>_<addr>`: vec4 register N of the block the pass uploads, component by address), the two __dyld words, the subpicture ring index (DAT_0000f1ac), and all 39 pointer slots (7 lazy slots by import, nl slots by the function/object they point to; PTR_DAT_0000f13c/f184 by the extension-block global they point at).
Not named:
- DAT_0000f1a4 / DAT_0000f1a8: write-only copies of ctx+0x57c / ctx+0x578 made in ava_setup_decode; nothing reads them, so their role beyond "copy of that field" is not stated by the code.
- DAT_00010001: a stray extern in decls.h that no part file uses and the link layer does not map (0x10001 is an immediate, not an address); not a data symbol.
Weakest names (INFERRED): the *ShaderProgram_ block names rely on the reading of ava_emit_shader_constants' B argument as 6-word program entries; the deinterlace block is passed with 6 registers but only registers 0-3 have symbols.
Checks: datacheck.sh DATA-IDENTICAL (16 link files, 111 symbols); compile gate (G5, Tiger) SPLIT-EQUIVALENT, 2 objects different, 178 functions compared, 0 problems.
