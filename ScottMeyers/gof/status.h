#ifndef _GOF_STATUS_
#define _GOF_STATUS_

namespace gof_status {



class Status {
public:
    virtual void dosth() = 0;
private:

};

class StatusA : public Status {
public:

};

class StatusB : public Status {
public:

};

class Context {
public:
    Context() : status_(nullptr) {}
private:
    Status* status_;
};

void testStatus() {

}

} // namespace gof_status


#endif // _GOF_STATUS_