// 20_Singleton4.cpp
#include <iostream>
using namespace std;

class Mutex {
public:
    void Lock() { cout << "Mutex Lock" << endl; }
    void Unlock() { cout << "Mutex Unlock" << endl; }

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

template <typename TYPE>
class Singleton {

protected:
    Singleton() { }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    static TYPE* sInstance;
    static Mutex sLock;

public:
    static TYPE& GetInstance()
    {

        Mutex::AutoLock al { sLock };
        if (sInstance == nullptr) {
            sInstance = new TYPE;
        }

        return *sInstance;
    }
};

template <typename TYPE>
TYPE* Singleton<TYPE>::sInstance = nullptr;

template <typename TYPE>
Mutex Singleton<TYPE>::sLock;

// CRTP
class Cursor : public Singleton<Cursor> {
};

int main()
{
    Cursor& c = Cursor::GetInstance();
    cout << &c << endl;

    auto& c2 = Cursor::GetInstance();
    cout << &c2 << endl;
}