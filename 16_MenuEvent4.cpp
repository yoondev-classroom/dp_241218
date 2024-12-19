// 16_MenuEvent4.cpp
#include <iostream>
using namespace std;

// 일반 함수 포인터 역활을 수행하는 클래스와
// 멤버 함수 포인터 역활을 수행하는 클래스의 공통의 부모
class ICommand {
public:
    virtual ~ICommand() { }

    virtual void Call() = 0;
};

// 1. 일반 함수 포인터 역활을 수행하는 클래스
class FunctionCommand : public ICommand {
    using HANDLER = void (*)();

    HANDLER handler;

public:
    FunctionCommand(HANDLER h)
        : handler { h }
    {
    }

    void Call() override
    {
        handler();
    }
};

void foo() { cout << "foo" << endl; }

int main()
{
    FunctionCommand fc { &foo };
    fc.Call();
}