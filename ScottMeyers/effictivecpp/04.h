#ifndef _EC_04_
#define _EC_04_

#include <iostream>

/*
条款 4：确定对象在使用前已被初始化
    为内置型对象进行手工初始化，因为C++不保证初始化他们
    构造函数最好使用初始化列初始化而不是复制，并且他们初始化时有顺序的
    为了免除跨文件编译的初始化次序问题，应该以local static对象替换non-local static对象
*/
namespace ec04 {
/*
1)
为内置型对象进行手工初始化
*/
int x = 0;
const char* text = "A C-style string";

/*
2)
自定义类初始化
*/
class classInitC98 {
    classInitC98() : textLength(0), lengthIsValid(false) {}
private:
    std::size_t textLength;
    bool lengthIsValid;
};

class classInitC11 {
private:
    std::size_t textLength{0};
    bool lengthIsValid{false};
};

} // namespace ec04

#endif // _EC_04_