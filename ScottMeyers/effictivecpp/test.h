#ifndef _EC_TEST_
#define _EC_TEST_

#include "02.h"
#include "03.h"
#include "04.h"
#include "05.h"
#include "06.h"
#include "07.h"
#include "08.h"
#include "09.h"
#include "10.h"
#include "11.h"
#include "12.h"
#include "13.h"
#include "15.h"
#include "16.h"
#include "18.h"
#include "20.h"
#include "24.h"
#include "25.h"
#include "26.h"
#include "28.h"
#include "29.h"
#include "31.h"
#include "33.h"
#include "34.h"
#include "36.h"
#include "37.h"

namespace ectest {
void ectest() {
    ec02::testEC02();
    ec03::testEC03();
    ec05::testEC05();
    ec09::testEC09();   
    ec13::testEC13();
    ec15::testEC15();
    ec16::testEC16();
    ec18::testEC18();
    ec20::testEC20();
    ec24::testEC24();
    ec25::testEC25();
    ec26::testEC26();
    ec33::testEC33();
    ec36::testEC36();
    ec37::testEC37();
}

} // namespace ectest


#endif // _EC_TEST_