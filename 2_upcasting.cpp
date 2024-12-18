// 2_upcasting.cpp
#include <iostream>
using namespace std;

class Animal { };

class Dog : public Animal { };
//          protected/private 상속은 C++에만 존재합니다. - 객체지향의 일반적인 상속의 개념과 다릅니다.

// * Upcasting
// - 부모 클래스의 포인터(참조) 타입을 통해 자식 객체를 참조할 수 있습니다.
// - is-a 관계
//  <자식 클래스> is a(n) <부모 클래스>

int main()
{
    Animal a;
    Dog d;

    Animal* p1 = &a;
    Dog* p2 = &d;

    Animal& r1 = a;
    Dog& r2 = d;

    // 자식 클래스의 주소(참조) 타입이 부모 클래스의 주소(참조) 타입으로의 암묵적인 변환이 허용됩니다.
    Animal* p = &d;
    Animal& r = d;
}