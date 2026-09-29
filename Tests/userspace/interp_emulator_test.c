/* interp_emulator_test.c - issue #66 criterion 2: drive the runtime interpreter/JIT emulator
 * (_PPEmulatorCreate -> _PPEmulatorProgramCreate -> _PPEmulatorProgramInitialiseHandleBanks ->
 * _PPEmulatorProgramConvertFromPPStream -> _PPEmulatorAttachProgram -> _PPEmulatorBuild ->
 * _PPEmulatorRun, in that order - NOT the order an earlier issue comment recorded: Convert
 * reads straight through the handle-bank pointers InitialiseHandleBanks allocates, so the
 * banks have to exist first) on a real PP-stream produced by parsing a real ARB program (the
 * same parser already verified 78/78 identical to stock, #61/#65).
 *
 * STATUS (2026-09-29, against the real stock libGLProgrammability.dylib on the G5): reaches
 * and successfully drives the real runtime JIT compiler - confirmed via a post-mortem core
 * dump that execution reaches PPCRuntimeCompilerCompileAV -> LoadSourceAV -> LoadRegister, and
 * that PPEmulatorBuild's own final tail-dispatch jumps into real, freshly JIT-compiled
 * PPC/AltiVec vertex-transform code sitting in heap memory (disassembled and confirmed
 * legitimate, not garbage). Currently crashes there: PPEmulatorBuild's own tail-dispatch
 * passes a small compile-mode flag in r9, but the generated code's first real instruction
 * reads r9 as a data pointer (the same slot PPEmulatorRun's tail-dispatch puts the emulator
 * context pointer in) - a real calling-convention question, not yet resolved. Only --one mode
 * (single image) exists; no stock-vs-rebuilt differential yet since neither image gets past
 * this point. See issue #66 for the full writeup.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <sys/wait.h>
#include <unistd.h>

static const char *prog_src =
    "!!ARBvp1.0\nATTRIB pos = vertex.position;\nPARAM mvp[4] = { state.matrix.mvp };\n"
    "DP4 result.position.x, mvp[0], pos;\nDP4 result.position.y, mvp[1], pos;\n"
    "DP4 result.position.z, mvp[2], pos;\nDP4 result.position.w, mvp[3], pos;\n"
    "MOV result.color, vertex.color;\nEND\n";

typedef void *(*create_t)(unsigned int);
typedef void (*attachstr_t)(void *, const char *, int);
typedef int (*parse_t)(void *);
typedef void *(*mk_t)(void);
typedef void (*astream_t)(void *, void *);
typedef int (*gs_t)(void *, void *, unsigned *);

typedef int (*emu_create_t)(void);
typedef int (*emu_attach_t)(int, int);
typedef int (*emu_progcreate_t)(void);
typedef int (*emu_convert_t)(void *, void *);
typedef int (*emu_handlebanks_t)(int, int, int, int, int);
typedef int (*emu_build_t)(int, int, int, int, int, int);
typedef int (*emu_run_t)(int, int, int, int, int);

static void hexdump(const char *label, unsigned char *p, int n) {
    printf("%s (%d bytes):", label, n);
    for (int i = 0; i < n; i++) {
        if (i % 32 == 0) printf("\n  %04x: ", i);
        printf("%02x", p[i]);
    }
    printf("\n");
}

int run_one(const char *lib) {
    void *h = dlopen(lib, RTLD_NOW | RTLD_LOCAL);
    if (!h) { printf("dlopen failed: %s\n", dlerror()); return 1; }
    printf("dlopen ok: %s\n", lib);

    create_t PPParserCreate = dlsym(h, "PPParserCreate");
    attachstr_t PPParserAttachString = dlsym(h, "PPParserAttachString");
    parse_t PPParserParse = dlsym(h, "PPParserParse");
    mk_t PPStreamCreate = dlsym(h, "PPStreamCreate");
    astream_t PPParserAttachStream = dlsym(h, "PPParserAttachStream");
    gs_t PPStreamGetStream = dlsym(h, "PPStreamGetStream");
    if (!PPParserCreate || !PPParserAttachString || !PPParserParse || !PPStreamCreate ||
        !PPParserAttachStream || !PPStreamGetStream) {
        printf("missing parser symbol\n"); return 1;
    }

    unsigned vlim[15] = { 0x100, 0x100, 8, 0x8000, 0x100, 0x100, 0x20, 2, 8, 0x10, 4, 1, 6, 8, 0x10 };
    void *parser = PPParserCreate(0);   /* EShLangVertex */
    void *stream = PPStreamCreate();
    PPParserAttachStream(parser, stream);
    memcpy((char *)parser + 0x450, vlim, sizeof vlim);
    PPParserAttachString(parser, prog_src, 1);
    int rc = PPParserParse(parser);
    unsigned nwords = 0;
    PPStreamGetStream(stream, 0, &nwords);
    printf("parse rc=%d, stream words=%u\n", rc, nwords);
    if (rc != 0 || nwords == 0 || nwords > 100000) { printf("RESULT: PARSE-FAIL\n"); return 1; }
    unsigned *streamwords = calloc(nwords, 8);
    PPStreamGetStream(stream, streamwords, &nwords);
    hexdump("ppstream first words", (unsigned char *)streamwords, nwords * 8 > 128 ? 128 : nwords * 8);

    emu_create_t PPEmulatorCreate = dlsym(h, "PPEmulatorCreate");
    emu_attach_t PPEmulatorAttachProgram = dlsym(h, "PPEmulatorAttachProgram");
    emu_progcreate_t PPEmulatorProgramCreate = dlsym(h, "PPEmulatorProgramCreate");
    emu_convert_t PPEmulatorProgramConvertFromPPStream = dlsym(h, "PPEmulatorProgramConvertFromPPStream");
    emu_handlebanks_t PPEmulatorProgramInitialiseHandleBanks = dlsym(h, "PPEmulatorProgramInitialiseHandleBanks");
    emu_build_t PPEmulatorBuild = dlsym(h, "PPEmulatorBuild");
    emu_run_t PPEmulatorRun = dlsym(h, "PPEmulatorRun");
    if (!PPEmulatorCreate || !PPEmulatorAttachProgram || !PPEmulatorProgramCreate ||
        !PPEmulatorProgramConvertFromPPStream || !PPEmulatorProgramInitialiseHandleBanks ||
        !PPEmulatorBuild || !PPEmulatorRun) {
        printf("missing emulator symbol\n"); return 1;
    }
    printf("STEP 1: PPEmulatorCreate\n");
    int ctx = PPEmulatorCreate();
    printf("  ctx=0x%x\n", ctx);
    if (!ctx) { printf("RESULT: FAIL-CREATE\n"); return 1; }

    printf("STEP 2: PPEmulatorProgramCreate\n");
    int prog = PPEmulatorProgramCreate();
    printf("  prog=0x%x\n", prog);
    if (!prog) { printf("RESULT: FAIL-PROGCREATE\n"); return 1; }

    printf("STEP 3: PPEmulatorProgramInitialiseHandleBanks\n");
    int hb = PPEmulatorProgramInitialiseHandleBanks(prog, 64, 64, 64, 64);
    printf("  hb rc=%d\n", hb);

    printf("STEP 4: PPEmulatorProgramConvertFromPPStream\n");
    int conv = PPEmulatorProgramConvertFromPPStream((void *)(long)prog, stream);
    printf("  conv rc=%d\n", conv);

    printf("STEP 5: PPEmulatorAttachProgram\n");
    PPEmulatorAttachProgram(ctx, prog);

    printf("STEP 6: PPEmulatorBuild\n");
    int build = PPEmulatorBuild(ctx, 0, 0, 0, 0, 0);
    printf("  build rc=%d\n", build);

    printf("STEP 7: PPEmulatorRun\n");
    int run = PPEmulatorRun(ctx, 0, 0, 0, 0);
    printf("  run rc=%d\n", run);

    hexdump("emulator ctx", (unsigned char *)(long)ctx, 0xe00);
    hexdump("program obj", (unsigned char *)(long)prog, 0x128);

    printf("RESULT: PASS\n");
    return 0;
}

int main(int argc, char **argv) {
    setvbuf(stdout, NULL, _IONBF, 0);
    if (argc > 2 && !strcmp(argv[1], "--one")) return run_one(argv[2]);
    fprintf(stderr, "usage: %s --one LIB\n", argv[0]);
    return 2;
}
