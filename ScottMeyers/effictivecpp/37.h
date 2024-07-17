#ifndef _EC_37_
#define _EC_37_

#include <iostream>
using namespace std;

/*
条款 37：绝不重新定义继承而来的缺省参数值
*/
namespace ec37 {

class Shape {
public:
    enum class ShapeColor { Red, Green, Blue };
    virtual void Draw(ShapeColor color = ShapeColor::Red) const = 0;
};

void Shape::Draw(ShapeColor color) const {
    cout << "Shape::Draw: " << int(color) << endl;
}

class Rectangle : public Shape {
public:
    virtual void Draw(ShapeColor color = ShapeColor::Green) const;
};

void Rectangle::Draw(ShapeColor color) const {
    cout << "Rectangle::Draw: " << int(color) << endl;
}

class Circle : public Shape {
public:
    virtual void Draw(ShapeColor color) const;
};

void Circle::Draw(ShapeColor color) const {
    cout << "Circle::Draw: " << int(color) << endl;
}

void testEC37() {
    Shape* pr = new Rectangle;  // 此时pr的静态类型是Shape，但是他的动态类型是Rectangle
    pr->Draw();                 // virtual函数是动态绑定，而缺省参数值是静态绑定，所以会调用Red
}

} // namespace ec37


#endif // _EC_37_