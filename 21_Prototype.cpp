// 21_Prototype.cpp
#include <iostream>
#include <vector>
using namespace std;

class Shape {
public:
    virtual ~Shape() { } // !!!

    virtual void Draw() const = 0;
    virtual Shape* Clone() const = 0;
};

// C++/Java/C#
// => Template / Generic
// => 공변 반환의 룰

class Rect : public Shape {
public:
    void Draw() const override { cout << "Draw Rect" << endl; }

    Rect* Clone() const override { return new Rect { *this }; }
};

class Circle : public Shape {
public:
    void Draw() const override { cout << "Draw Circle" << endl; }

    Circle* Clone() const override { return new Circle { *this }; }
};

int main()
{
    vector<Shape*> shapes;

    while (1) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            shapes.push_back(new Rect);
        } else if (cmd == 2) {
            shapes.push_back(new Circle);
        }

        //---
        else if (cmd == 5) {
            cout << "몇번째 도형 복제? ";

            int index;
            cin >> index;

            Shape* copy = shapes[index];
            shapes.push_back(copy->Clone());
            // Prototype Pattern
            // => 견본에 의한 객체 생성

// shapes[index]
//  : Rect?? Circle?? => RTTI(RunTime Type Information)
#if 0
            Shape* copy = shapes[index];
            if (typeid(*copy) == typeid(Rect)) {
                shapes.push_back(new Rect(*static_cast<Rect*>(copy)));
            } else if (typeid(*copy) == typeid(Circle)) {
                shapes.push_back(new Circle(*static_cast<Circle*>(copy)));
            }
#endif

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
#endif