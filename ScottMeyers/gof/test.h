#ifndef _GOF_TEST_
#define _GOF_TEST_

#include "adapter.h"
#include "bridge.h"
#include "strategy.h"
#include "singleton.h"

namespace goftest {
void goftest() {
    gof_adapter::testAdapter();
    gof_bridge::testBridge();
    gof_strategy::testStrategy();
    gof_singleton::testSingleton();
}

} // namespace goftest


#endif // _GOF_TEST_