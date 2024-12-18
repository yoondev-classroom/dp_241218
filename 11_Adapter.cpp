// 11_Adapter.cpp
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

int main()
{
    TextView tv { "Hello" };
    tv.Show();
}