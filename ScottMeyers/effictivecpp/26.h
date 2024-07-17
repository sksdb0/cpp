#ifndef _EC_26_
#define _EC_26_

#include <string>

using namespace std;

/*
条款 26：尽可能延后变量定义式出现的时间

主要是防止变量在定义以后没有使用，影响效率，应该在用到的时候再定义，同时通过default构造而不是赋值来初始化
*/
namespace ec26 {

class Widget {
public:
    Widget() : i_(0) {}
    Widget(int i) : i_(i) {}
    int i_;
};

void testEC26() {
    cout << endl;
    // 效率低 construct + operator=
    string encrypted;
    encrypted = "password";

    // 效率高 construct
    string encrypted2("password");

    // 1 construct + 1 destruct + 10 operator
    Widget w1;
    for (int i = 0; i < 10; ++i) {
        w1.i_ = i;
    }

    // 10 construct + 10 destruct
    for (int i = 0; i < 10; ++i) {
        Widget w(i);
    }
}

} // namespace ec26


#endif // _EC_26_