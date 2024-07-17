#ifndef _EC_18_
#define _EC_18_

/*
条款 18：让接口容易被正确使用，不易被误用
*/
namespace ec18 {

enum class Month {
    jan,
    feb
};

using Year = int;

struct Day {
    Day(int d) : d_(d) {};
    int d_;
};

void Date1(int year, int month, int day) {}
void Date2(Year year, Month month, Day day) {}

void testEC18() {
    Date1(1, 2, 3);
    Date2(Year(1), Month::jan, Day(3)); // better
}

} // namespace ec18


#endif // _EC_18_