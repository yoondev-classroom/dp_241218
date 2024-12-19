// 11_Adapter2.cpp
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

// Adapter Pattern
// => 인터페이스를 변경해서, 새로운 클래스처럼 보이게하는 설계 방법

// 1) 상속
// => 부모가 제공하는 모든 인터페이스가 외부에 노출됩니다.
// class Text : public TextView, public Shape {
class Text : private TextView, public Shape {
public:
    Text(const string& s)
        : TextView { s }
    {
    }

    void Draw() const override
    {
        TextView::Show(); // !!!
    }
};

int main()
{
    Text t { "Hello" };
    t.Draw();

    Shape* p = &t;
    p->Draw(); // !!!
}