#ifndef _EC_10_
#define _EC_10_

/*
条款 10：令 operator= 返回一个指向 *this 的引用
    处理这种情况: a = b = c;
*/
namespace ec10 {

class Widget {
public:
    Widget& operator+=(const Widget& rhs) { // 这个条款适用于
        return *this;
    }
    Widget& operator=(int rhs) { // 即使参数类型不是 Widget& 也适用
        return *this;
    }
};

} // namespace ec10


#endif // _EC_10_