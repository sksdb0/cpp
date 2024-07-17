#ifndef _EC_28_
#define _EC_28_

#include <memory>

/*
条款 28：避免返回 handles 指向对象的内部成分
*/
namespace ec28 {

struct Point {

};

struct RectData {
    Point ulhc;
    Point lrhc;
};

class Rectangle {
public:
    // wrong
    Point& UpperLeft() const { return pData->ulhc; }
    Point& LowerRight() const { return pData->lrhc; }

    // not good
    const Point& UpperLeft1() const { return pData->ulhc; }
    const Point& LowerRight1() const { return pData->lrhc; }

    // ok
    Point UpperLeft2() const { return pData->ulhc; }
    Point LowerRight2() const { return pData->lrhc; }
private:
    std::shared_ptr<RectData> pData;
};


} // namespace ec28


#endif // _EC_28_