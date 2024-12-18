// 10_Decorator.cpp
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

// 1) 상속을 통한 기능의 추가
// => pic 객체에 기능이 추가된 것이 아니라,
//    새로운 기능을 가지는 클래스를 만든 것 입니다.
// => 객체가 아닌 클래스에 기능이 추가됩니다.
class Picture {
public:
    void Draw() { cout << "Draw Picture" << endl; }
};

class FramePicture : public Picture {
public:
    void Draw()
    {
        Picture::Draw(); // 원래 기능을 수행하고
        cout << "Draw Frame" << endl; // 추가 기능을 수행
    }
};

int main()
{
    Picture pic;
    pic.Draw();
    cout << "------" << endl;

    FramePicture fp;
    fp.Draw();
}