// 16_MenuEvent.cpp
#include <iostream>
#include <string>
using namespace std;

class MenuItem {
    string title;

public:
    string GetTitle() const { return title; }

    MenuItem(const string& s)
        : title { s }
    {
    }

    void Command()
    {
        cout << GetTitle() << " 선택됨" << endl;
        // 선택된 사실을 외부에 알려주어야 합니다.
        // "객체가 이벤트를 발생한다." 라고 합니다.
    }
};

int main()
{
    MenuItem m1 { "파일 열기" };
    MenuItem m2 { "프로그램 종료" };

    m1.Command();
    m2.Command();
}
