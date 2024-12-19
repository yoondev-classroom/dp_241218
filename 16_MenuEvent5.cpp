// 16_MenuEvent5.cpp
#include <iostream>
using namespace std;

// C++11에 범용 함수 포인터 라이브러리가 제공되고 있습니다.
//  - function
#include <functional>

// void()
void foo() { cout << "foo" << endl; }

void goo(int a, int b)
{
    cout << "goo: " << a << ", " << b << endl;
}

void hoo(int a, int b, int c, int d)
{
    cout << "hoo: " << a << ", " << b << ", " << c << ", " << d << endl;
}

using namespace std::placeholders; // _1, _2 ...

// void(int, int)
void foo(int a, int b)
{
}

class Point {
public:
    void foo(int a, int b) // Point::foo(Point* this, int a, int b)
    {
    }
    // 멤버 함수는 함수를 호출하기 위해서 객체가 필요합니다. - thiscall
};

class Dialog {
public:
    void Close()
    {
        cout << "Dialog::Close" << endl;
    }
};

int main()
{
    Dialog dlg;
    dlg.Close(); // Dialog::Close(&dlg);

    function<void()> f = bind(&Dialog::Close, &dlg);
    f();

    function<void(Dialog*)> f2 = &Dialog::Close;
    f2(&dlg);
    // thiscall을 이해해야, 멤버 함수 포인터를 호출하는 방법을 이해할 수 있습니다.

    Point pt;
    pt.foo(10, 20); // Point::foo(&pt, 10, 20)
}

#if 0
int main()
{
    function<void(int, int)> f = &goo;
    goo(100, 200);

    f = bind(&hoo, 100, 200, _1, _2);
    f(50, 60);
}
#endif

#if 0
int main()
{
    function<void()> f1 { &foo };
    f1();

    // 인자를 고정하는 기술이 제공됩니다. - bind
    f1 = bind(&goo, 100, 200);
    f1();
}
#endif