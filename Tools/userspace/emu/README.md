# Differential emulation: stock vs rebuilt GLDriver (#81, #82, #83)

Runs a function of the stock bundle and the same function of the rebuilt bundle (`out_*` from `build.sh` on the G5) in a PPC emulator (unicorn) on the SAME fake
context, with the dispatch table (`*(ctx+0x3d4) + 0x12e4..0x132c`) pointing at logging hooks, and compares every hooked call: r3..r10 and the stack words the slot's
callee takes. Pointers into the images are normalised to `DAT_x + offset` through the rebuilt image's `nm` (a DAT symbol's stock address is in its name).

Setup (nothing is installed system-wide):
    pip install --break-system-packages --target /tmp/upkgs unicorn
    scp G5:/System/Library/Extensions/ATIRadeonX1000GLDriver.bundle/Contents/MacOS/ATIRadeonX1000GLDriver /tmp/emu/stock.bin     # fat: the ppc slice is used
    scp G5:'.../out_xx' /tmp/emu/rebuilt.bin ; ssh G5 nm -n .../out_xx > /tmp/emu/rebuilt.nm         # RBIN / RNM override the paths
Use:  `python3 first.py FUN_00099e50 3 400 3`  (first diverging call per seed, NOSTK=1 ignores stack-array contents)
      `python3 sites.py FUN_00097440 400`      (per hand-written site: aligned-equal / call-equal / CALL-DIFFERS / rebuilt-missing)
Emulator details that matter: zero-fill sections are zeroed, non-lazy pointers to symbols defined in the image are filled from the indirect symbol table,
dyld stubs and calls to address 0 return 0.
What it found: #82 (scalar DAT globals read as bytes), #83 (stack locals a callee reaches through a pointer laid out by gcc instead of like the stock), #84 (raw stock
addresses as C integers).
