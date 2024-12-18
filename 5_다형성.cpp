// 5_다형성.cpp
#include <iostream>
#include <vector>
using namespace std;

// 1. 각 도형의 클래스를 설계합니다.
// 2. 부모 클래스를 도입합니다.
//  => 하나의 컨테이너에 모든 도형을 보관할 수 있습니다.
//  => "동종을 보관하는 컨테이너 - Upcasting"
//   연관된 클래스를 묶어서 관리할 수 있습니다.

// 3. 자식 클래스의 공통의 특징을 부모의 포인터(참조)를 통해서 이용하기 위해서는
//    반드시 해당 특징이 부모로부터 비롯되어야 한다.
//  => LSP(Liskov Substitution Principle, 리스코프 치환 원칙)
//    - 자식 클래스는 부모 클래스로 대체할 수 있어야 한다.
//    - 자식의 공통의 기능은 부모로부터 비롯되어야 한다.

// 4. 자식이 재정의 하는 부모의 함수는 반드시 가상이어야 한다.
//    부모 클래스의 소멸자는 가상이어야 합니다.

class Shape {
public:
    virtual ~Shape() { } // !!!
    virtual void Draw() const { cout << "Draw Shape" << endl; }
};

class Rect : public Shape {
public:
    void Draw() const override { cout << "Draw Rect" << endl; }
};

class Circle : public Shape {
public:
    void Draw() const override { cout << "Draw Circle" << endl; }
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

#if 0
int main()
{
    vector<Rect*> rects;
    vector<Circle*> circles;
}
#endif