// 1_생성자.cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base()" << endl; }
    ~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base {
public:
    Derived()
    // : Base()
    // 2) 위의 코드를 컴파일러가 생성합니다.
    {
        cout << "Derived()" << endl;
    }

    ~Derived()
    {
        cout << "~Derived()" << endl;

        // 2> Base::~Base();
        // 위의 코드를 컴파일러가 자동으로 처리합니다.
    }
};

int main()
{
    Derived d; // 1) Derived::Derived()
}
// 1> Derived::~Derived();