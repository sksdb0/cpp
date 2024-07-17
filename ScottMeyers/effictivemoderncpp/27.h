#ifndef _EMC_27_
#define _EMC_27_

#include <iostream>
#include <string>
using namespace std;

/*
条款二十七：熟悉通用引用重载的替代方法
*/
namespace emc27 {

class rvalue {

};

template<typename T>
void testrvalue(T&& t) {
    cout << "r" << endl;
}

void testrvalue(rvalue& t) {
    cout << "l" << endl;
}

template <int I>
bool testTem() {
    if (I > 2) {
        return testTem<2>();
    }

    return true;
}

template <>
bool testTem<2>() {
    return false;
}

void testEMC27() {
    auto&& rv = rvalue();
    testrvalue(rv);

    testrvalue(rvalue());

    auto r = testTem<3>();
}

} // namespace emc27


#endif // _EMC_27_