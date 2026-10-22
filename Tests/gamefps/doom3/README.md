# Doom 3 benchmark on the G5 (dhewm3, PPC Tiger)

- Engine: dhewm3 master 455b88e + `dhewm3-tiger-ppc.patch` (8 files: 10.4 SDK `Availability.h`, BPTC enum alias, OpenAL framework shims + `efx.h` from openal-soft 1.23.1, SDLMain, GL debug-callback cast). Configure: cmake 3.9.6 (Tigerbrew bottle), gcc-7, 10.4u SDK, `-DIMGUI=OFF -DSDL2=ON -DREPRODUCIBLE_BUILD=ON`, `PATH` with ld64 first.
- Data: retail PC data (pak000-004, extracted from the 3 CDs with `7z x` straight from the device) + 1.3.1 patch (pak005-008, from the `doom3-linux-1.3.1.1304-x86.run`, sha256 2f90dff2...).
- Installed on Tiger HD in `/Applications/Doom 3` (base/ + run/ with dhewm3, base.dylib, d3xp.dylib); the SonnetSATA disk (Test HD) is avoided because SonnetSATA 2.2.4 panicked twice (same fault offset).
- Only `demo1` exists in the retail data. `r_useVertexBuffers 0` is mandatory: with VBOs on the first `glBufferSubData` wedges the STOCK driver (reboot needed).
- Run: `Tools/gamefps/doom3_run_side.sh OUT SIDE`, report `Tools/game_fps_report_d3.py OUT`, full write-up generator `Tools/gamefps/make_comparison_report.py`.
