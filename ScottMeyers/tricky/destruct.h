#ifndef _TRICKY_DESTRUCT_
#define _TRICKY_DESTRUCT_

#include <iostream>
#include <memory>
using namespace std;

namespace tricky_destruct {

typedef void(*FUNCTION)();

class Base {
public:
    ~Base() { cout << "~Base" << endl; }
    virtual void test() {}
};

class Derive : public Base {
public:
    ~Derive() { cout << "~Derive" << endl; }
};

class Derive1 : public Derive {
public:
    ~Derive1() { cout << "~Derive1" << endl; }
};

void testTrickyDestruct() {
    Base* b =  new Derive;

    delete b;
    b = nullptr;

    // Derive d;
    // Base* b1 = &d;

    // shared_ptr<Base> b2 = make_shared<Derive1>();

    // Derive1 d1;
    // Base* b3 = &d1;
}

} // namespace tricky_destruct


#endif // _TRICKY_DESTRUCT_