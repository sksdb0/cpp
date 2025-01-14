#ifndef _EC_19_
#define _EC_19_

/*
条款 19：设计 class 犹如设计 type

几乎在设计每一个 class 时，都要面对如下问题：

新 type 对象应该如何被创建和销毁？
这会影响到类中构造函数、析构函数、内存分配和释放函数（operator new，operator new[]，operator delete，operator delete[]）的设计。

对象的初始化和赋值该有什么样的差别？
这会影响到构造函数和拷贝赋值运算之间行为的差异。

新 type 的对象如果被按值传递，意味着什么？
这会影响到拷贝构造函数的实现。

什么是新 type 的合法值？
你的类中的成员函数必须对类中成员变量的值进行检查，如果不合法就要尽快解决或明确地抛出异常。

你的新 type 需要配合某个继承图系吗？
你的类是否受到基类设计地束缚，是否拥有该覆写地虚函数，是否允许被继承（若不想要被继承，应该声明为final）。

什么样的运算符和函数对此新 type 而言是合理的？
这会影响到你将为你的类声明哪些函数和重载哪些运算符。

什么样的标准函数应该被驳回？
这会影响到你将哪些标准函数声明为= delete。

谁该取用新 type 的成员？
这会影响到你将类中哪些成员设为 public，private 或 protected，也将影响到友元类和友元函数的设置。

什么是新 type 的“未声明接口”？
为未声明接口提供效率、异常安全性以及资源运用上的保证，并在实现代码中加上相应的约束条件。

你的新 type 有多么一般化？
如果你想要一系列新 type 家族，应该优先考虑模板类。
*/
namespace ec19 {

} // namespace ec19


#endif // _EC_19_