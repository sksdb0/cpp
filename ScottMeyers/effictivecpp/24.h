#ifndef _EC_24_
#define _EC_24_

/*
条款 24：若所有参数皆需类型转换，请为此采用非成员函数

*/
namespace ec24 {

class Rational {
public:
    Rational(int numerator = 0, int denominator = 1) :
        numerator_(numerator),
        denominator_(denominator) {};
    // const Rational operator*(const Rational& rhs) const {
    //     return Rational(numerator_ * rhs.numerator_, denominator_ * rhs.denominator_);
    // }

    friend const Rational operator*(const Rational& lhs, const Rational& rhs);

private:
    int numerator_;
    int denominator_;
};

const Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.numerator_ * rhs.numerator_, lhs.denominator_ * rhs.denominator_);
}

void testEC24() {
    Rational oneEight(1, 8);
    Rational oneHalf(1, 2);
    // Rational result = oneHalf / oneEight;

    auto result = oneHalf * 2;  // 正确
    result = 2 * oneHalf;       // 报错

    // result = oneHalf.operator*(2);    // 正确
    // result = 2.operator*(oneHalf);    // 报错
    // 在调用operator*时，int类型的变量会隐式转换为Rational对象，因此用Rational对象乘以int对象是合法的，但反过来则不是如此。
    // 不推荐这样用隐示转换 explicit Rational构造也会引起编译失败
}

} // namespace ec24


#endif // _EC_24_