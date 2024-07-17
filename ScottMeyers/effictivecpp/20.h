#ifndef _EC_20_
#define _EC_20_

#include "05.h"

/*
条款 20：宁以按常引用传参替换按值传参
    也并非永远都使用按引用传参，对于内置类型、STL的迭代器和函数对象，我们认为使用按值传参是比较合适的
*/
namespace ec20 {

/*
传参方式不会调用任何构造函数或析构函数，所以效率比按值传参高得多
*/
void testParamRef(const ec05::Empty& e) {} // better

void testParam(ec05::Empty e) {}

void testEC20() {
    ec05::Empty e;
    testParam(e);
}

} // namespace ec20


#endif // _EC_20_