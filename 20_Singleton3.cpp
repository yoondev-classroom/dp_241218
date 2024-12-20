// 20_Singleton3.cpp
#include <iostream>
using namespace std;

class Mutex {
public:
    void Lock() { cout << "Mutex Lock" << endl; }
    void Unlock() { cout << "Mutex Unlock" << endl; }

    // 생성자/소멸자를 통해 자원의 초기화와 해제를 관리하면 편리합니다.
    // => 예외가 발생해도 안전하게 해제할 수 있습니다.
    // RAII(Resource Acqution Is Initialize)
    class AutoLock {
        Mutex& mLock;

    public:
        AutoLock(Mutex& m)
            : mLock { m }
        {
            mLock.Lock();
        }

        ~AutoLock() { mLock.Unlock(); }
    };
};

// 힙에 생성하는 싱글톤
class Cursor {
private:
    Cursor() { }

    Cursor(const Cursor&) = delete;
    Cursor& operator=(const Cursor&) = delete;

    static Cursor* sInstance;
    static Mutex sLock;

public:
#if 0
    static Cursor& GetInstance()
    {
        sLock.Lock();
        if (sInstance == nullptr) {
            sInstance = new Cursor;
            //  new는 메모리 할당에 실패할 경우, 예외가 발생합니다.
            //  예외가 발생할 경우, Unlock이 수행되지 않아서, 데드락의 위험성이 존재합니다.
        }
        sLock.Unlock();

        return *sInstance;
    }
#endif

#if 0
    static Cursor& GetInstance()
    {
        sLock.Lock();
        try {
            if (sInstance == nullptr) {
                sInstance = new Cursor;
                //  new는 메모리 할당에 실패할 경우, 예외가 발생합니다.
                //  예외가 발생할 경우, Unlock이 수행되지 않아서, 데드락의 위험성이 존재합니다.
            }
            sLock.Unlock();
        } catch (...) {
            sLock.Unlock();
        }

        return *sInstance;
    }
#endif

    static Cursor& GetInstance()
    {

        Mutex::AutoLock al { sLock };
        if (sInstance == nullptr) {
            sInstance = new Cursor;
        }

        return *sInstance;
    }
};

Cursor* Cursor::sInstance = nullptr;
Mutex Cursor::sLock;

class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    ~Sample() { cout << "~Sample()" << endl; }
};

void foo()
{
    Sample s;

    throw 1; // 예외 발생!!!
    // 지역 객체가 존재하는 함수에서 예외가 발생하더라도, 소멸자의 호출은 보장됩니다.
}

int main()
{
    try {
        foo();
    } catch (...) {
    }

    Cursor& c = Cursor::GetInstance();
    cout << &c << endl;

    auto& c2 = Cursor::GetInstance();
    cout << &c2 << endl;
}