#ifndef _EC_05_
#define _EC_05_

#include <iostream>
#include <memory>
using namespace std;

/*
条款 5：了解 C++ 默默编写并调用哪些函数
    编译器可以自动为class生成default构造函数，拷贝构造函数，拷贝赋值操作符，以及析构函数
    生成条件在后面章节说明

    effictive modern c++ item17有补充说明
*/
namespace ec05 {

class Empty {
public:
    Empty() { cout << "constructor" << endl; } // 默认构造函数（没有任何构造函数时）
    Empty(const Empty&) { cout << "copy" << endl; } // 拷贝构造函数
    Empty(Empty&&) { cout << "move" << endl; } // 移动构造函数 (since C++11)
    ~Empty() { cout << "destructor" << endl; } // 析构函数
    
    Empty& operator=(const Empty&) { 
        cout << "operator=" << endl;
        return *this;
    } // 拷贝赋值运算符
    Empty& operator=(Empty&&) {
        cout << "move operator=" << endl;
        return *this;
    } // 移动赋值运算符 (since C++11)
};

/*
编译器会拒绝为该类创建一个默认的拷贝赋值运算符:
    类中含有引用类型成员
    类中含有const成员
    基类中含有private的拷贝赋值运算符
*/
class ForbidenCopy {
public:
    ForbidenCopy(string s) : s_(s) { cout << "constructor" << endl; }
private:
    string s_;
    // const string s_; // error
    // string& s_; // error
};

void testEC05() {
    Empty em;
    Empty em1(em);
    Empty em2 = em1;
    em = em1;

    Empty em3, em4;
    em3 = move(em4);

    ForbidenCopy fc1("12");
    ForbidenCopy fc2("bubu");
    fc1 = fc2;
}

} // namespace ec05


#endif // _EC_05_