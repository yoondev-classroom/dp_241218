// 16_MenuEvent2.cpp
#include <iostream>
#include <string>
using namespace std;

// 1. 인터페이스 기반의 리스너: Java, 안드로이드, 타이젠C++
//  => 이벤트를 발생시킨 sender를 구분할 수 있는 정보를 추가적으로 전달해야 합니다.

// 메뉴 이벤트를 수신하고 싶은 모든 클래스는 아래 인터페이스를 구현해야 합니다.
class IMenuListener {
public:
    virtual ~IMenuListener() { }

    virtual void OnCommand(int id) = 0;
};

class MenuItem {
    int id;
    string title;
    IMenuListener* listener = nullptr;

public:
    string GetTitle() const { return title; }
    void SetListener(IMenuListener* p) { listener = p; }

    MenuItem(int i, const string& s)
        : id { i }
        , title { s }
    {
    }

    void Command()
    {
        cout << GetTitle() << " 선택됨" << endl;
        // 선택된 사실을 외부에 알려주어야 합니다.
        // "객체가 이벤트를 발생한다." 라고 합니다.

        if (listener) {
            listener->OnCommand(id);
        }
    }
};

class Program : public IMenuListener {

public:
    enum EventID {
        OPEN_FILE = 100,
        EXIT_PROGRAM
    };

    void OpenFile() { cout << "OpenFile" << endl; }
    void ExitProgram() { cout << "ExitProgram" << endl; }

    void OnCommand(int id) override
    {
        cout << "메뉴 이벤트 수신" << endl;

        switch (id) {
        case EventID::OPEN_FILE:
            OpenFile();
            break;
        case EventID::EXIT_PROGRAM:
            ExitProgram();
            break;
        }
    }
};

int main()
{
    Program prog;

    MenuItem m1 { Program::EventID::OPEN_FILE, "파일 열기" };
    MenuItem m2 { Program::EventID::EXIT_PROGRAM, "프로그램 종료" };

    m1.SetListener(&prog);
    m2.SetListener(&prog);

    m1.Command();
    m2.Command();
}
