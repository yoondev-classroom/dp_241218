// 14_Bridge.cpp
#include <iostream>
using namespace std;

// * 인터페이스 기반 설계의 문제점!
// => 인터페이스에 새로운 기능을 추가하기가 어렵습니다.
//    인터페이스 자체의 변화에 대응하기가 어렵습니다.

// => ISP(Interface Segregation Principle, 인터페이스 분리 원칙)
//   : 범용화된 인터페이스보다 세분화된 인터페이스가 낫다.

// mp3 Interface
class MP3 {
public:
    virtual ~MP3() { }

    virtual void Play() = 0;
    virtual void Stop() = 0;

    // virtual void PlayOneMinute() = 0; // !!!
};

class Person {
    MP3* mp3;

public:
    Person(MP3* p) // 생성자 주입
        : mp3 { p }
    {
    }

    void PlayMusic()
    {
        mp3->Play();
        // ...
        mp3->Stop();
    }

    void Play(MP3* mp3) // 메소드 주입
    {
        // ...
    }
};

class Galaxy : public MP3 {
public:
    void Play() override
    {
        cout << "Play()" << endl;
    }

    void Stop() override
    {
        cout << "Stop()" << endl;
    }
};

class ApplePhone : public MP3 {
public:
    void Play() override
    {
        cout << "Play()" << endl;
    }

    void Stop() override
    {
        cout << "Stop()" << endl;
    }
};

int main()
{
    ApplePhone mp3;
    Person person { &mp3 };
    // DI: 외부에서 생성해서 전달받아야 합니다.
    // - 생성자 주입: 필수적일 때
    // - 메소드 주입: 필수적이지 않을 때
    // 문제점: 객체를 생성할 때, 의존성 관리로 인한 보일러플레이트가 발생합니다.
    //  => 의존성 주입 프레임워크를 사용하는 경우도 많습니다.

    person.PlayMusic();
}