# Behavioural checks of the linked userspace images (issue #61)

Run on the Tiger G5 after `Tools/userspace/link_corpus.py` + `build.sh` (see `Userspace/README.md`, "Linking"). Build with `gcc -arch ppc -w -std=gnu99 X.c [-framework OpenGL]`.
Always give the rebuilt image a *different install name* (`INSTALL=/path/x.dylib sh build.sh out`): `dlopen` of a copy that keeps the stock name returns the already-loaded system image.

| test | what it does | result (2026-09-19) |
|---|---|---|
| `libgl_test2.c` | OpenGL smoke test (offscreen CGL context, clear, quad, readback, thread tag path). Run normally and with `DYLD_LIBRARY_PATH` pointing at a directory holding the rebuilt `libGL.dylib` (stock install name), so the whole process, framework included, uses it | identical output; `dladdr` shows glClear inside the rebuilt image |
| `ga_test.c` | stock and rebuilt GA plug-in side by side: exports, `window_mode_to_ati_format` over 2.16M inputs, `ati_format_info_table` (48 pointer words compared by target) | PASS, 0 differences |
| `va_test.c` | stock and rebuilt VA bundle: exports, `AVAGetRendererInfo` return + buffer | PASS |
| `glprog_test.c` | stock and rebuilt libGLProgrammability: all 515 stock C exports resolve, ARB vertex/fragment program parser (create, attach stream, attach string, parse; status + stream words) over 16 programs x 2 shader kinds | loads, 515/515 exports resolve; **parser differs** (below) |
| `glprog_parsestatement_probe.c` | walks `PPParserParseVersion/Option/Statement` one statement kind at a time in both images | `TEMP`, `ATTRIB` agree; `PARAM`, `OUTPUT`, `MOV ...` do not (rebuilt returns 21/10 where the stock returns 6 = end reached) |
