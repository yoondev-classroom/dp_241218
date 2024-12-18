// 6_공통성과가변서의분리5.cpp
#include <iostream>
using namespace std;

// 1. C++ - Policy Based Design(단위 전략)
// => 템플릿의 타입 파라미터를 이용해서, 컴파일 시간에 정책을 교체할 수 있습니다.
// => 실행 시간에 객체의 정책을 교체하는 것이 불가능합니다.
// => 암묵적인 인터페이스
//    - 문서적으로 어떤 함수의 이름과 시그니처를 가지는 약속합니다.

// => Idioms(관용구)
//    - 디자인 패턴에서는 "매개변수화 타입을 이용한 재사용 기법"

class MutexLock {
public:
    inline void Lock() { cout << "Mutex Lock" << endl; }
    inline void UnLock() { cout << "Mutex UnLock" << endl; }
};

class NoLock {
public:
    inline void Lock() { }
    inline void UnLock() { }
};

template <typename TYPE, typename SyncModel = NoLock>
class List {
    SyncModel lock;

public:
    void push_front(const TYPE& e)
    {
        lock.Lock();
        // ...
        lock.UnLock();
    }
};

// List<int, MutexLock> l;
// List<int, NoLock> l;
List<int> l;

int main()
{

    l.push_front(10);
    // ...
}