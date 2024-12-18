// 3_가상소멸자.cpp
#include <iostream>
using namespace std;

// 상속을 Upcasting을 목적으로 사용하고 있다면,
// 반드시 소멸자를 가상으로 만들어야 합니다.

class Base {
public:
    Base() { cout << "Base()" << endl; }
    virtual ~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base {
public:
    Derived()
    {
        cout << "Derived()" << endl;
    }

    ~Derived()
    {
        cout << "~Derived()" << endl;
    }
};

int main()
{
    // Derived d;
    Base* p = new Derived;

    // delete p; // 컴파일러는 p의 타입을 보고, 소멸자를 호출하는 코드를 삽입합니다. - 정적 바인딩
    delete p;
    // 소멸자가 가상함수 이므로, 가상함수테이블을 통해 실제 객체의 소멸자를 호출합니다. - 동적 바인딩
}