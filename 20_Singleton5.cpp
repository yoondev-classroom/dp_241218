#include <iostream>
using namespace std;

class Cursor {
private:
    Cursor() { }

public:
    Cursor(const Cursor& rhs) = delete;
    Cursor& operator=(const Cursor& rhs) = delete;

    // C++11 이후로 정적 지역 변수를 통해 참조하는 new 객체에 대한 초기화가
    // 스레드 안전하다는 것을 표준적으로 보장합니다.
    static Cursor& GetInstance()
    {
        static Cursor* instance = new Cursor;
        return *instance;
    }
};

int main()
{
    Cursor& c = Cursor::GetInstance();
    cout << &c << endl;

    auto& c2 = Cursor::GetInstance();
    cout << &c2 << endl;
}