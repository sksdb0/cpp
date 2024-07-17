#ifndef _EC_08_
#define _EC_08_

#include <iostream>

/*
条款 8：别让异常逃离析构函数

DBConn2代替DBConn: 提供了close函数供客户手动调用，这样客户也可以根据自己的意愿处理异常
*/
namespace ec08 {

struct DBConnection {
    void close() {}
};

class DBConn {
public:
    ~DBConn(){
        db.close();
    }
private:
    DBConnection db;
};

class DBConn2 {
public:
    void close() {
        db.close();
        closed = true;
    }

    ~DBConn2() {
        if(!closed) {
            try{
                db.close();
            }
            catch(...) {
                std::abort();
            }
        }
    }
private:
    bool closed;
    DBConnection db;
};

} // namespace ec08


#endif // _EC_08_