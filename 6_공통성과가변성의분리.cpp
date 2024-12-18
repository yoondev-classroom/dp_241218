// 6_공통성과가변성의분리.cpp
#include <iostream>
#include <vector>
using namespace std;

#include <mutex>

class Shape {
protected:
    mutex lock;

public:
    virtual ~Shape() { } // !!!

    // 변하지 않는 것은 부모가 비가상함수를 통해 제공하고,
    // 변하는 것은 가상함수를 통해 자식이 재정의하도록 합니다.
    // => Design Pattern
    //    "Template Method Pattern"
    // => C++
    //     NVI(Non Virtual Interface)
    void Draw()
    {
        lock.lock();
        DrawImpl();
        lock.unlock();
    }

protected:
    virtual void DrawImpl() = 0;
};

// * 요구사항: Draw()는 동기화되어야 합니다.
// * 공통성과 가변성의 분리
// = 변하는 것과 변하지 않는 것은 분리되어야 합니다.
// = 변하는 것을 가상 함수를 통해 분리할 수 있습니다.

class Rect : public Shape {
public:
#if 0
    void Draw() override
    {
        lock.lock();
        cout << "Draw Rect" << endl;
        lock.unlock();
    }

#endif
protected:
    void DrawImpl() override
    {
        cout << "Draw Rect" << endl;
    }
};

class Circle : public Shape {
public:
#if 0
    void Draw() override
    {
        lock.lock();
        cout << "Draw Circle" << endl;
        lock.unlock();
    }
#endif
protected:
    void DrawImpl() override
    {
        cout << "Draw Circle" << endl;
    }
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