#ifndef _EC_11_
#define _EC_11_

#include <iostream>
using namespace std;

/*
条款 11：在 operator= 中处理“自我赋值”
    microsoft给的demo还不是swap的版本
    https://learn.microsoft.com/zh-cn/cpp/cpp/move-constructors-and-move-assignment-operators-cpp?view=msvc-170
*/
namespace ec11 {

class Widget {
public:
    Widget& operator=(const Widget& rhs) {
        if (this == &rhs) return *this; // 若是自我赋值，则不做任何事

        delete[] pRes_;
        len_ = rhs.len_;
        pRes_ = new char[rhs.len_];
        return *this;
    }

    // Widget& operator=(Widget rhs) {  // 利用按值传参, 栈空间会自动释放rhs
    //     swap(*this, rhs);
    //     return *this;
    // }

private:
    char* pRes_;
    size_t len_;
};

void testEC11() {
    Widget w;

}

} // namespace ec11


#endif // _EC_11_