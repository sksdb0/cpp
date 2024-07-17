#ifndef _EC_03_
#define _EC_03_

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
条款 3：尽可能使用 const
    将某些东西声明为const可以帮助编译器检查出错误。
    编译器强制实施bitwise constneww，但是编写程序的时候应该使用概念上的常量性。
    当const和非const版本有着实质等价的实现时，让非const版本调用const版本可以避免代码重复
*/

namespace ec03 {
/*
1)
const*  底层const，数据不可修改
*const  顶层const，指针不可修改
*/

class TextBlock {
public:
    TextBlock(string s) : text_(s) {}
    const char& operator[](std::size_t position) const {    // const对象使用的重载
        return text_[position];
    }

    // 这种例子比较牵强，一般不会返回类成员地址
    char& operator[](std::size_t position) {                // non-const对象使用的重载
        return text_[position + 1];
    }
    void print() { cout << text_ << endl; }

private:
    std::string text_;
};

/*
non-const版本调用const版本以避免重复，这里不举例说明
    return const_cast<char&>(static_cast<const TextBlock&>(*this)[position]);
*/

void testEC03() {
    TextBlock tb("Hello");
    cout << tb[0] << endl;
    tb[0] = 'x';
    tb.print();

    const TextBlock ctb("World");
    cout << ctb[0] << endl;
    // ctb[0] = 'x'; // error
}

} // namespace ec03

#endif // _EC_03_

