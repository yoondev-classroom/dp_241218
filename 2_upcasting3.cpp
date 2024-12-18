// 2_upcasting3.cpp
#include <iostream>
#include <vector>
using namespace std;

#if 0
class Dog {
};

class Cat {
};

int main()
{
    vector<Dog*> dogs;
    vector<Cat*> cats;
}
#endif

class Animal { };
class Dog : public Animal {
};

class Cat : public Animal {
};

// 활용 2. 동종을 보관하는 컨테이너를 정의할 수 있습니다.

int main()
{
    vector<Animal*> animals;
    animals.push_back(new Dog);
    animals.push_back(new Cat);
}