# Capturing opcode_recorder traffic from WindowServer itself (2026-10-07)

Issue #42's last open coverage gap was 2D-context opcode usage: `2D` connections are only ever opened by `WindowServer`
itself (ordinary GL/2D client apps never touch the 2D context directly), so injecting `Tools/userspace/opcode_recorder.c`
via `DYLD_INSERT_LIBRARIES` - the same mechanism already used for every GL workload in this file - means getting it into
WindowServer's own process, not an app's.

## What did NOT work, and why

WindowServer is started on-demand from `/etc/mach_init.d/WindowServer.plist` (`ServiceName`/`Command` keys only - this is
the legacy pre-launchd format, still read by `launchd` for backward compatibility on Tiger). Two dead ends:

1. **Adding an `EnvironmentVariables` dict to the plist does nothing.** That key is a `launchd`-native concept; the
   `mach_init.d` format launchd parses for these legacy service definitions only understands `ServiceName`/`Command` -
   the extra key is silently ignored. Confirmed by the recorder's log file never being created despite WindowServer
   relaunching cleanly after the env-var-only edit.
2. **Pointing `Command` at a shell-script wrapper (`export ...; exec WindowServer`) works - but only from a fresh boot,
   not a kill+respawn.** `launchd` reads `/etc/mach_init.d/*.plist` once, when it builds a boot session's bootstrap
   namespace - not per-launch. Editing the plist and then just `kill`-ing the live WindowServer process makes `launchd`
   respawn it from its **already-cached** copy of the old config, not the file on disk. The edit is real and correct;
   it just doesn't apply until the next full reboot.
3. **The wrapper script's location matters for *which* reboot it works on.** The first corrected attempt put the
   wrapper script on `/Volumes/Test HD` (a secondary, non-boot volume). That volume mounts asynchronously, *after*
   `loginwindow` makes its first attempt to start `com.apple.windowserver` at boot - so the very first on-demand launch
   attempt execs a path that doesn't exist yet, WindowServer never comes up, `loginwindow` aborts, and `launchd`
   respawns it in a tight crash loop (confirmed via `/var/log/system.log`: dozens of
   `Login Window Application Started` / `exited abnormally: Abort trap` pairs within the same second). Needed a reboot
   to recover (reverting the plist to its backup first). **Any future wrapper-script approach must live on the actual
   boot volume** (anywhere under the real root filesystem - `/Users/<user>/...`, `/tmp`, etc. - not a secondary volume),
   so it's reachable from the very first on-demand launch attempt during boot.

## What DID work: manual kill + immediate manual relaunch, no plist edit at all

Realized the plist/reboot route is unnecessary overhead for a one-off capture. `launchd`'s on-demand dispatch for a
service only fires when some client does a fresh bootstrap lookup and finds nobody currently registered - it does not
eagerly respawn a dead on-demand service on its own. So:

```sh
PID=$(ps auxww | grep '[W]indowServer -daemon' | awk '{print $2}')
sudo kill $PID
nohup /path/to/windowserver_wrapper.sh -daemon > /tmp/ws_manual.log 2>&1 < /dev/null & disown -a
```

run as one SSH command (same `nohup ... < /dev/null & disown -a` pattern the `tiger-ssh` skill documents for any
backgrounded command over a non-tty SSH session) reliably won the race to register `com.apple.windowserver` before any
GUI client's reconnect attempt could trigger `launchd`'s own on-demand respawn of the *stock* binary. Confirmed clean
both ways: only one `WindowServer` process ever existed at a time, the desktop stayed fully alive and interactive
throughout (screenshotted before/during/after), and killing the manual instance afterward let a fresh stock
`WindowServer` come back normally via the unmodified, never-edited `/etc/mach_init.d/WindowServer.plist` - zero lasting
changes to the machine's boot configuration.

**This is the reusable technique for any future need to inject something into WindowServer specifically**: never touch
the plist at all; kill the live instance and immediately background-relaunch the instrumented version yourself in the
same breath.

## Gesture generation

`Tests/perf_2d_compositing.c` (already built for #44) was reused as-is to drive real desktop interaction (window
open/drag/resize, scroll, Dock hover) via synthetic `CGPostMouseEvent`/`CGPostScrollWheelEvent` input against the live
login session - no new tooling needed for that half.


## Direct injection into WindowServer's real 2D connection (2026-10-07)

Extended `opcode_recorder.c`'s existing GL-only injection mechanism (built 2026-10-02/03) two ways, both backward
compatible (default behavior unchanged):

- `OPCODE_INJECT_TYPE` (default `1` = GL): which `IOServiceOpen` connection type to target. Set to `2` for 2D, `3` for
  DVD. The original mechanism was hardcoded to GL only (`(k->type & 3) == 1`).
- `OPCODE_INJECT_SCHEDULE="flush:word[,word...];flush:word[,word...];..."`: schedules several independent single-shot
  injections across different flushes of the same matched connection, each firing once the first time its own flush
  count is reached. Added specifically because several 2D opcodes (`0x03`/`0x04`/`0x07`/`0x08`/`0x10`/`0x13`) each end
  the *whole* command buffer's processing early when given a deliberately-invalid id (the same safe "no-op" pattern
  already proven for GL's `0x43`) - two of them can never share one flush, and the original mechanism only supported
  one single-shot injection per process lifetime, meaning each would otherwise need its own full kill+relaunch cycle.
  `OPCODE_INJECT_SCHEDULE` lets all of them fire in one process lifetime instead, each on its own flush.

Verified the schedule mechanism itself first against a disposable GL client (two independent scheduled injections,
flush 2 and flush 3 of the same connection, both fired and rewrote exactly as predicted) before ever pointing it at
WindowServer.

**11 of the 17 real 2D opcodes were then live-injected into WindowServer's own real 2D connection in one batch (one
flush), all rewritten exactly as the static source predicts, zero anomalies** - see `Tests/pm4_opcode_usage.md`'s 2D
section for the full table. This is the first live, real-kernel confirmation of any 2D-context opcode in this
project's history (previously only GL opcodes had been live-injected).

### A second real WindowServer-relaunch fragility (distinct from the mach_init.d/Test-HD one above)

A follow-up attempt to schedule the remaining 6 ("terminator-family") opcodes across flushes 2-7 of one connection hit
a **different** failure mode than the mach_init.d one documented above: the recorder-instrumented `WindowServer`
process started (logged its own startup banner to its log file) but exited before any client ever connected to it -
a second, *uninstrumented* `WindowServer` evidently won the on-demand relaunch race instead and served the desktop
(Finder, the gesture driver) completely normally and successfully, just with no recorder attached. No crash, no
anomaly, no corruption - the desktop recovered and worked fine throughout; the only cost was that specific test's data
never got recorded. This happened on the *third* manual kill+relaunch cycle within one boot session (the first two,
earlier the same session, both won the race cleanly) - consistent with a real, reproducible fragility around rapid
repeated `WindowServer` kill+relaunch cycling specifically, not with anything about the injected opcode content
(this project has an unrelated precedent for the same general shape of problem with a different subsystem: #145,
DVD `setup_buffers`/`lock_all_buffers` cycling). **Treat more than ~2 manual WindowServer kill+relaunch cycles within
one boot session as a real reliability risk** - prefer a fresh reboot between cycles if more than two are needed in
one session, rather than cycling the live instance repeatedly.

Given this, the remaining 6 opcodes were accepted as closed by existing static/emulator evidence instead of chasing a
further live confirmation - see `Tests/pm4_opcode_usage.md`'s 2D section for the reasoning per opcode.
