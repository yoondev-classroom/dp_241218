// 1_생성자.cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base()" << endl; }
    Base(int) { cout << "Base(int)" << endl; }
    ~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base {
public:
    Derived(int n)
        : Base { n } // 부모의 기본생성자가 아닌 경우, 명시적으로 초기화리스트를 통해 작성해주어야 합니다.
    {
        cout << "Derived(int)" << endl;
    }

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
    Derived d { 42 };

    // Derived d; // 1) Derived::Derived()
}
// 1> Derived::~Derived();