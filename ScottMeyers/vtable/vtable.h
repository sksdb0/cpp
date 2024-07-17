#ifndef _VTABLE_
#define _VTABLE_

#include <iostream>
using namespace std;

namespace vtable {

typedef void(*FUNCTION)();

class Base {
public:
	virtual void vFunc1() { cout << "  Base::vFunc1" << endl; }
	virtual void vFunc2() { cout << "  Base::vFunc2" << endl; }
	virtual void vFunc3() { cout << "  Base::vFunc3" << endl; }
};

class Base2 {
public:
	virtual void vBase2Func1() { cout << "  Base2::vFunc1" << endl; }
	virtual void vBase2Func2() { cout << "  Base2::vFunc2" << endl; }
};

class Base3 {
public:
	virtual void vBase3Func1() { cout << "  Base3::vFunc1" << endl; }
	virtual void vBase3Func2() { cout << "  Base3::vFunc2" << endl; }
};

class SubClass : public Base , public Base2, public Base3 {
	//virtual void vFunc() { cout << " SubClass::vFunc" << endl; }
};

void testvtable() {
    cout << endl;
    SubClass sub;
    // 虚函数表一 Base vTablePtr1 (地址)
    int64_t *subAddress = (int64_t*)&sub;
    int64_t *vTablePtr1 = (int64_t*)*(subAddress);

    // 虚函数表二 Base2 vTablePtr2（地址）
    int64_t *subAddress2 = (int64_t*)&sub + 1;
    int64_t *vTablePtr2 = (int64_t*)*(subAddress2);

    // 虚函数表三 Base3 vTablePtr3 (地址)
    int64_t *subAddress3 = (int64_t*)&sub + 2;
    int64_t *vTablePtr3 = (int64_t*)*(subAddress3);

    // Base
    int64_t *pBaseFunc1 = (int64_t *)*(vTablePtr1 + 0);
    int64_t *pBaseFunc2 = (int64_t *)*(vTablePtr1 + 1);
    int64_t *pBaseFunc3 = (int64_t *)*(vTablePtr1 + 2);

    // Base2 
    int64_t *pBase2Func1 = (int64_t *)*(vTablePtr2 + 0);
    int64_t *pBase2Func2 = (int64_t *)*(vTablePtr2 + 1);

    // Base3
    int64_t *pBase3Func1 = (int64_t *)*(vTablePtr3 + 0);
    int64_t *pBase3Func2 = (int64_t *)*(vTablePtr3 + 1);

    // Base
    (FUNCTION(pBaseFunc1))();
    (FUNCTION(pBaseFunc2))();
    (FUNCTION(pBaseFunc3))();

    // Base2
    (FUNCTION(pBase2Func1))();
    (FUNCTION(pBase2Func2))();

    // Base3
    (FUNCTION(pBase3Func1))();
    (FUNCTION(pBase3Func2))();
}

} // namespace vtable


#endif // _VTABLE_