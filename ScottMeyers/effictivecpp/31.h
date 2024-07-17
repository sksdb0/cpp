#ifndef _EC_31_
#define _EC_31_

#include <memory>
#include <iostream>

/*
条款 31：将文件间的编译依存关系降至最低
*/
namespace ec31 {

// person.hpp 负责声明类

class PersonImpl;

class Person {
public:
    Person();
    void Print();
private:
    std::shared_ptr<PersonImpl> pImpl;
};

// person.cpp 负责实现类

class PersonImpl {
public:
    int data{ 0 };
};

Person::Person() {
    pImpl = std::make_shared<PersonImpl>();
}

void Person::Print() {
    std::cout << pImpl->data << std::endl;
}

} // namespace ec31


#endif // _EC_31_