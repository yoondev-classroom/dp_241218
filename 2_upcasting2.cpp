// 2_upcasting2.cpp
#include <iostream>
using namespace std;

#if 0
class Dog {
    int age = 10;

public:
    int GetAge() const { return age; }
};

class Cat {
    int age = 20;

public:
    int GetAge() const { return age; }
};

void PrintAge(const Dog& a) { cout << a.GetAge() << endl; }
// void PrintAge(const Cat& a) { cout << a.GetAge() << endl; }

int main()
{
    Dog d;
    Cat c;

    PrintAge(d);
    PrintAge(c);
}
#endif

class Animal {
    int age = 10;

public:
    int GetAge() const { return age; }
};

class Dog : public Animal {
};

class Cat : public Animal {
};

// 1. 동종을 처리하는 함수를 정의할 수 있습니다.
// => Animal의 모든 자식 클래스는 아래 함수를 이용할 수 있습니다.
void PrintAge(const Animal& a) { cout << a.GetAge() << endl; }

int main()
{
    Dog d;
    Cat c;

    PrintAge(d);
    PrintAge(c);
}