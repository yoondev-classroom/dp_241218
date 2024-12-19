// 12_ProxyClient2.cpp

#define USING_GUI
#include "dp.h"

// 서버를 대신하는 대리자(Proxy)를 만들어봅시다.
// - Proxy Pattern
//   : 기존 요소를 대신하는 대리자를 제공하는 방법
//   * Remote Proxy: 원격의 요소를 대신하는 대리자.

int main()
{
    // 1. 서버의 핸들을 얻어 옵니다.
    int server = ec_find_server("Calc");

    std::cout << "서버 번호: " << server << std::endl;

    // 2. 서버에 메세지를 전달합니다.
    int n1 = ec_send_server(server, 1, 10, 20);
    std::cout << n1 << std::endl;

    int n2 = ec_send_server(server, 2, 100, 50);
    std::cout << n2 << std::endl;
}