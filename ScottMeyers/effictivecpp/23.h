#ifndef _EC_23_
#define _EC_23_

/*
条款 23：宁以非成员、非友元函数替换成员函数
*/
namespace ec23 {

class WebBrowser {
public:
    void ClearCache() {};
    void ClearHistory() {};
    void RemoveCookies() {};
private:
    void privateFunc() {};
    friend void testFriend(WebBrowser& wb);
};

void testFriend(WebBrowser& wb) {
    wb.privateFunc();
}

/*
member可以访问class的private函数，enums，typedefs等，
但是non-member函数则无法访问上面这些东西，所以non-member non-friend函数更好
*/
void ClearEverything(WebBrowser& wb) {
    wb.ClearCache();
    wb.ClearHistory();
    wb.RemoveCookies();
}

} // namespace ec23


#endif // _EC_23_