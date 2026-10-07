#!/bin/sh
# windowserver_wrapper_template.sh - reusable template for injecting a DYLD_INSERT_LIBRARIES interposer into
# WindowServer itself (needed for anything, like 2D-context opcode capture, that only WindowServer's own process
# ever does). See Tests/windowserver_capture_notes.md for the full technique and why this needs to be launched via
# a manual kill+relaunch, never via an /etc/mach_init.d/WindowServer.plist edit.
#
# Edit the two paths below before use. If this script's own path will be used from a /etc/mach_init.d plist at
# boot (rather than the recommended manual kill+relaunch), it MUST live on the actual boot volume, not a secondary
# volume that mounts after loginwindow's first on-demand launch attempt.
export DYLD_INSERT_LIBRARIES="/path/to/your/interposer.dylib"
export OPCODE_LOG="/path/to/your/output.tsv"
exec /System/Library/Frameworks/ApplicationServices.framework/Frameworks/CoreGraphics.framework/Resources/WindowServer "$@"
