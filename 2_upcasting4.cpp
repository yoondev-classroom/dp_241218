// 2_upcasting4.cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual ~Animal() { }
};
class Dog : public Animal {
public:
    void Cry() { cout << "Dog::Cry()" << endl; }
};

int main()
{
    Dog d;

    Animal* p = &d;
    Animal& r = d;

    // p->Cry(); // Error!
    // r.Cry(); // Error!

    // Downcasting
    // => 명시적인 캐스팅이 필요합니다.
    // dynamic_cast<Dog*>(p)->Cry();
    // - 가상함수 테이블에 보관되어 있는 type_info를 꺼내서 검사합니다.

    Dog* pDog = dynamic_cast<Dog*>(p);
    if (pDog) {
        pDog->Cry(); // !!
    }

    static_cast<Dog*>(p)->Cry();
    // p가 Dog 타입인것을 확신하는 경우
}