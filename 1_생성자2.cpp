// 1_생성자2.cpp
#include <iostream>
using namespace std;

// protected 생성자의 의도
// - 자신의 객체는 생성할 수 없지만(추상적 존재)
// - 자식의 객체는 생성할 수 있습니다.

// Android Framework - RefBase
// MFC - CObject
// => 생성자가 protected로 지정되어 있습니다.

class Animal {
protected:
    Animal() { }
};

class Dog : public Animal {
public:
    Dog()
    // : Animal {}
    {
    }
};

int main()
{
    // Animal a; // 컴파일 오류!
    Dog d; // OK!
}