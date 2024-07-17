#ifndef _EC_27_
#define _EC_27_

/*
条款 27：少做转型动作
尽量避免转型，特别是在注重效率的代码中避免dynamic_cast，试着用无需转型的替代设计
如果转型是必要的，试着将他封装到函数背后，让用户调用该函数，而不需要在自己的代码里面转型
如果需要转型，使用新式的static_cast等转型，比原来的（int）好很多（更明显，分工更精确）
*/
namespace ec27 {

void testEC27() {
    // const_cast<T>(expression)
    // dynamic_cast<T>(expression)
    // reinterpret_cast<T>(expression)
    // static_cast<T>(expression) 常用
}

} // namespace ec27


#endif // _EC_27_