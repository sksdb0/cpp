#ifndef _EMC_31_
#define _EMC_31_

#include <functional>
#include <vector>
using namespace std;

/*
条款三十一：避免使用默认捕获模式
*/
namespace emc31 {

using FilterContainer = vector<function<bool(int)>>;

class lambdaParam {
public:
    void testLambda() {
        auto divisor = 4;
        fc_.emplace_back([&](int value) { return value % divisor == 0; });
    }

private:
    FilterContainer fc_;
};

void testEMC31() {
}

} // namespace emc31


#endif // _EMC_31_