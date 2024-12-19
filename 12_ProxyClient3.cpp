// 12_ProxyClient3.cpp
#define USING_GUI
#include "dp.h"
#include "ICalc.h"

#if 0
// ProxyClient.dll을 통해 객체를 생성해야 합니다.
ICalc* LoadProxy()
{
    // 1. DLL Load
    //  - linux: dlopen / windows: LoadLibrary
    void* addr = ec_load_module("ProxyClient.dll");

    // 2. DLL 안에서 약속된 함수의 주소를 찾습니다.
    //  - linux: dlsym / windows: GetProcAddress
    using F = ICalc* (*)();
    F f = (F)ec_get_function_address(addr, "CreateCalc");

    // 3. 약속된 함수를 호출해서, Proxy 객체 생성
    ICalc* calc = f();

    return calc;
}
#endif

int main()
{
    // Windows: CoCreateInstance
    // Android: getSystemService

    ICalc* calc = LoadProxy();
    // 객체를 생성하는 행위는 강한 결합이 형성됩니다.
    // 객체를 직접 생성하면, 인터페이스를 기반으로 하여도, 강한 결합입니다.
    // - 외부에서 생성해서 전달받아야 합니다!
    //  : DI(Dependency Injection)

    std::cout << calc->Add(10, 20) << std::endl;
    std::cout << calc->Sub(100, 50) << std::endl;
}

// 서버 제작자
// - ICalc.h
// - ProxyClient.dll

// Remote Proxy
// => Android / Windows COM의 서브 시스템의 핵심입니다.