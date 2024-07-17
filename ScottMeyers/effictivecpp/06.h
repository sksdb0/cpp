#ifndef _EC_06_
#define _EC_06_

/*
条款 6：若不想使用编译器自动生成的函数，就该明确拒绝
*/
namespace ec06 {

class UncopyableC98 {
private:
    UncopyableC98(const UncopyableC98&) {}
    UncopyableC98& operator=(const UncopyableC98&) {return *this;}
};

class UncopyableC11 {
public:
    UncopyableC11(const UncopyableC11&) = delete;
    UncopyableC11& operator=(const UncopyableC11&) = delete;
};

} // namespace ec06


#endif // _EC_06_