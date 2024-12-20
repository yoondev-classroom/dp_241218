// 13_Facade.cpp
#include <iostream>
using namespace std;

#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

// 복잡한 C의 API를 클래스로 래핑하면 좀더 편리하게 사용할 수 있습니다.

// RAII
class NetworkInit {
public:
    NetworkInit()
    {
        WSADATA w;
        WSAStartup(0x202, &w); // 네트워크 라이브러리 초기화
    }

    ~NetworkInit()
    {
        WSACleanup(); // 네트워크 라이브러리 정리
    }
};

class IPAddress {
    SOCKADDR_IN addr;

public:
    IPAddress(const char* ip, short port)
    {
        memset(&addr, 0, sizeof addr);
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = inet_addr(ip);
    }

    SOCKADDR* GetRawAddress() { return (SOCKADDR*)&addr; }
};

class Socket {
    int sock;

public:
    Socket(int type) { sock = socket(PF_INET, type, 0); }

    void Bind(IPAddress* addr)
    {
        bind(sock, addr->GetRawAddress(), sizeof(SOCKADDR_IN));
    }

    void Listen() { listen(sock, 5); }
    void Accept()
    {
        SOCKADDR_IN addr2 = { 0 };
        int sz = sizeof(addr2);
        accept(sock, (SOCKADDR*)&addr2, &sz);
    }
};

// Facade - TCP Server
//  : 하위 클래스의 복잡함을 단순화하는 상위 개념의 클래스를 제공하는 것
class TCPServer {
    NetworkInit init;
    Socket sock;

public:
    TCPServer()
        : sock { SOCK_STREAM }
    {
    }

    void Start(const char* aip, short port)
    {
        IPAddress ip { aip, port };
        sock.Bind(&ip);
        sock.Listen();
        sock.Accept();
    }
};

int main()
{
    TCPServer server;
    server.Start("127.0.0.1", 4000); // !!!
}

#if 0
// 아래 코드는 이해하기 쉽지만, TCP 서버의 절차를 이해해야 사용할 수 있습니다.
// => 복잡한 절차를 래핑하는 상위 클래스 - Facade Pattern
int main()
{
    NetworkInit init;

    Socket sock { SOCK_STREAM };
    IPAddress addr { "127.0.0.1", 4000 };

    sock.Bind(&addr);
    sock.Listen();
    sock.Accept();
}
#endif

#if 0
int main()
{
    WSADATA w;
    WSAStartup(0x202, &w); // 네트워크 라이브러리 초기화

    // 1. 소켓 생성
    int sock = socket(PF_INET, SOCK_STREAM, 0);

    // 2. 소켓 주소 지정
    SOCKADDR_IN addr = {
        0,
    };
    addr.sin_family = AF_INET;
    addr.sin_port = htons(4000);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(sock, (SOCKADDR*)&addr, sizeof addr);

    // 3. 소켓을 대기 상태로 변경
    listen(sock, 5);

    // 4. 클라이언트의 연결을 대기
    SOCKADDR_IN addr2 = { 0 };
    int sz = sizeof(addr2);
    accept(sock, (SOCKADDR*)&addr2, &sz);

    WSACleanup(); // 네트워크 라이브러리 정리
}
#endif