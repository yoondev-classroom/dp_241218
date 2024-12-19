// 14_Bridge2.cpp
#include <iostream>
using namespace std;

class MP3 {
public:
    virtual ~MP3() { }

    virtual void Play() = 0;
    virtual void Stop() = 0;
};

// Person은 인터페이스의 구현을 직접 사용하는 것이 아니라,
// 중간층을 통해서 사용하도록 변경해봅시다.

// 1. Person이 새로운 기능을 요구하면, MP3Bridge가 제공하면 됩니다.
//  => 인터페이스를 변경할 필요가 없습니다.
// 2. 인터페이스가 변경되어도, MP3 브릿지가 해당 기능을 제대로 구현해주면,
//    Person은 변경될 필요가 없습니다.

// 의도: 구현부의 변화없이 인터페이스를 변경하는 하는것 가능하고,
//      인터페이스의 변화 없이 구현부를 변경하는 것이 가능합니다.
//  => 상호 독립적인 변경이 가능합니다.

class MP3Bridge {
    MP3* mp3;

public:
    MP3Bridge(MP3* p)
        : mp3 { p }
    {
    }

    void Play() { mp3->Play(); }
    void Stop() { mp3->Stop(); }

    void PlayOneMinute()
    {
        mp3->Play();
        // 1분후 ...
        mp3->Stop();
    }
};

class Person {
    MP3Bridge* mp3;

public:
    Person(MP3Bridge* p)
        : mp3 { p }
    {
    }

    void PlayMusic()
    {
        mp3->Play();
        // ...
        mp3->Stop();

        mp3->PlayOneMinute(); // !!!
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

int main()
{
    Galaxy mp3;
    MP3Bridge bridge { &mp3 };

    Person person { &bridge };

    person.PlayMusic();
}