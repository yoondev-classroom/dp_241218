// 22_Factory2.cpp
#include <iostream>
#include <vector>
#include <map>
using namespace std;

#include "Singleton.h"

class Shape {
public:
    virtual ~Shape() { }

    virtual void Draw() const = 0;
};

// 싱글톤으로 만드는 경우가 많습니다.
class ShapeFactory {
    MAKE_SINGLETON(ShapeFactory);

    using CREATOR = Shape* (*)();
    map<int, CREATOR> creator_map;

public:
    void RegisterShape(int type, CREATOR f)
    {
        creator_map[type] = f;
    }

    Shape* CreateShape(int type)
    {
        Shape* p = nullptr;
        if (creator_map[type] != nullptr) {
            p = creator_map[type]();
        }

        return p;
    }
};

// 제품을 공장에 자동으로 등록하는 클래스
class RegisterShape {
public:
    RegisterShape(int type, Shape* (*f)())
    {
        ShapeFactory& factory = ShapeFactory::GetInstance();
        factory.RegisterShape(type, f);
    }
};

// - 모든 도형은 자기 자신을 생성하는 정적 팩토리 함수를 약속합니다.
// - 모든 도형은 자신을 등록하기 위해 RegisterShape 클래스를 정적 멤버로 약속합니다.
// > 위의 약속을 편리하게 작성할 수 있는 도구(매크로)를 제공합니다.

#define REGISTER_SHAPE()          \
public:                           \
    static Shape* CreateObject(); \
    static RegisterShape rs

#define IMPLEMENT_REGISTER_SHAPE(classname, type)              \
    Shape* classname::CreateObject() { return new classname; } \
    RegisterShape classname::rs { type, &classname::CreateObject }

class Rect : public Shape {
public:
    void Draw() const override { cout << "Draw Rect" << endl; }
    REGISTER_SHAPE();
};
IMPLEMENT_REGISTER_SHAPE(Rect, 1);

class Circle : public Shape {
public:
    void Draw() const override { cout << "Draw Circle" << endl; }
    REGISTER_SHAPE();
};
IMPLEMENT_REGISTER_SHAPE(Circle, 2);

//-- 새로운 도형
class Triangle : public Shape {
public:
    void Draw() const override { cout << "Draw Triangle" << endl; }

    REGISTER_SHAPE();
};
IMPLEMENT_REGISTER_SHAPE(Triangle, 3);

int main()
{
    vector<Shape*> shapes;

    // factory.RegisterShape(1, &Rect::CreateObject);
    // factory.RegisterShape(2, &Circle::CreateObject);

    while (1) {
        int cmd;
        cin >> cmd;

        if (cmd >= 1 && cmd <= 5) {
            ShapeFactory& factory = ShapeFactory::GetInstance();

            Shape* p = factory.CreateShape(cmd);
            if (p != nullptr) {
                shapes.push_back(p);
            }
        }

        else if (cmd == 9) {
            for (auto e : shapes) {
                e->Draw();
            }
        } else if (cmd == 0) {
            break;
        }
    }

    for (auto e : shapes) {
        delete e;
    }
}