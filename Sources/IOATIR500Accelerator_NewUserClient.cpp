/*
 * IOATIR500Accelerator_NewUserClient.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real body for
 * `IOATIR500Accelerator::newUserClient` - real addr 0x2070. The header's
 * own already-thorough comment (`Headers/IOATIR500Accelerator.h`)
 * documents the real type dispatch and factory slots; this file adds
 * the actual C++ transcription.
 *
 * Real body: dispatches on `type` to one of four real factory vtable
 * slots (`+0x5d4`/`+0x5e0`/`+0x5d8`/`+0x5dc` - already-established
 * `new_surface`/`new_gl_context`/`new_2d_context`/`new_dvd_context`).
 * `type==0` (Surface) additionally allocates a real `OSDictionary` of
 * one entry (`"IOUserClientCrossEndianCompatible"` -> `kOSBooleanTrue`)
 * and passes it as the new client's `open`-style properties argument;
 * every other type passes `nullptr` there instead. Tags the new
 * client's own `+0x78` field with the caller's task, then calls three
 * more real vtable methods on it (`+0x150`, `+0x3a4`, `+0x348` - exact
 * Apple virtual-method identities UNKNOWN, referenced only by vtable
 * slot in the real decompile, matching this project's own header
 * comment) - unwinding (`+0x3a8`/`+0x18`) and releasing the properties
 * dictionary on any failure.
 *
 * Confidence: CONFIRMED for control flow and every real offset - a
 * real, complete, standalone decompile.
 */

#include "../Headers/IOATIR500Accelerator.h"

namespace {
typedef void *(*FactoryFn)(void *);
typedef bool (*InitFn)(void *, void *);
typedef bool (*BoolArgFn)(void *, void *);
typedef void (*VoidArgFn)(void *, void *);
typedef void (*ReleaseFn)(void *);
typedef bool (*SetObjectFn)(void *, const char *, void *);
} // namespace

/* both real mangled names CONFIRMED via Ghidra's own external-symbol
 * import table (ground truth, not guessed) - see this project's
 * established `DumpExternals2`/`DumpExternalData` technique. */
extern "C" void *OSDictionary_withCapacity(UInt32 capacity) asm("__ZN12OSDictionary12withCapacityEj");
extern "C" void *g_kOSBooleanTrue asm("_kOSBooleanTrue");

IOReturn IOATIR500Accelerator::newUserClient(task *owningTask, void *securityID, UInt32 type, IOUserClient **handler) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    void **selfVtable = *reinterpret_cast<void ***>(self);
    *handler = nullptr;

    void *properties = nullptr;
    bool hasProperties = false;
    IOUserClient *client = nullptr;

    if (type == 1) {
        client = reinterpret_cast<IOUserClient *>((*reinterpret_cast<FactoryFn *>(selfVtable + (0x5e0 / 4)))(self));
        if (client == nullptr) {
            return 0xe00002be;
        }
        *reinterpret_cast<task **>(reinterpret_cast<UInt8 *>(client) + 0x78) = owningTask;
    } else if (type == 0) {
        properties = OSDictionary_withCapacity(1);
        hasProperties = (properties != nullptr);
        if (properties == nullptr) {
            return 0xe00002be;
        }
        (*reinterpret_cast<SetObjectFn *>(*reinterpret_cast<void ***>(properties) + (300 / 4)))(
            properties, "IOUserClientCrossEndianCompatible", g_kOSBooleanTrue);
        client = reinterpret_cast<IOUserClient *>((*reinterpret_cast<FactoryFn *>(selfVtable + (0x5d4 / 4)))(self));
        if (client == nullptr) {
            (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(properties) + (0x18 / 4)))(properties);
            return 0xe00002be;
        }
        *reinterpret_cast<task **>(reinterpret_cast<UInt8 *>(client) + 0x78) = owningTask;
    } else if (type == 2) {
        client = reinterpret_cast<IOUserClient *>((*reinterpret_cast<FactoryFn *>(selfVtable + (0x5d8 / 4)))(self));
        if (client == nullptr) {
            return 0xe00002be;
        }
        *reinterpret_cast<task **>(reinterpret_cast<UInt8 *>(client) + 0x78) = owningTask;
    } else if (type == 3) {
        client = reinterpret_cast<IOUserClient *>((*reinterpret_cast<FactoryFn *>(selfVtable + (0x5dc / 4)))(self));
        if (client == nullptr) {
            return 0xe00002be;
        }
        *reinterpret_cast<task **>(reinterpret_cast<UInt8 *>(client) + 0x78) = owningTask;
    } else {
        return 0xe00002c2;
    }

    void **clientVtable = *reinterpret_cast<void ***>(client);
    bool ok = (*reinterpret_cast<InitFn *>(clientVtable + (0x150 / 4)))(client, properties);
    if (ok) {
        ok = (*reinterpret_cast<BoolArgFn *>(clientVtable + (0x3a4 / 4)))(client, self);
        if (ok) {
            ok = (*reinterpret_cast<BoolArgFn *>(clientVtable + (0x348 / 4)))(client, self);
            if (ok) {
                *handler = client;
                if (hasProperties) {
                    (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(properties) + (0x18 / 4)))(properties);
                }
                return 0;
            }
            (*reinterpret_cast<VoidArgFn *>(clientVtable + (0x3a8 / 4)))(client, self);
        }
    }
    (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(client) + (0x18 / 4)))(client);
    if (hasProperties) {
        (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(properties) + (0x18 / 4)))(properties);
    }
    return 0xe00002c9;
}
