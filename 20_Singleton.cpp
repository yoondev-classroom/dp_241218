// 20_Singleton.cpp
#include <iostream>
using namespace std;

// C++은 전역 객체의 생성/소멸 시점이 표준에서 미지정되어 있습니다.

// Singleton Pattern
//  정의: 오직 한개의 객체를 만들 수 있고, 어디에서도 동일한 방법으로
//       객체를 얻을 수 있습니다.

// 아래의 구현 방식을
// "마이어스의 싱글톤" 이라고 합니다.

class Cursor {
private:
    Cursor() { } // 규칙 1. private 생성자

public:
    // 규칙 3. 복사/대입 금지
    //  - delete function
    Cursor(const Cursor& rhs) = delete;
    Cursor& operator=(const Cursor& rhs) = delete;

    // 규칙 2. 오직 한개의 객체만 생성하는 정적 멤버 함수
    static Cursor& GetInstance()
    {
        static Cursor instance; // 내부 정적 데이터 / 정적 지역 변수
        // 함수가 처음 호출되기 전에 초기화되고,
        // 함수가 더이상 호출되지 않을 때, 파괴됩니다.

        return instance;
    }
};

int main()
{
    Cursor& c = Cursor::GetInstance();
    cout << &c << endl;

    auto& c2 = Cursor::GetInstance();
    cout << &c2 << endl;
}