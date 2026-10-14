# squash_play: autopilot test copy of "Squash the Creeps (3D)"

The real game (`~/Godot/squash_the_creeps_start_1.1.0` on the G5) needs a human: with no input the player is hit by the
first creep within ~1 s, dies, and a full-screen "Press Enter To Retry" overlay covers the 3D scene (that, over a
lit white ground, is the flat grey seen in earlier runs). `/Volumes/Test HD/squash_the_creeps_start` is a stub (empty
Main node) and renders nothing at all.

Setup on the G5 (one time): `cp -R ~/Godot/squash_the_creeps_start_1.1.0 ~/rung3/squash_play` then overwrite `Player.gd`
and `Main.gd` with the two files here. Changes only: Player walks a small circle and jumps every 1.5 s, `die()` is a no-op
(invulnerable), spawns use `seed(12345)`. Everything else (scene, meshes, materials, light, camera) is untouched.
`godot_gui.command` uses it by default (`PROJ=...` overrides).
