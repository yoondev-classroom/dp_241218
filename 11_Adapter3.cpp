// 11_Adapter3.cpp
#include <iostream>
#include <string>
using namespace std;

class Shape {
public:
    virtual ~Shape() { } // !!!

    virtual void Draw() const = 0;
};

class TextView {
    string data;

public:
    TextView(const string& s)
        : data { s }
    {
    }

    void Show() const { cout << data << endl; }
};

// 2) 포함
class Text : public Shape {
    TextView textView;

public:
    Text(const string& s)
        : textView { s }
    {
    }

    void Draw() const override
    {
        textView.Show();
    }
};

int main()
{
    Text t { "Hello" };
    t.Draw();

    Shape* p = &t;
    p->Draw();
}

// * 상속을 재사용의 목적으로 사용하는 것보다는
//   포함을 사용하는 것이 좋습니다.
// => 상속의 목적은 "다형성"