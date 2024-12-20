// 22_Factory.cpp
#include <iostream>
#include <vector>
using namespace std;

class Shape {
public:
    virtual ~Shape() { }

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