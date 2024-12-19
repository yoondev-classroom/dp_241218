// 16_MenuEvent3.cpp
#include <iostream>
#include <string>
using namespace std;

// 2. 핸들러(함수 포인터) 방식의 이벤트 처리
class Program {
public:
    void OpenFile() { cout << "OpenFile" << endl; } // Program::OpenFile
    void ExitProgram() { cout << "ExitProgram" << endl; } // Program::ExitProgram
};

// void (*f)()
void foo()
{
}

// 1. 일반 함수 포인터를 사용할 수 없습니다.
// 2. 특정한 타입에 종속적으로 만들어져서,
//   다른 클래스의 멤버 함수를 호출할 수 없습니다.
// => 범용 함수 포인터
// => 간접층 도입
//  1) 일반 함수 포인터의 역활을 수행하는 클래스
//  2) 멤버 함수 포인터의 역활을 수행하는 클래스(템플릿)
//  => 공통의 부모

class MenuItem {
    string title;

    // 멤버 함수 포인터
    // 1. 객체의 주소
    Program* obj;
    // 2. 멤버 함수 포인터 변수
    void (Program::*handler)();

public:
    void SetHandler(Program* o, void (Program::*h)())
    {
        obj = o;
        handler = h;
    }

    string GetTitle() const { return title; }

    MenuItem(const string& s)
        : title { s }
    {
    }

    void Command()
    {
        cout << GetTitle() << " 선택됨" << endl;

        // 멤버 함수 포인터를 호출하는 코드
        (obj->*handler)();
    }
};

int main()
{
    MenuItem m1 { "파일 열기" };
    MenuItem m2 { "프로그램 종료" };

    Program prog;

    m1.SetHandler(&prog, &Program::OpenFile);
    m2.SetHandler(&prog, &Program::ExitProgram);

    m1.Command();
    m2.Command();
}
