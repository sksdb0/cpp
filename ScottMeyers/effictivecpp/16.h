#ifndef _EC_16_
#define _EC_16_

#include <string>
using std::string;

/*
条款 16：成对使用 new 和 delete 时要采用相同形式
*/
namespace ec16 {

void testEC16() {
    int* array = new int[10];
    int* object = new int;

    delete[] array;
    delete object;

    typedef string AddressLines[4];
    string* pal = new AddressLines;    // pal 是一个对象数组，而非单一对象

    // delete pal;     // 行为未定义
    delete[] pal;   // 正确
    pal = nullptr;
}

} // namespace ec16


#endif // _EC_16_