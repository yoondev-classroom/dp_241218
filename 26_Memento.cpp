// 26_Memento.cpp
#include <iostream>
using namespace std;

#include <vector>

// 객체의 상태를 저장하고 복원하는 기능을 구현하고 싶습니다.
// => Memento Pattern
//   객체의 상태를 표현하는 클래스를 만들어서,
//   저장하고 복원하는 기능을 구현
//  : 외부에 캡슐화의 정책을 공개하지 않고, 객체 내부에서 상태를 저장하고 복원하는 기능을 제공합니다.
//    token

class Graphics {
    int penWidth = 0;
    int penColor = 1;
    int width = 100;
    int height = 200;

    // ....
    int temp1 = 10;
    int temp2 = 20;

    class Memento {
    public:
        int penWidth;
        int penColor;
        int width;
        int height;

        Memento(int p1, int p2, int w, int h)
            : penWidth { p1 }
            , penColor { p2 }
            , width { 2 }
            , height { h }
        {
        }
    };

    vector<Memento*> backup;

public:
    int CreateMemento()
    {
        Memento* m = new Memento { penWidth, penColor, width, height };
        backup.push_back(m);

        return backup.size() - 1;
    }

    void RestoreMemento(int token)
    {
        Memento* m = backup[token];

        penWidth = m->penWidth;
        penColor = m->penColor;
        width = m->width;
        height = m->height;
    }

    void DrawLine(int x1, int y1, int x2, int y2)
    {
    }

    void SetStrokeColor(int color) { penColor = color; }
    void SetStrokeWidth(int w) { penWidth = w; }
};

int main()
{
    Graphics g;

    g.SetStrokeColor(1000);
    g.SetStrokeWidth(10);
    // ...
    g.DrawLine(10, 10, 100, 100);

    int token = g.CreateMemento();

    g.SetStrokeColor(2);
    g.SetStrokeWidth(30);
    g.RestoreMemento(token); // !!
}