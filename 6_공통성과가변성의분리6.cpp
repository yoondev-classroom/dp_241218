// 6_공통성과가변서의분리5.cpp
#include <iostream>
using namespace std;

#include <mutex>

// 방법 1. 전략 패턴
//  => 명시적인 인터페이스

class ISync {
public:
    virtual ~ISync() { }

    virtual void Lock() = 0;
    virtual void UnLock() = 0;
};

template <typename TYPE>
class List {
    ISync* sync;

public:
    void SetSync(ISync* p) { sync = p; }

    void push_front(const TYPE& e)
    {
        if (sync)
            sync->Lock(); // 가상 함수 호출 오버헤드
        // ...
        if (sync)
            sync->UnLock();
    }
};

class Sync : public ISync {
public:
    void Lock() override { cout << "동기화 시작" << endl; }
    void UnLock() override { cout << "동기화 종류" << endl; }
};

List<int> l;
// 동기화가 가능하도록 만들고 싶습니다.
int main()
{
    Sync sync;
    l.SetSync(&sync); // 실행시간에 정책을 교체할 수 있습니다.

    l.push_front(10);
    // ...
}