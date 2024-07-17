#ifndef _EC_25_
#define _EC_25_

#include <memory>
#include <vector>

using namespace std;

/*
条款 25：考虑写出一个不抛异常的swap函数

当std::swap对我们的类型效率不高的时候，应该提供一个swap成员函数，且保证这个函数不抛出异常（因为swap是要帮助class提供强烈的异常安全性的）
如果提供了一个member swap，也应该提供一个non-member swap调用前者，对于classes（而不是templates），需要特例化一个std::swap
调用swap时应该针对std::swap使用using std::swap声明，然后调用swap并且不带任何命名空间修饰符
不要再std内加对于std而言是全新的东西（不符合C++标准）

????????????????这个先放一下
*/
namespace ec25 {

class WidgetImpl {
public:
    WidgetImpl(int a, int b, int c) : a_(a), b_(b), c_(c) {}

    WidgetImpl(WidgetImpl&& other) {}

    WidgetImpl& operator=(WidgetImpl&& other) {return *this; }

    int a_, b_, c_;
    vector<int> vi;
};

class Widget {
public:
    Widget(int a, int b, int c) {
        // pImpl_ = new WidgetImpl(a, b, c);
        pImpl_ = new int;
        cout << &pImpl_ << endl;
    }

    Widget(Widget&& other) {}
    Widget& operator=(Widget&& other) {return *this;}

    void swap(Widget& other) {
        using std::swap;
        swap(pImpl_, other.pImpl_);
    }

    void print() {
        // cout << pImpl_->a_ << " addr: " << &pImpl_ << endl;
        cout << pImpl_ << " addr: " << &pImpl_ << endl;
    }

private:
    // WidgetImpl* pImpl_;
    int* pImpl_;
};

void testEC25() {
    Widget w1 = Widget(1, 2, 3);
    Widget w2 = Widget(4, 5, 6);

    // std::swap(w1, w2);

    w1.print();
}

} // namespace ec25

namespace std {
    template<>
    void swap<ec25::Widget>(ec25::Widget& a, ec25::Widget& b) {
        a.swap(b);
    }
}



#endif // _EC_25_