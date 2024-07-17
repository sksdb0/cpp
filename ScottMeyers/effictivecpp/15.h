#ifndef _EC_15_
#define _EC_15_

#include "13.h"

/*
条款 15：在资源管理类中提供对原始资源的访问
*/
namespace ec15 {

void testEC15() {
    shared_ptr<ec13::Investment> r = ec13::makeInvestmentU('r');
    // shared_ptr get
    r.get()->test();
}

} // namespace ec15


#endif // _EC_15_