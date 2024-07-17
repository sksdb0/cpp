#ifndef _EC_33_
#define _EC_33_

#include <iostream>
using namespace std;

/*
条款 33：避免遮掩继承而来的名称
derived class 会遮蔽Base class的名称
可以通过using 或者转交函数来解决
*/
namespace ec33 {

class Base {
public:
    void mf() { cout << "Base::mf" << endl; }
    void mf(double) { cout << "Base::mf(double)" << endl; }
};

class Derived : public Base {
public:
    void mf() { cout << "Derived::mf" << endl; }
};

void testEC33() {
    Derived d;
    d.mf();
    // can't use d.fm(1.0);
}

} // namespace ec33


#endif // _EC_33_