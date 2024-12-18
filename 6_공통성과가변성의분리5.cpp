// 6_공통성과가변서의분리5.cpp
#include <iostream>
using namespace std;

#include <mutex>

// List 컨테이너를 설계한다고 가정합시다.
template <typename TYPE>
class List {
    mutex m;

public:
    void push_front(const TYPE& e)
    {
        m.lock();
        // ...
        m.unlock();
    }
};

List<int> l;
// 동기화가 가능하도록 만들고 싶습니다.

int main()
{

    l.push_front(10);
    // ...
}