// 12_ProxyClient.cpp

#define USING_GUI
#include "dp.h"

// 문제점
// 1. 클라이언트의 제작자가 "IPC 기술"을 알아야 합니다.
// 2. 서버가 제공하는 모든 프로토콜을 직접 작성해야 합니다.

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