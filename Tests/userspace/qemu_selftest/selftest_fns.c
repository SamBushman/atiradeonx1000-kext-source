/* harness self-test functions; built twice (-DREBUILT for the "rebuilt" image) */
#define NI __attribute__((noinline))
NI int anchor_fn(void) { return 0; }
NI unsigned t_same(unsigned a, unsigned b) { return a * 3 + b; }
NI unsigned t_diff(unsigned a, unsigned b) {
#ifdef REBUILT
    return (a & 1) ? a + b + 1 : a + b;
#else
    return a + b;
#endif
}
/* both read an unwritten stack word: the result follows the stack fill word */
NI unsigned t_bothres(unsigned a, unsigned b) { volatile unsigned x; return x + (a & 0); }
/* only the rebuilt reads an unwritten stack word (class #282 shape) */
NI unsigned t_rebres(unsigned a, unsigned b) {
#ifdef REBUILT
    volatile unsigned x; return a + b + (x & 0xff);
#else
    return a + b;
#endif
}
NI unsigned t_crash(unsigned a, unsigned b) { return *(volatile unsigned *)0 + a; }
/* stock reads residue, rebuilt is deterministic and different: every trial is dropped as stock-nondeterministic */
NI unsigned t_stockres_diff(unsigned a, unsigned b) {
#ifdef REBUILT
    return a + 1;
#else
    volatile unsigned x; return x + a;
#endif
}
NI unsigned t_same2(unsigned a, unsigned b) { return (a ^ b) + 7; }
NI unsigned t_diff2(unsigned a, unsigned b) {
#ifdef REBUILT
    return b > 100 ? a - b : a + b;
#else
    return a + b;
#endif
}
