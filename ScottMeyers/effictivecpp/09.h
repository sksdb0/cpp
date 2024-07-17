#ifndef _EC_09_
#define _EC_09_

#include <iostream>
using namespace std;

/*
条款 9：绝不在构造和析构过程中调用虚函数
    在构造和析构期间不要调用virtual函数，因为这类调用从不下降至派生类的版本
*/
namespace ec09 {

/*
基类构造先于派生类，不会调用派生类虚函数
*/
class Transaction {
public:
    Transaction() { init(); }
    virtual void LogTransaction() { cout << "Transaction" << endl; } // CWE-0
private:
    void init() { LogTransaction(); }
};

class BuyTransaction : public Transaction {
public:
    BuyTransaction() {}
    virtual void LogTransaction() {}
};

/*
书中有解决办法，但是不推荐这种
*/
class TransactionRes {
public:
    explicit TransactionRes(const std::string& logInfo);
    void LogTransaction(const std::string& logInfo) const {};
};

TransactionRes::TransactionRes(const std::string& logInfo) {
    LogTransaction(logInfo);                           // 更改为了非虚函数调用
}

class BuyTransactionRes : public TransactionRes {
public:
    BuyTransactionRes(...)
        : TransactionRes(CreateLogString()) {  }    // 将信息传递给基类构造函数

private:
    static std::string CreateLogString();
};

void testEC09() {
    Transaction* t = new BuyTransaction();
    t->LogTransaction();
}

} // namespace ec09


#endif // _EC_09_