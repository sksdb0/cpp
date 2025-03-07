#ifndef _EC_14_
#define _EC_14_

/*
条款 14：在资源管理类中小心拷贝行为

*/
namespace ec14 {

/*
当一个RAII对象被复制，会发生什么事？
选择一：禁止复制
    许多时候允许RAII对象被复制并不合理，如果确是如此，那么就该明确禁止复制行为，条款 6 已经阐述了怎么做这件事。
选择二：对底层资源祭出“引用计数法”
    正如std::shared_ptr所做的那样，每一次复制对象就使引用计数+1，每一个对象离开定义域就调用析构函数使引用计数-1，直到引用计数为0就彻底销毁资源。
选择三：复制底层资源
    在复制对象的同时复制底层资源的行为又被称作深拷贝（Deep copying），例如在一个对象中有一个指针，那么在复制这个对象时就不能只复制指针，也要复制指针所指向的数据。
选择四：转移底层资源的所有权
    和std::unique_ptr的行为类似，永远保持只有一个对象拥有对资源的管理权，当需要复制对象时转移资源的管理权。
*/

} // namespace ec14


#endif // _EC_14_