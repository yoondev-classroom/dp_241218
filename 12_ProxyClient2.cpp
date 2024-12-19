// 12_ProxyClient2.cpp

#define USING_GUI
#include "dp.h"

// 서버를 대신하는 대리자(Proxy)를 만들어봅시다.
// - Proxy Pattern
//   : 기존 요소를 대신하는 대리자를 제공하는 방법
//   * Remote Proxy: 원격의 요소를 대신하는 대리자.
//    : RPC / RMI

// Proxy는 "서버 제작자가 만들어서 배포" 합니다.
// 1. ICalc.h
// 2. ProxyClient.dll
//    - 객체를 생성할 수 있는 약속된 함수

class Calc {
    int server;

public:
    Calc() { server = ec_find_server("Calc"); }

    int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
    int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

// 장점
// 1. Client 제작자는 IPC의 개념을 몰라도 됩니다.
// 2. 프로토콜을 직접 구현하는 것이 아니라, 클래스의 멤버 함수를 통해
//    해당 기능을 이용할 수 있습니다.ㄸ

int main()
{
    Calc* calc = new Calc; // !!! 강한 결합

    std::cout << calc->Add(10, 20) << std::endl;
    std::cout << calc->Sub(100, 50) << std::endl;
}

// DIP: 의존관계 역전 원칙
// - 구체적인 타입이 아니라 추상 타입(인터페이스/추상 클래스)에 의존해야 한다.
// - 의존하는 객체를 직접 생성하는 것이 아니라,
//   외부에서 생성해서 전달 받아야 합니다.(DI, 의존성 주입)