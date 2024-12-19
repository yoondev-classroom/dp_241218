// 14_Bridge3.cpp
#include <iostream>
using namespace std;

// interface MP3 {}
// - 기존의 자바는 인터페이스의 메소드에 기본 구현을 제공할 수 없습니다.
// - Modern Java(8)부터는 인터페이스에 기본 구현을 제공하는 문법이 도입되었습니다.
//   => defender method

// * 인터페이스의 문제점: 새로운 기능을 추가하기 어렵습니다.
class MP3 {

public:
    virtual ~MP3() { }

    virtual void Play() = 0;
    virtual void Stop() = 0;

    // 인터페이스에 새로운 기능을 추가할 때, 기본 구현을 제공하면
    // 기존의 모든 인터페이스의 구현체는 그 기능을 물려 받습니다.
    virtual void PlayOneMinute()
    {
        // 기본 구현을 제공하면 됩니다.
        Play();
        //...
        Stop();
    }
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

        mp3->PlayOneMinute();
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

    void PlayOneMinute() override
    {
        // 더 좋은 기능으로 재정의
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

    person.PlayMusic();
}