// 5_다형성2.cpp
#include <iostream>
#include <vector>
using namespace std;

class Shape {
public:
    virtual ~Shape() { } // !!!
    // virtual void Draw() const { cout << "Draw Shape" << endl; }

    virtual void Draw() const = 0;
};

class Rect : public Shape {
public:
    void Draw() const override { cout << "Draw Rect" << endl; }
};

class Circle : public Shape {
public:
    void Draw() const override { cout << "Draw Circle" << endl; }
};

class Triangle : public Shape {
public:
    void Draw() const override { cout << "Draw Triangle" << endl; }
};

// * 다형성은 OCP를 만족합니다!
// * 상속의 목적은 "다형성" 입니다.

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
        } else if (cmd == 3) {
            shapes.push_back(new Triangle);
        }

        else if (cmd == 9) {
            for (auto e : shapes) {
                e->Draw();
                // 다형성(Polymorphism)
                // e->Draw()        - e가 Rect면 -> Rect::Draw()
                //                      Circle  -> Circle::Draw()
                //                     Triangle -> Triangle::Draw()
            }
        } else if (cmd == 0) {
            break;
        }
    }

    for (auto e : shapes) {
        delete e;
    }
}

// Unix(Linux)
// => VFS(Virtual File System)
// - 모든 것은 파일입니다.
//   1. 일반 파일
//   2. 소켓 파일
//   3. 디바이스 특수 파일

// write -> 일반 파일에 데이터가 기록됩니다.
//          네트워크로 데이터가 전송됩니다.
//          디바이스에 명령을 전달합니다.