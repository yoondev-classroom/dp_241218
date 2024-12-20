// 20_Singleton.cpp
#include <iostream>
using namespace std;

// 아래의 규칙을 일반화하는 방법을 제공해봅시다.
// => 매크로

#define MAKE_SINGLETON(classname)                        \
private:                                                 \
    classname() { }                                      \
                                                         \
public:                                                  \
    classname(const classname& rhs) = delete;            \
    classname& operator=(const classname& rhs) = delete; \
    static classname& GetInstance()                      \
    {                                                    \
        static classname instance;                       \
        return instance;                                 \
    }                                                    \
                                                         \
private:

class Cursor {
    MAKE_SINGLETON(Cursor)
};

int main()
{
    Cursor& c = Cursor::GetInstance();
    cout << &c << endl;

    auto& c2 = Cursor::GetInstance();
    cout << &c2 << endl;
}