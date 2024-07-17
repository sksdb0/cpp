#ifndef _EC_02_
#define _EC_02_

#include <iostream>
using std::cout;
using std::endl;

/*
条款 2. 尽量以 const, enum, inline 替换 #define
    对于单纯的常量，最好用const和enums替换#define
    对于形似函数的宏，最好改用inline函数替换#define
*/

namespace ec02 {
/*
1) variable
*/
#define ASPECT_RATIO_C 1.653
const double aspect_ratio_c98 = 1.653;
constexpr double aspect_ratio_c11 = 1.653;

/*
2) class专属常量
static常量与enum区别：
    static常量可以取以址，enum不可以
    enum方式在模板元编程常见
static常量取地址的前提是常量定义：
    constexpr int GamePlayerConst::numTurns;
*/
class GamePlayerConst {
public:
    static constexpr auto numTurns = 5;
};

class GamePlayerEnum {
public:
    enum { numTurns = 5 };
};

constexpr int GamePlayerConst::numTurns;

/*
3) function
宏只做替换，有可能和预想的结果不一致
*/
#define CALL_WITH_MAX(a, b) (a) > (b) ? (a) : (b)
template<typename T>
inline T CallWithMax(const T& a, const T& b) {
    return a > b ? a : b;
}

void testEC02() {
    GamePlayerConst gpc;
    cout << "gpc: " << GamePlayerConst::numTurns << endl;
    cout << "gpc addr: " << &GamePlayerConst::numTurns << endl;

    GamePlayerEnum gpe;
    cout << "gpe : " << GamePlayerEnum::numTurns << endl;
    // cout << "gpe addr: " << &GamePlayerEnum::numTurns << endl;

    int a = 2, b = 4;
    auto rstm = CALL_WITH_MAX(++a, ++b);
    cout << "call with max macro: " << rstm << endl; // 6

    a = 2, b = 4;
    auto rstf = CallWithMax(++a, ++b);
    cout << "call with max func: " << rstf << endl; // 5
}

} // namespace ec02




#endif // _EC_02_