#ifndef _EC_29_
#define _EC_29_

#include <vector>
#include <mutex>
#include <memory>
using namespace std;

/*
条款 29：为“异常安全”而努力是值得的
异常安全函数的三个特征
第二个特征往往能够通过copy-and-swap实现出来，但是并非对所有函数都可实现或具备现实意义
函数提供的异常安全保证，通常最高只等于其所调用各个函数的“异常安全保证”中最弱的那个。即函数的异常安全保证具有连带性
*/
namespace ec29 {

// after c++11 use noexcept
int DoSomething() noexcept { return 0; };

struct Image {
    Image(vector<uint8_t>& imgSrc) {}
};

// 违反不泄漏任何资源: 一旦new Image导致异常，对unlock的调用就绝不会执行，互斥器就永远被把持住了
// 违反不允许数据败坏：如果new Image抛出异常，bgImage就是指向一个已被删除的对象，imageChanges也被累加，而其实没有新的图像被成功安装。
class PrettyMenuBad {
public:
    void ChangeBackground(vector<uint8_t>& imgSrc);
private:
    mutex mutex_;        // 互斥锁
    Image* bgImage_;     // 目前的背景图像
    int imageChanges_;   // 背景图像被改变的次数
};

void PrettyMenuBad::ChangeBackground(vector<uint8_t>& imgSrc) {
    mutex_.lock();
    delete bgImage_;
    ++imageChanges_;
    bgImage_ = new Image(imgSrc);
    mutex_.unlock();
}

struct PMImpl {
    shared_ptr<Image> bgImage;
    int imageChanges;
};

class PrettyMenuGood {
    void ChangeBackground(vector<uint8_t>& imgSrc);
private:
    mutex mutex_;
    shared_ptr<PMImpl> pImpl;
};

void PrettyMenuGood::ChangeBackground(std::vector<uint8_t>& imgSrc) {
    lock_guard<mutex> lock(mutex_);

    auto pNew = make_shared<PMImpl>(*pImpl);    // 获取副本
    pNew->bgImage.reset(std::make_shared<Image>(imgSrc).get());
    ++pNew->imageChanges;
    
    std::swap(pImpl, pNew);
}

} // namespace ec29


#endif // _EC_29_