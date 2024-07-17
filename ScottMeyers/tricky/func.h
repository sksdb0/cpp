#ifndef _TRICKY_FUNCTION_
#define _TRICKY_FUNCTION_

#include <mutex>
#include <vector>
#include <memory>
#include <functional>
#include <iostream>
using namespace std;

namespace tricky_function {

using regFunction = function<void(int)>;

class observable {
public:
    virtual void notify(int state) = 0;
};

using observerPtr = shared_ptr<observable>;
using weakObserverPtr = weak_ptr<observable>;

class observer {
public:
    void observe(observerPtr ob) {
        obs_.emplace_back(ob);
    }

    void notify() {
        for (auto ob : obs_) {
            auto obptr = ob.lock();
            if (obptr) {
                obptr->notify(1);
            }
        }
    }

private:
    vector<weakObserverPtr> obs_;
    vector<weak_ptr<regFunction>> obsFunc_;
};

class observable1 : public observable {
public:
    void notify(int state) { cout << "observable1" << endl; };
};

class observable2 : public observable {
public:
    void notify(int state) { cout << "observable2" << endl; };
};

void testFunc() {
    observer ob;
    auto ob1 = make_shared<observable1>();
    ob.observe(ob1);
    
    auto ob2 = make_shared<observable2>();
    ob.observe(ob2);

    ob.notify();
}

} // tricky_function

#endif // _TRICKY_FUNCTION_