#ifndef _GOF_SINGLETON_
#define _GOF_SINGLETON_

#include <iostream>
#include <memory>
#include <mutex>
using namespace std;

namespace gof_singleton {

class Singleton {
public:
    Singleton& getInstance();

private:
    Singleton() {};
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    std::unique_ptr<Singleton> instance_;
    mutex mutex_;
};

Singleton& Singleton::getInstance() {
    if (instance_ == nullptr) {
        lock_guard<mutex> lock(mutex);
        if (instance_ == nullptr) {
            // instance_ = make_unique<Singleton>();
            instance_.reset(new Singleton);
        }
    }
    return *instance_;
}

void testSingleton() {

}

} // namespace gof_singleton


#endif // _GOF_SINGLETON_