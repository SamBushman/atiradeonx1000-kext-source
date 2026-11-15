/* Linux/PPC (qemu-ppc user mode) stand-ins for the few Darwin/Mach interfaces fnfuzz.c uses outside the image loader. Test builds only. */
#ifndef FNFUZZ_LINUX_SHIM_H
#define FNFUZZ_LINUX_SHIM_H
#define _GNU_SOURCE
#include <stdint.h>
#include <unistd.h>
#include <errno.h>
#include <elf.h>
#include <link.h>
typedef unsigned vm_size_t; typedef unsigned vm_address_t; typedef int mach_port_t;
#define KERN_SUCCESS 0
#define MACH_PORT_NULL 0
#define EXC_MASK_ALL 0
#define EXCEPTION_DEFAULT 0
#define THREAD_STATE_NONE 0
#define mach_task_self() 0
#define task_set_exception_ports(...) 0
/* a read of another address range that fails instead of faulting: write() to a pipe returns EFAULT for an unmapped source */
static int vm_read_overwrite(int task, vm_address_t a, vm_size_t n, vm_address_t buf, vm_size_t *out) {
    static int pfd[2] = { -1, -1 }; char tmp[4096]; vm_size_t done = 0;
    if (pfd[0] < 0 && pipe(pfd)) return 1;
    while (done < n) { vm_size_t k = n - done > sizeof tmp ? sizeof tmp : n - done; ssize_t w = write(pfd[1], (const void *)(a + done), k); if (w <= 0) return 1; ssize_t r = read(pfd[0], (void *)(buf + done), w); if (r != w) return 1; done += w; }
    *out = done; return 0;
}
#endif
