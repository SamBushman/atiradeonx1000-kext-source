// eh_test.cpp - C++ exceptions crossing frames of libGLProgrammability (issue #63 criterion 2).
//
//   eh_test IMAGE OFF_ShInitialize OFF_S_create
//
// The image's own copy of std::string::_Rep::_S_create(size, alloc) throws std::length_error for a size above max_size. It is called here with such a
// size from a C++ caller (this program, linked against the system libstdc++): the exception has to unwind through the image's frames (_S_create and the
// __throw_length_error it calls) into this caller.
//   case 1: caught here as std::length_error - the text must be "basic_string::_S_create";
//   case 2 (in a forked child): only std::bad_alloc is caught here, so the exception has no handler and the runtime must call terminate (SIGABRT).
// The addresses are nm values (the image's local symbols) rebased with dlsym("ShInitialize"). Build: g++ -arch ppc -o eh_test eh_test.cpp
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <new>
#include <dlfcn.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

typedef void *(*create_t)(unsigned long, void *);

int main(int argc, char **argv) {
    if (argc < 4) { fprintf(stderr, "usage: eh_test IMAGE OFF_ShInitialize OFF_S_create\n"); return 2; }
    setvbuf(stdout, NULL, _IONBF, 0);
    void *L = dlopen(argv[1], RTLD_NOW | RTLD_LOCAL);
    if (!L) { printf("dlopen failed: %s\n", dlerror()); return 2; }
    char *base = (char *)dlsym(L, "ShInitialize") - strtoul(argv[2], 0, 16);
    create_t create = (create_t)(base + strtoul(argv[3], 0, 16));
    char alloc[8];
    int ok = 1;
    printf("%s\n", argv[1]);
    try {
        create(0x7fffffffUL, alloc);
        printf("  case 1: no exception - FAIL\n"); ok = 0;
    } catch (std::length_error &e) {
        int good = strcmp(e.what(), "basic_string::_S_create") == 0;
        printf("  case 1: caught std::length_error \"%s\" - %s\n", e.what(), good ? "PASS" : "FAIL");
        ok &= good;
    } catch (...) {
        printf("  case 1: caught something else - FAIL\n"); ok = 0;
    }
    pid_t p = fork();
    if (p == 0) {
        try { create(0x7fffffffUL, alloc); } catch (std::bad_alloc &) { _exit(3); }
        _exit(4);
    }
    int st = 0;
    waitpid(p, &st, 0);
    int term = WIFSIGNALED(st) && WTERMSIG(st) == SIGABRT;
    printf("  case 2: unmatched type -> %s (%s)\n", term ? "terminate/SIGABRT" : "no terminate", term ? "PASS" : "FAIL");
    ok &= term;
    printf("RESULT: %s\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
