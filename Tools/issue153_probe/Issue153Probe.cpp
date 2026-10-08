/*
 * Issue153Probe.cpp - issue #153 follow-up: read-only-ish, generic isolation test.
 *
 * Does the "newUserClient Surface branch crashes inside OSDictionary::setObject" symptom
 * generalize to ANY call to OSDictionary::setObject from our kext's own runtime/link context,
 * using a dictionary and key/value totally unrelated to the real accelerator or a real
 * ATIR500Surface object - or is it specific to the real call site (piVar4 from the live
 * accelerator's newUserClient, self, the real "IOUserClientCrossEndianCompatible" call)?
 *
 * Uses Apple's own declared, typed libkern C++ API (OSDictionary.h/OSSymbol.h/OSBoolean.h from
 * Kernel.framework) rather than hand-rolled vtable-offset VCALL macros, so the compiler resolves
 * the real ABI/vtable slot itself - no offset-guessing risk in this probe's own code.
 *
 * Step 1 is a pure read: kOSBooleanTrue's own apparent vtable pointer (queued diagnostic from
 * #153's session wrap-up, never completed - is it a plausible kernel .text address or garbage?).
 * Steps 2-4 build a fresh, independent OSDictionary and exercise both setObject overloads
 * (const char* and const OSSymbol*) on it. None of this touches the live ATIRadeonX1000
 * instance, any real surface/context object, or hardware in any way.
 *
 * IOLog calls are placed before each step so a crash's exact furthest-reached point is visible
 * in the panic log / system.log even if a later step never runs.
 */
#include <IOKit/IOLib.h>
#include <libkern/c++/OSDictionary.h>
#include <libkern/c++/OSSymbol.h>
#include <libkern/c++/OSBoolean.h>

extern "C" kern_return_t Issue153Probe_start(kmod_info_t *ki, void *data);
extern "C" kern_return_t Issue153Probe_stop(kmod_info_t *ki, void *data);

extern "C" kern_return_t Issue153Probe_start(kmod_info_t *ki, void *data) {
    IOLog("Issue153Probe: start\n");

    OSBoolean *b = const_cast<OSBoolean *>(kOSBooleanTrue);
    IOLog("Issue153Probe: kOSBooleanTrue=%p\n", b);
    if (b != NULL) {
        UInt32 vt = *(UInt32 *)(void *)b;
        IOLog("Issue153Probe: kOSBooleanTrue's own apparent vtable ptr = 0x%x\n", (unsigned)vt);
    }

    IOLog("Issue153Probe: about to call OSDictionary::withCapacity(1) on a fresh, independent dictionary\n");
    OSDictionary *dict = OSDictionary::withCapacity(1);
    IOLog("Issue153Probe: withCapacity returned dict=%p\n", dict);
    if (dict == NULL) {
        IOLog("Issue153Probe: withCapacity failed, stopping here\n");
        return KERN_SUCCESS;
    }

    IOLog("Issue153Probe: about to call setObject(const char*, ...) on our own dict (generic, independent of the real accelerator/surface)\n");
    bool ok1 = dict->setObject("Issue153TestKeyA", kOSBooleanTrue);
    IOLog("Issue153Probe: setObject(const char*) returned %d\n", (int)ok1);

    const OSSymbol *sym = OSSymbol::withCString("Issue153TestKeyB");
    IOLog("Issue153Probe: OSSymbol::withCString returned sym=%p\n", sym);
    if (sym != NULL) {
        IOLog("Issue153Probe: about to call setObject(const OSSymbol*, ...) directly on our own dict\n");
        bool ok2 = dict->setObject(sym, kOSBooleanTrue);
        IOLog("Issue153Probe: setObject(const OSSymbol*) returned %d\n", (int)ok2);
        sym->release();
    }

    dict->release();
    IOLog("Issue153Probe: ALL STEPS COMPLETED, no crash\n");
    return KERN_SUCCESS;
}

extern "C" kern_return_t Issue153Probe_stop(kmod_info_t *ki, void *data) {
    IOLog("Issue153Probe: stop\n");
    return KERN_SUCCESS;
}
