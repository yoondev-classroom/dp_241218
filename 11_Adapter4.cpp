// 11_Adapter4.cpp
#include <iostream>
using namespace std;

class Base {
public:
    int a;

protected:
    int b;

private:
    int c;
};

// * public 상속
//  [부모]            [자식]
// public     ->     public
// protected  ->     protected
// private    ->     X

// * protected 상속
// public     ->     protected(*)
// protected  ->     protected
// private    ->     X

// * private 상속
// public     ->     private(*)
// protected  ->     private(*)
// private    ->     X

class Derived : protected Base {
    //          -------- 접근 변경자
public:
};

int main()
{
    Derived d;
    // d.a = 10;
}