#ifndef _EMC_TEST_
#define _EMC_TEST_

#include "23.h"
#include "25.h"
#include "27.h"

namespace emctest {
void emctest() {
  
    emc23::testEMC23();
    emc25::testEMC25();
    emc27::testEMC27();
  
}

} // namespace emctest


#endif // _EMC_TEST_