/* mmio_probe.c - issue #141, user-authorized raw-MMIO probe: GA_IDLE (0x425c) and GA_SOFT_RESET (0x429c), both outside the
 * stock kext's existing read_regs/write_regs mask (& 0x1ffc) and so unreachable through any existing proven-safe kernel path.
 * Maps BAR1 of the ATIRadeonX1000 PCI device directly via /dev/mem (root, physical address 0x90000000, 64KB - decoded from
 * this device's own "assigned-addresses" OF property: entry 2 = reg offset 0x18, phys 0x90000000, size 0x10000). This is a
 * SINGLE, TARGETED, DOCUMENTED-register access (AMD R5xx_Acceleration_v1.5.pdf 10.1.9), not a scan and not a fuzz - the
 * access class this project's own standing caution (Tests/idct_engine_findings.md section 9k) is about broad/undirected use
 * of, not this. Explicit user authorization obtained before running (see #141 comment thread) - run read-only ("read") first.
 *
 * Usage: sudo ./mmio_probe read                 - dumps RBBM_STATUS, RBBM_SOFTRESET, GA_IDLE, GA_SOFT_RESET only (no writes)
 *        sudo ./mmio_probe gaidle                - read-only GA_IDLE alone (for use mid-hang, minimal footprint)
 *        sudo ./mmio_probe softreset             - the full AMD-documented recovery sequence, now including GA_SOFT_RESET
 * Build:  gcc -o mmio_probe mmio_probe.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define BAR1_PHYS 0x90000000UL
#define BAR1_SIZE 0x10000UL

static volatile unsigned int *map_bar1(void) {
    int fd = open("/dev/mem", O_RDWR);
    if (fd < 0) { perror("open /dev/mem"); exit(1); }
    void *m = mmap(NULL, BAR1_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, BAR1_PHYS);
    if (m == MAP_FAILED) { perror("mmap"); exit(1); }
    return (volatile unsigned int *)m;
}
static unsigned int rd(volatile unsigned int *base, unsigned off) { return base[off / 4]; }
static void wr(volatile unsigned int *base, unsigned off, unsigned val) { base[off / 4] = val; }

int main(int argc, char **argv) {
    const char *mode = argc > 1 ? argv[1] : "read";
    volatile unsigned int *bar1 = map_bar1();
    unsigned v;

    if (!strcmp(mode, "gaidle")) {
        v = rd(bar1, 0x425c); printf("GA_IDLE (0x425c) = 0x%08x\n", v);
        return 0;
    }
    if (!strcmp(mode, "read")) {
        v = rd(bar1, 0x0e40); printf("RBBM_STATUS    (0x0e40) = 0x%08x\n", v);
        v = rd(bar1, 0x00f0); printf("RBBM_SOFTRESET (0x00f0) = 0x%08x\n", v);
        v = rd(bar1, 0x425c); printf("GA_IDLE        (0x425c) = 0x%08x\n", v);
        v = rd(bar1, 0x429c); printf("GA_SOFT_RESET  (0x429c) = 0x%08x\n", v);
        return 0;
    }
    if (!strcmp(mode, "softreset")) {
        printf("--- before ---\n");
        v = rd(bar1, 0x0e40); printf("RBBM_STATUS    = 0x%08x\n", v);
        v = rd(bar1, 0x425c); printf("GA_IDLE        = 0x%08x\n", v);

        printf("--- RBBM_SOFTRESET sequence (AMD 10.1.9 steps 2-4) ---\n");
        wr(bar1, 0x00f0, 0x32005); v = rd(bar1, 0x00f0); printf("wrote 0x32005, readback RBBM_SOFTRESET = 0x%08x\n", v);
        wr(bar1, 0x00f0, 0); v = rd(bar1, 0x00f0); printf("wrote 0, readback RBBM_SOFTRESET = 0x%08x\n", v);
        v = rd(bar1, 0x0e40); printf("RBBM_STATUS after = 0x%08x\n", v);

        v = rd(bar1, 0x425c); printf("GA_IDLE (should now be readable per 10.1.9 step 5) = 0x%08x\n", v);
        if (v != 0x1ffffff /* not necessarily all bits but check for "still busy" pattern below before resetting GA too */) {
            printf("--- GA still indicates not-fully-idle; GA_SOFT_RESET (AMD step 6) ---\n");
            wr(bar1, 0x429c, 0x200);
            v = rd(bar1, 0x429c); printf("wrote 0x200, readback GA_SOFT_RESET = 0x%08x\n", v);
            v = rd(bar1, 0x425c); printf("GA_IDLE after GA_SOFT_RESET = 0x%08x\n", v);
            v = rd(bar1, 0x0e40); printf("RBBM_STATUS after GA_SOFT_RESET = 0x%08x\n", v);
        }
        return 0;
    }
    printf("usage: %s [read|gaidle|softreset]\n", argv[0]);
    return 1;
}
