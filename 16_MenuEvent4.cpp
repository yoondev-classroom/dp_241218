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

// 2. 멤버 함수 포인터의 역활을 수행하는 클래스
class Dialog {
public:
    void Close() { cout << "Dialog::Close" << endl; }
};

template <typename TYPE>
class MemberCommand : public ICommand {
    TYPE* obj;
    void (TYPE::*handler)();

public:
    MemberCommand(TYPE* p, void (TYPE::*h)())
    {
        obj = p;
        handler = h;
    }

    void Call() override
    {
        (obj->*handler)(); // !!!
    }
};

int main()
{
    Dialog dlg;

    MemberCommand mc { &dlg, &Dialog::Close };
    mc.Call();
}

#if 0
int main()
{
    Dialog dlg;
    void (Dialog::*fp)() = &Dialog::Close;

    (dlg.*fp)();
}
#endif

#if 0
int main()
{
    FunctionCommand fc { &foo };
    fc.Call();
}
#endif