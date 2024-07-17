#ifndef _GOF_ADAPTER_
#define _GOF_ADAPTER_

#include <memory>
#include <iostream>
using namespace std;

/*
例子是对象适配器，类适配器用多继承就行。对象适配器比类适配器灵活一些。
*/
namespace gof_adapter {

class target {
public:
    virtual ~target() { cout << "target destruct" << endl; }
    virtual void run() { cout << "target run" << endl; };
};

class adaptee : public std::enable_shared_from_this<adaptee> {
public:
    ~adaptee() { cout << "adaptee destruct" << endl; }
    shared_ptr<adaptee> getp() { return shared_from_this(); }
    void dosth() { cout << "adaptee do" << endl; }
};

class adapter : public target {
public:
    ~adapter() { cout << "adapter destruct" << endl; }
    adapter(shared_ptr<adaptee> adaptee) : adaptee_(adaptee) {}

    void run() {
        cout << "adapter run" << endl;
        adaptee_->dosth();
    };
private:
    shared_ptr<adaptee> adaptee_;
};

void testAdapter() {
    cout << endl;
    cout << "begin testAdapter" << endl;
    auto atee = make_shared<adaptee>();
    atee->dosth();

    auto ater = make_shared<adapter>(atee->getp());
    ater->run();
    cout << "end testAdapter" << endl;
}

} // namespace gof_adapter


#endif // _GOF_ADAPTER_