# reboot_wait.sh - sourced by the *_fresh_boots.sh scripts. reboot_wait: reboot the G5 and wait until it answers AND Test HD is mounted
# (a reboot sometimes leaves Test HD unmounted after the SonnetSATA "Failed OOB sequence" error; one more reboot has always cleared it).
g5_up() { sleep 90; until ssh -o ConnectTimeout=5 G5 'uptime' > /dev/null 2>&1; do sleep 10; done; sleep 30; }
g5_testhd() { for _i in 1 2 3 4 5 6 7 8 9 10 11 12; do ssh -o ConnectTimeout=5 G5 'ls /Volumes | grep -q "Test HD"' 2>/dev/null && return 0; sleep 30; done; return 1; }
reboot_wait() {
  ssh G5 'sudo reboot' > /dev/null 2>&1; g5_up
  g5_testhd || { echo "Test HD missing after reboot, rebooting again $(date)" >&2; ssh G5 'sudo reboot' > /dev/null 2>&1; g5_up; g5_testhd || { echo "Test HD still missing" >&2; return 1; }; }
}
