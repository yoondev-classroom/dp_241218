// 12_ProxyClient4.cpp
#define USING_GUI
#include "dp.h"
#include "ICalc2.h"

#if 0
int main()
{
    ICalc* calc = LoadProxy();

    std::cout << calc->Add(10, 20) << std::endl;
    std::cout << calc->Sub(100, 50) << std::endl;

    // delete calc; // 이렇게 해도 될까요?
    // DLL에서 new한 메모리를 실행 파일에서 delete 하는 것은 안전하지 않습니다.
    // 모듈간의 new/delete 로직이 다르기 때문입니다.
}

// 문제점: 서버의 제작자는 자신이 제작한 Proxy 객체의 수명을 관리하는 기능을
//        제공해야 합니다.
#endif

// 클라이언트는 해당 객체를 사용할 때, 규칙이 있습니다.
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