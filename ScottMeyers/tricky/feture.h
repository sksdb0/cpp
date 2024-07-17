#ifndef _TRICKY_FETURE_
#define _TRICKY_FETURE_

#include <iostream>
#include <future>
#include <chrono>
using namespace std;

namespace tricky_feture {

int slow_operation() {
    this_thread::sleep_for(chrono::seconds(2));
    return 42;
}

void testfunc() {
    cout << "testfunc" << endl;
}

int testFeture() {
    function<void ()> f = testfunc;

    auto f2 = move(f);
    f2();
    testfunc();
    // f();

    future<int> result1 = async(slow_operation);
    cout << "Waiting for the result1..." << endl;
    int value1 = result1.get();
    cout << "Result1: " << value1 << endl;

    packaged_task<int()> task(slow_operation);
    future<int> result2 = task.get_future();
    thread t(move(task));
    cout << "Waiting for the result2..." << endl;
    int value2 = result2.get();
    cout << "Result2: " << value2 << endl;
    t.join();

    return 0;
}


} // tricky_feture

#endif // _TRICKY_FETURE_

