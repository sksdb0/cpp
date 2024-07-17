#ifndef _EC_30_
#define _EC_30_

/*
条款 30：透彻了解 inlining 的里里外外
*/
namespace ec30 {

/*
The compiler may not perform inlining in such circumstances as: 

If a function contains a loop. (for, while and do-while) 
If a function contains static variables. 
If a function is recursive. 
If a function return type is other than void, and the return statement doesn’t exist in a function body. 
If a function contains a switch or goto statement. 
*/



} // namespace ec30


#endif // _EC_30_