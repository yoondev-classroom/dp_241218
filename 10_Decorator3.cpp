// 10_Decorator2.cpp
#include <iostream>
using namespace std;

class Item {
public:
    virtual ~Item() { }
    virtual void Draw() = 0; // !!!
};

class Picture : public Item {
public:
    void Draw() override { cout << "Draw Picture" << endl; }
};

class FrameDecorator : public Item {
    Item* pic; // 재귀적 포함!

public:
    FrameDecorator(Item* p)
        : pic { p }
    {
    }

    void Draw() override
    {
        pic->Draw(); // 원래 기능을 수행하고
        cout << "Draw Frame" << endl; // 추가 기능 수행
    }
};

class FlowerDecorator : public Item {
    Item* pic;

public:
    FlowerDecorator(Item* p)
        : pic { p }
    {
    }

    void Draw() override
    {
        pic->Draw();
        cout << "Draw Flower" << endl;
    }
};

// 핵심: 포장지(Decorator)는 객체를 포장하지만, 포장된 객체를 다시 포장할 수 있어야 합니다.
// => 재귀적 포함
// 1) 포장지와 포장해야 하는 객체가 동일한 부모를 가져야 합니다.
// 2) 포장지는 부모 타입을 포함할 수 있는 형태로 설계되어야 합니다.

// => Decorator Pattern / Wrapper

int main()
{
    Picture pic;
    pic.Draw();

    cout << "--------" << endl;
    FrameDecorator fd(&pic);
    fd.Draw();

    cout << "-------" << endl;
    FlowerDecorator fd2(&fd);
    fd2.Draw();
}