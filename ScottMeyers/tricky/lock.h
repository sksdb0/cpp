#ifndef _TRICKY_LOCK_
#define _TRICKY_LOCK_

#include <iostream>
#include <mutex>
using namespace std;

namespace tricky_lock {

class XpLock {
public:
    XpLock(mutex& m): m_(m) {
        m_.lock();
        cout << "lvalue" << endl;
    }
    XpLock(mutex&& m): m_(m) {
        m_.lock();
        cout << "rvalue" << endl;
    }
    ~XpLock() { m_.unlock(); }
private:
    mutex& m_;
};

void testLock() {
    mutex m;
    XpLock xpl(m);

    mutex m1;
    XpLock xpl1(move(m1));
}

} // tricky_lock

#endif // _TRICKY_LOCK_