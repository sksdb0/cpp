#ifndef _EC_13_
#define _EC_13_

#include <iostream>
#include <string>
#include <memory>
using namespace std;

/*
条款 13：以对象管理资源
    建议使用shared_ptr
    如果需要自定义shared_ptr，请通过定义自己的资源管理类来对资源进行管理
    不要使用弃用的auto_ptr；unique_ptr常用于工厂模式
*/
namespace ec13 {

class Investment {
public:
    void test() {};
};
class Stock: public Investment {
public:
    Stock() {};
};
class Bond: public Investment {
public:
    Bond() {};
};
class RealEstate: public Investment {
public:
    RealEstate() {};
};

std::unique_ptr<Investment> makeInvestmentU(char p) {
    if (p == 's') {
        return make_unique<Stock>();
    } else if (p == 'b') {     
        return make_unique<Bond>();
    } else if (p == 'r') {     
        return make_unique<RealEstate>();
    }

    return nullptr;
}

std::shared_ptr<Investment> makeInvestmentS(char p) {
    if (p == 's') {
        return make_shared<Stock>();
    } else if (p == 'b') {     
        return make_shared<Bond>();
    } else if (p == 'r') {     
        return make_shared<RealEstate>();
    }

    return nullptr;
}

void testEC13() {
    std::unique_ptr<Investment> pUniqueInv1(makeInvestmentU('s'));
    std::unique_ptr<Investment> pUniqueInv2(std::move(pUniqueInv1)); // 转移资源所有权

    std::shared_ptr<Investment> pSharedInv1(makeInvestmentS('b'));
    std::shared_ptr<Investment> pSharedInv2(pSharedInv1); // 引用计数+1
}

} // namespace ec13


#endif // _EC_13_