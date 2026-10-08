/*
 * Issue153CtxProbe.cpp - issue #153 follow-up: does the Surface-branch newUserClient crash depend
 * on EXECUTION CONTEXT (being invoked via a real userspace IOServiceOpen -> newUserClient call
 * chain - thread/lock/preemption state), rather than anything about the real ATIRadeonX1000
 * object itself?
 *
 * Issue153Probe (previous commit) already proved OSDictionary::setObject works fine called from
 * our kext's own start() - but start() runs in a different context than a real IOServiceOpen's
 * newUserClient dispatch. This probe tests that specific context difference directly, using a
 * throwaway, software-only IOService (no hardware, no relation to ATIRadeonX1000 at all) whose
 * newUserClient() override does the EXACT SAME setObject call shape, invoked via a REAL
 * IOServiceOpen from real userspace. If this crashes identically, the trigger is context
 * (thread/lock/preemption state during a real newUserClient dispatch), not anything about the
 * accelerator's own object/code. If it does NOT crash, that specific context theory is ruled out
 * too, and the defect really is specific to the accelerator's own object/stack state at that point.
 *
 * Registers under IOResources (the standard attach point for software-only pseudo-services -
 * no hardware access, no interrupt/DMA/PCI involvement of any kind).
 */
#include <IOKit/IOLib.h>
#include <IOKit/IOService.h>
#include <IOKit/IOUserClient.h>
#include <libkern/c++/OSDictionary.h>
#include <libkern/c++/OSSymbol.h>
#include <libkern/c++/OSBoolean.h>

class Issue153TestService : public IOService {
    OSDeclareDefaultStructors(Issue153TestService)
public:
    virtual bool start(IOService *provider);
    virtual IOReturn newUserClient(task_t owningTask, void *securityID, UInt32 type,
                                    IOUserClient **handler);
};

OSDefineMetaClassAndStructors(Issue153TestService, IOService)

bool Issue153TestService::start(IOService *provider) {
    if (!IOService::start(provider)) {
        return false;
    }
    registerService();
    IOLog("Issue153CtxProbe: Issue153TestService started and registered\n");
    return true;
}

IOReturn Issue153TestService::newUserClient(task_t owningTask, void *securityID, UInt32 type,
                                             IOUserClient **handler) {
    IOLog("Issue153CtxProbe: newUserClient ENTRY (real IOServiceOpen call chain, type=%u)\n",
          (unsigned)type);
    *handler = NULL;

    IOLog("Issue153CtxProbe: about to call OSDictionary::withCapacity(1) from inside a real newUserClient dispatch\n");
    OSDictionary *dict = OSDictionary::withCapacity(1);
    IOLog("Issue153CtxProbe: withCapacity returned dict=%p\n", dict);
    if (dict == NULL) {
        return kIOReturnNoMemory;
    }

    IOLog("Issue153CtxProbe: about to call setObject(const char*, kOSBooleanTrue) - same call shape as the real #153 crash site, now from inside a real IOServiceOpen->newUserClient dispatch\n");
    bool ok = dict->setObject("IOUserClientCrossEndianCompatible", kOSBooleanTrue);
    IOLog("Issue153CtxProbe: setObject returned %d - NO CRASH\n", (int)ok);

    dict->release();
    IOLog("Issue153CtxProbe: newUserClient EXIT, refusing the open on purpose (test complete)\n");
    return kIOReturnUnsupported;
}

static Issue153TestService *g_testService = NULL;

extern "C" kern_return_t Issue153CtxProbe_start(kmod_info_t *ki, void *data);
extern "C" kern_return_t Issue153CtxProbe_stop(kmod_info_t *ki, void *data);

extern "C" kern_return_t Issue153CtxProbe_start(kmod_info_t *ki, void *data) {
    IOLog("Issue153CtxProbe: start\n");
    Issue153TestService *svc = new Issue153TestService;
    if (svc == NULL) {
        IOLog("Issue153CtxProbe: new Issue153TestService failed\n");
        return KERN_SUCCESS;
    }
    if (!svc->init()) {
        IOLog("Issue153CtxProbe: init failed\n");
        svc->release();
        return KERN_SUCCESS;
    }
    IOService *resources = IOService::getResourceService();
    IOLog("Issue153CtxProbe: IOResources=%p\n", resources);
    if (resources == NULL || !svc->attach(resources)) {
        IOLog("Issue153CtxProbe: attach to IOResources failed\n");
        svc->release();
        return KERN_SUCCESS;
    }
    if (!svc->start(resources)) {
        IOLog("Issue153CtxProbe: start() failed\n");
        svc->detach(resources);
        svc->release();
        return KERN_SUCCESS;
    }
    g_testService = svc;
    IOLog("Issue153CtxProbe: setup complete, waiting for a real IOServiceOpen from userspace\n");
    return KERN_SUCCESS;
}

extern "C" kern_return_t Issue153CtxProbe_stop(kmod_info_t *ki, void *data) {
    IOLog("Issue153CtxProbe: stop\n");
    if (g_testService != NULL) {
        g_testService->stop(IOService::getResourceService());
        g_testService->detach(IOService::getResourceService());
        g_testService->release();
        g_testService = NULL;
    }
    return KERN_SUCCESS;
}
