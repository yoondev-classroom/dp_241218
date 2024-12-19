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
    calc->AddRef();

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