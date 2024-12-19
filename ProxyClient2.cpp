// ProxyClient.cpp
#define USING_GUI
#include "dp.h"
#include "ICalc2.h"

// 참조 계수 기반으로 객체의 수명을 관리합니다.
class Calc : public ICalc {
    int server;
    int ref;

public:
    Calc()
        : ref { 0 }
    {
        server = ec_find_server("Calc");
    }

    ~Calc()
    {
        std::cout << "~Calc()" << std::endl;
    }

    void AddRef() { ++ref; }
    void Release()
    {
        if (--ref == 0) {
            delete this;
        }
    }

    int Add(int a, int b) override { return ec_send_server(server, 1, a + 10, b); }
    int Sub(int a, int b) override { return ec_send_server(server, 2, a + 10, b); }
};

extern "C" __declspec(dllexport) ICalc*
CreateCalc()
{
    return new Calc;
}