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
