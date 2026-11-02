#!/bin/sh
# kill every running Halo (SIGTERM; several instances at once make the launcher dialog vanish)
for p in `ps auxww | grep "[.]/Halo" | awk '{print $2}'`; do kill $p; done
