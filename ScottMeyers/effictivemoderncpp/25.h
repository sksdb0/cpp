#ifndef _EMC_25_
#define _EMC_25_

#include <iostream>
#include <string>
using namespace std;

/*
条款二十五：对右值引用使用move，对通用引用使用forward
*/
namespace emc25 {

class Widget {
public:
    template<typename T>
    void setName(T&& newName) { // newName是通用引用
        name = std::forward<T>(newName);
    }

    // void setName(const string& newName) { // 用const左值
    //     cout << "setname lvalue" << endl;
    //     name = newName;
    // }
    
    // void setName(string&& newName) { // 用右值
    //     cout << "setname rvalue" << endl;
    //     name = move(newName);
    // }

    // void setName(const char* newName) { // 方法3
    //     cout << "setname 3" << endl;
    //     name = move(newName);
    // }
    
private:
    string name;
};

void testEMC25() {
    Widget w;
    w.setName("abcdefg");   // 如果不用模版方法没有方法3
                            // 只有const左值和右值重载的话，会先生成string临时对象
}

} // namespace emc25


#endif // _EMC_25_