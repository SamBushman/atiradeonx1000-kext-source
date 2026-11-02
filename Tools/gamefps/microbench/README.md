# GL draw/state/upload microbenchmarks (issue #209)

Build on the Tiger G5: `gcc -arch ppc -std=gnu99 -w -o pcd pcd.c -framework OpenGL` (same for `pcd4.c`).
`pcd` = CPU cost per draw/state change (64x64 pbuffer, GPU trivial): `PCD_ONLY="matrix change" PCD_REPS=9 ./pcd`.
`pcd4` = texture upload paths (256..2048, DXT1/DXT5 mip chains, texSubImage, BGRA); it crashed on the rebuilt GLDriver until #211.
Run the rebuilt image with `. ~/rung3/ut_env_<name>` (gld_redirect.dylib), stock with those variables unset.
`pcdshark.sh TAG ENV TEST` / `utshark.sh TAG ENV SECS` = Shark capture of a microbenchmark / of UT2004 map load + first seconds.
Caveat: results move +-4-5 % between builds that differ only in unrelated code (code layout on the 970); do not chase smaller deltas with these.
