// 10_Decorator2.cpp
#include <iostream>
using namespace std;

#if 0
class Picture {
public:
    void Draw() { cout << "Draw Picture" << endl; }
};

int main()
{
    Picture pic;
    pic.Draw();
}
#endif
class Picture {
public:
    void Draw() { cout << "Draw Picture" << endl; }
};

// 2) 포함을 이용한 기능의 추가
// => 동적인 기능의 추가를 구현할 수 있습니다.
class FrameDecorator {
    Picture* pic;

public:
    FrameDecorator(Picture* p)
        : pic { p }
    {
    }

    void Draw()
    {
        pic->Draw(); // 원래 기능을 수행하고
        cout << "Draw Frame" << endl; // 추가 기능 수행
    }
};

class FlowerDecorator {
    Picture* pic;

public:
    FlowerDecorator(Picture* p)
        : pic { p }
    {
    }

    void Draw()
    {
        pic->Draw();
        cout << "Draw Flower" << endl;
    }
};

// 핵심: 포장지(Decorator)는 객체를 포장하지만, 포장된 객체를 다시 포장할 수 있어야 합니다.
// => 재귀적 포함
// 1) 포장지와 포장해야 하는 객체가 동일한 부모를 가져야 합니다.
// 2) 포장지는 부모 타입을 포함할 수 있는 형태로 설계되어야 합니다.

int main()
{
    Picture pic;
    pic.Draw();

    FrameDecorator fd(&pic);
    fd.Draw();
}