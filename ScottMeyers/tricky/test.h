#ifndef _TRICKY_TEST_
#define _TRICKY_TEST_

#include "destruct.h"
#include "lock.h"
#include "func.h"
#include "feture.h"

namespace trickytest {
void trickytest() {
    tricky_destruct::testTrickyDestruct();
    tricky_lock::testLock();
    tricky_function::testFunc();
    tricky_feture::testFeture();
}

} // namespace goftest


#endif // _TRICKY_TEST_