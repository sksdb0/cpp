#ifndef _GOF_BRIDGE_
#define _GOF_BRIDGE_

#include <memory>
#include <iostream>
using namespace std;

namespace gof_bridge {

class Implementation {
public:
    virtual ~Implementation() { cout << "Implementation destruct" << endl; }
    virtual void OperationImplementation() const = 0;
};

class ConcreteImplementationA : public Implementation {
public:
    ~ConcreteImplementationA() { cout << "ConcreteImplementationA destruct" << endl; }
    void OperationImplementation() const override {
        cout << "ConcreteImplementationA: Here's the result on the platform A." << endl;
    }
};

class ConcreteImplementationB : public Implementation {
public:
    ~ConcreteImplementationB() { cout << "ConcreteImplementationB destruct" << endl; }
    void OperationImplementation() const override {
        cout << "ConcreteImplementationB: Here's the result on the platform B." << endl;
    }
};

class Abstraction {
protected:
    unique_ptr<Implementation> implementation_;

public:
    Abstraction(unique_ptr<Implementation>& implementation) : implementation_(move(implementation)) {}
    virtual ~Abstraction() { cout << "Abstraction destruct" << endl; }

    virtual void Operation() const {
        cout << "Abstraction: Base operation with: " << endl;
        this->implementation_->OperationImplementation();
    }
};

class ExtendedAbstraction : public Abstraction {
public:
    ExtendedAbstraction(unique_ptr<Implementation>& implementation) : Abstraction(implementation) {}
    virtual ~ExtendedAbstraction() { cout << "ExtendedAbstraction destruct" << endl; }
    void Operation() const override {
        cout << "ExtendedAbstraction: Extended operation with: " << endl;
        this->implementation_->OperationImplementation();
    }
};

void ClientCode(const Abstraction& abstraction) {
    // ...
    abstraction.Operation();
    // ...
}

void testBridge() {
    cout << endl;
    unique_ptr<Implementation> implementation =  make_unique<ConcreteImplementationA>();
    unique_ptr<Abstraction> abstraction = make_unique<Abstraction>(implementation);
    ClientCode(*abstraction.get());

    unique_ptr<Implementation> implementatione =  make_unique<ConcreteImplementationB>();
    unique_ptr<ExtendedAbstraction> abstractione = make_unique<ExtendedAbstraction>(implementatione);
    ClientCode(*abstractione.get());
}

} // namespace gof_bridge


#endif // _GOF_BRIDGE_