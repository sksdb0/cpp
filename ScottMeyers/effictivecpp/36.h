#ifndef _EC_36_
#define _EC_36_

#include <iostream>
using namespace std;

/*
条款 36：绝不重新定义继承而来的非虚函数
在任何情况下都不该重新定义一个继承而来的非虚函数
*/
namespace ec36 {

class Base {
public:
    void funcA() { cout << "Base::funcA" << endl; }
};

class Derive : public Base {
public:
    void funcA() { cout << "Derive::funcA" << endl; }
};

void testEC36() {
    Derive x;

    Base *b = &x;
    Derive *d = &x;

    b->funcA();
    d->funcA();
}

} // namespace ec36


#endif // _EC_36_