// ICalc2.h

#ifndef ICALC_H_
#define ICALC_H_

#define USING_GUI
#include "dp.h"

class ICalc {
public:
    virtual ~ICalc() { }

    virtual int Add(int a, int b) = 0;
    virtual int Sub(int a, int b) = 0;

    virtual void AddRef() = 0;
    virtual void Release() = 0;
};

// ProxyClient.dll을 통해 객체를 생성해야 합니다.
ICalc* LoadProxy()
{
    // 1. DLL Load
    //  - linux: dlopen / windows: LoadLibrary
    void* addr = ec_load_module("ProxyClient2.dll");

    // 2. DLL 안에서 약속된 함수의 주소를 찾습니다.
    //  - linux: dlsym / windows: GetProcAddress
    using F = ICalc* (*)();
    F f = (F)ec_get_function_address(addr, "CreateCalc");

    // 3. 약속된 함수를 호출해서, Proxy 객체 생성
    ICalc* calc = f();

    return calc;
}

#endif
