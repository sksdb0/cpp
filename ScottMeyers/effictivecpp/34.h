#ifndef _EC_34_
#define _EC_34_

/*
条款 34：区分接口继承和实现继承
纯虚函数提供缺省的默认实现
*/
namespace ec34 {

// method1
class Airplane1 {
public:
    virtual void Fly() = 0;
protected:
    void DefaultFly() {
        // 缺省实现
    }
};

class Model1 : public Airplane1 { 
public:
    virtual void Fly() override {
        DefaultFly();
    }
};

// method2
class Airplane2 {
public:
    virtual void Fly() = 0;
};

void Airplane2::Fly() {
        // 缺省实现
}

class Model2 : public Airplane2 { 
public:
    virtual void Fly() override {
        Airplane2::Fly();
    }
};

} // namespace ec34


#endif // _EC_34_