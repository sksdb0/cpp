#ifndef _GOF_STRATEGY_
#define _GOF_STRATEGY_

#include <memory>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

namespace gof_strategy {

class Strategy {
public:
    virtual ~Strategy() = default;
    virtual string doAlgorithm(string data) const = 0;
};

class Context {
private:
    unique_ptr<Strategy> strategy_;
public:
    explicit Context(unique_ptr<Strategy> &&strategy = {}) : strategy_(move(strategy)) {}
    void set_strategy(unique_ptr<Strategy> &&strategy) {
        strategy_ = move(strategy);
    }
 
    void doSomeBusinessLogic() const {
        if (strategy_) {
            cout << "Context: Sorting data using the strategy (not sure how it'll do it)"
            << strategy_->doAlgorithm("aecbd") << endl;
        } else {
            cout << "Context: Strategy isn't set" << endl;
        }
    }
};

class ConcreteStrategyA : public Strategy {
public:
    string doAlgorithm(string data) const override {
        string result(data);
        sort(begin(result), end(result));

        return result;
    }
};

class ConcreteStrategyB : public Strategy {
    string doAlgorithm(string data) const override {
        string result(data);
        sort(begin(result), end(result), greater<>());

        return result;
    }
};

class StrategyFunc {
public:
    StrategyFunc(function<string(string)> f) : func_(f) {};
    virtual ~StrategyFunc() = default;
    void setAlgorithm(function<string(string)> f) { func_ = f; }
    string doAlgorithm(string data) { return func_(data); }
    
    function<string(string)> func_;
};

string do1(string data) {
    string result(data);
    sort(begin(result), end(result), greater<>());

    return result;
}

string do2(string data) {
    string result(data);
    sort(begin(result), end(result));

    return result;
}

void testStrategy() {
    cout << endl;
    Context context(make_unique<ConcreteStrategyA>());
    cout << "Client: Strategy is set to normal sorting." << endl;
    context.doSomeBusinessLogic();
    cout << "Client: Strategy is set to reverse sorting." << endl;
    context.set_strategy(make_unique<ConcreteStrategyB>());
    context.doSomeBusinessLogic();

    StrategyFunc sf(do1);
    cout << sf.doAlgorithm("12345") << endl;
    sf.setAlgorithm(do2);
    cout << sf.doAlgorithm("12345") << endl;
}

} // namespace gof_strategy

#endif // _GOF_STRATEGY_