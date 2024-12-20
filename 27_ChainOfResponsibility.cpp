// 27_ChainOfResponsibility.cpp
#include <iostream>
#include <string>
using namespace std;

// 이벤트가 발생하였을 때, 처리할 수 있는 핸들러가 여러개 존재할 수 있습니다.
// - 자신이 처리하지 못하는 경우, 다음 핸들러를 통해 처리할 수 있도록합니다.

class Handler {
    Handler* next;

public:
    virtual ~Handler() { }

    void SetNext(Handler* p) { next = p; }

    virtual void HandleRequest(int level)
    {
        if (next) {
            next->HandleRequest(level);
        } else {
            std::cout << "처리할 수 없습니다. " << endl;
        }
    }
};

class LowLevelHandler : public Handler {
public:
    void HandleRequest(int level) override
    {
        if (level <= 3) {
            std::cout << "LowLevelHandler 처리 완료 -" << level << std::endl;
        } else {
            // 처리할 수 없는 경우
            std::cout << "LowLevelHandler 처리 불가 -" << level << std::endl;
            Handler::HandleRequest(level); // 책임의 전가
        }
    }
};

class HighLevelHandler : public Handler {
    void HandleRequest(int level) override
    {
        if (level > 3) {
            std::cout << "HighLevelHandler 처리 완료 -" << level << std::endl;
        } else {
            // 처리할 수 없는 경우
            std::cout << "HighLevelHandler 처리 불가 -" << level << std::endl;
            Handler::HandleRequest(level); // 책임의 전가
        }
    }
};

int main()
{
    LowLevelHandler h1;
    HighLevelHandler h2;

    h1.SetNext(&h2);

    int event[] = { 1, 2, 3, 5, 10 };
    for (auto e : event) {
        h1.HandleRequest(e);
    }
}