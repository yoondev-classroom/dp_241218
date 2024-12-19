// 12_ProxyClient5.cpp
#define USING_GUI
#include "dp.h"
#include "ICalc2.h"

// 클라이언트는 해당 객체를 사용할 때, 규칙이 있습니다.
#if 0
int main()
{
    ICalc* calc = LoadProxy(); // 규칙 1. Proxy를 만들면, 참조 계수 증가
    calc->AddRef();

    ICalc* other = calc; // 규칙 2. 포인터를 복사하는 경우, 참조 계수 증가
    other->AddRef();

    std::cout << calc->Add(10, 20) << std::endl;
    std::cout << calc->Sub(100, 50) << std::endl;

    // 규칙 3. 더이상 사용하지 않는 포인터는 참조 계수 감소
    other->Release(); // ref: 2 -> 1
    calc->Release(); // ref: 1 -> 0
}
#endif

// 위의 규칙을 제대로 수행하지 않는 경우, 문제가 발생할 가능성이 있습니다.
// 위의 규칙을 자동으로 대신 수행해주는 대리자를 만들어봅시다.
//  - Smart Proxy

// C++은 포인터의 역활을 대신 수행하는 클래스를 "스마트 포인터" 라고 합니다.
template <typename T>
class sp {
    T* obj;

public:
    sp(T* p)
        : obj(p)
    {
        if (obj) {
            obj->AddRef();
        }
    }

    sp(const sp& other)
        : obj(other.obj)
    {
        if (obj) {
            obj->AddRef();
        }
    }

    ~sp()
    {
        if (obj) {
            obj->Release();
        }
    }

    // 연산자 오버로딩을 통해서, 포인터처럼 사용할 수 있는 기능을 제공할 수 있습니다.
    T* operator->() { return obj; }
    T& operator*() { return obj; }
};

int main()
{
    sp<ICalc> calc = LoadProxy();
    sp<ICalc> other = calc;

    std::cout << calc->Add(10, 20) << std::endl;
    std::cout << calc->Sub(100, 50) << std::endl;
}

// Obj-C
//  : MRC(Manual Ref Counting)
//  => ARC(Auto Ref Counting) / Swift
//   - 컴파일러가 코드를 분석해서, 자동으로 참조 계수 관련 코드를 삽입합니다.

// 참조 계수의 문제점
// 1) 순환 참조로 인해, 절대 파괴되지 않는 경우가 발생합니다.
//  - 참조 계수 라이브러리는 두가지 종류의 스마트 포인터를 제공합니다.
//    sp(Strong Pointer): 참조할 때, 참조 계수 증가
//    wp(Weak Pointer): 참조할 때, 참조 계수 증가되지 않습니다.
//                참조하는 객체가 유효한지 여부를 판단할 수 있는 기능을 제공합니다.
//                 - auto niling

//  - C++은 객체의 수명을 참조 계수로 관리할 수 있는 스마트 포인터를 제공합니다.
//    shared_ptr / weak_ptr

// 2) 참조 계수의 증감은 스레드 안전해야 합니다.
//  => Atomic Operations(원자적 연산을 통해 구현되어 있습니다.)

// C++은 2가지 종류의 스마트 포인터를 제공하고 있습니다.
// => 소유권(Ownership)
// 1) shared_ptr / weak_ptr - 참조 계수 기반
// 2) unique_ptr - 일반 스마트 포인터