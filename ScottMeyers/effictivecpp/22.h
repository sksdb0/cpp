#ifndef _EC_22_
#define _EC_22_

/*
条款 22：将成员变量声明为 private
    protected和public一样，都不该被优先考虑。假设我们有一个public成员变量，最终取消了它，那么所有使用它的客户代码都将被破坏；
    假设我们有一个protected成员变量，最终取消了它，那么所有使用它的派生类都将被破坏。
*/
namespace ec22 {

} // namespace ec22


#endif // _EC_22_