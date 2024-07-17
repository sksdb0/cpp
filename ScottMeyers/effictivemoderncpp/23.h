#ifndef _EMC_23_
#define _EMC_23_

#include <iostream>
#include <string>
using namespace std;

/*
条款二十三：理解std::move和std::forward
std::move执行到右值的无条件的转换，但就自身而言，它不移动任何东西。
std::forward只有当它的参数被绑定到一个右值时，才将参数转换为右值。
std::move和std::forward在运行期什么也不做。
*/
namespace emc23 {

class xpstring {
public:
    xpstring(const string& str) : str_(str) { cout << "construct" << endl; }
    xpstring(const xpstring& str) : str_(str.str_) { cout << "construct xpstring" << endl; }
    xpstring(xpstring&& str) : str_(forward<string>(str.str_)) { cout << "move construct" << endl; }
    xpstring& operator=(xpstring& other) {
        cout << "operator=" << endl;
        str_ = other.str_;
        return *this;
    }

    void print() { cout << str_ << " addr: " << &str_ << endl; }
private:
    string str_;
};

class Annotation {
public:
    explicit Annotation(xpstring& text) : str_(move(text)) {
        cout << "an construct" << endl;
    }

private:
    xpstring str_;
};

class AnnotationConst {
public:
    explicit AnnotationConst(const xpstring& text) : str_(move(text)) {
        cout << "an construct" << endl;
    }

private:
    xpstring str_;
};

void testEMC23() {
    xpstring xps("abc");
    Annotation an(xps);
    xps.print();

    xpstring cxps("def");
    AnnotationConst can(cxps);
    cxps.print();
}

} // namespace emc23


#endif // _EMC_23_