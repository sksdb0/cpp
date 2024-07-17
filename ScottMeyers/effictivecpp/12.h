#ifndef _EC_12_
#define _EC_12_

/*
条款 12：复制对象时勿忘其每一个成分
    当编写一个copy或者拷贝构造函数，应该确保复制成员里面的所有变量，以及所有基类的成员
    不要尝试用一个拷贝构造函数调用另一个拷贝构造函数，如果想要精简代码的话，应该把所有的功能机能放到第三个函数里面，并且由两个拷贝构造函数共同调用
    当新增加一个变量或者继承一个类的时候，很容易出现忘记拷贝构造的情况，所以每增加一个变量都需要在拷贝构造里面修改对应的方法
*/
namespace ec12 {

class Customer {
public:
    Customer() {}
};

class PriorityCustomer : public Customer {
public:
    PriorityCustomer(const PriorityCustomer& rhs) : 
        Customer(rhs), // 调用基类的拷贝构造函数
        priority(rhs.priority) {}
    PriorityCustomer& operator=(const PriorityCustomer& rhs) {
        Customer::operator=(rhs); // 调用基类的拷贝赋值运算符
        priority = rhs.priority;
        return *this;
    }

private:
    int priority;
};

} // namespace ec12


#endif // _EC_12_