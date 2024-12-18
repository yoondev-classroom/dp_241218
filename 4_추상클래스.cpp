// 4_추상클래스.cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual ~Animal() { }
    // virtual void Cry() { cout << "Animal::Cry()" << endl; }
    // 1. 자식의 공통의 기능을 부모의 포인터(참조)를 통해서 이용하기 위해서는
    //    해당 특징이 반드시 부모로부터 비롯되어야 합니다.

    // 2. 자식이 재정의하는 함수는 반드시 가상함수이어야 합니다.
    // 3. 부모의 함수가 가상함수이면, 자식이 재정의하는 함수도 자동으로 가상함수입니다.
    // 4. 부모가 구현을 제공할 필요가 없고, 자식 클래스는 해당 기능을 반드시 제공(오버라이드)해야 한다면,
    //    "순수 가상 함수"로 만드는 것이 좋습니다.

    virtual void Cry() = 0;
    // 순수 가상함수를 하나 이상 가지는 클래스는 객체를 생성하는 것이 불가능합니다.
    // => 추상 클래스(abstract class)
};

// 부모가 제공하는 순수 가상함수를 오버라이딩의 하지 않는다면,
// 자식 클래스도 추상클래스가 되어 객체를 생성할 수 없습니다.
class Dog : public Animal {
public:
    // override 키워드를 반드시 사용해야 합니다.
    void Cry() override
    {
        cout << "Dog::Cry()" << endl;
    }
};
class Cat : public Animal {
public:
    void Cry() override
    {
        cout << "Cat::Cry()" << endl;
    }
};

int main()
{
    // Animal a; // 오류!

    Dog d;
    Cat c;

    // d.Cry();
    // c.Cry();

    Animal* p = &d;
    p->Cry();

    p = &c;
    p->Cry();
}
