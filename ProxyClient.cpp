// ProxyClient.cpp
#define USING_GUI
#include "dp.h"
#include "ICalc.h"

class Calc : public ICalc {
    int server;

public:
    Calc() { server = ec_find_server("Calc"); }

    int Add(int a, int b) override { return ec_send_server(server, 1, a + 10, b); }
    int Sub(int a, int b) override { return ec_send_server(server, 2, a + 10, b); }
};

// 핵심!
// 서버 제작자는 자신이 만든 Proxy를 생성할 수 있는 방법도 제공해주어야 합니다.
// 함수의 이름이 변경되지 않도록 막아줍니다. - extern "C"
extern "C" __declspec(dllexport) ICalc*
CreateCalc()
{
    return new Calc;
}

// $ build.bat ProxyClient.cpp /LD