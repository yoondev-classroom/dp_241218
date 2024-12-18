// 4_추상클래스3.cpp
#include <iostream>
using namespace std;

// 1. 원인
//  - 강한 결합: 구체적인 타입에 의존하는 것
//  Car -----<> Camera

// 2. 약한 결합 / 느슨한 결합
//  Car -----<> <<BlackBox>>
//                   |
//                 -----------
//                 |          |
//                 Camera  FHDCamera

// 3. 약한 결합은 구체적인 타입에 의존하는 것이 아니라,
//    추상 타입(추상 클래스/인터페이스)에 의존하는 것을 의미합니다.
//  => DIP(Dependency Inversion Principle, 의존관계 역전 원칙)
//     : 구체적인 타입에 의존하는 것이 아니라, 추상 타입에 의존해야 한다.
//  => 교체 가능한 유연한 설계

// 1) 카메라의 제작자와 자동차의 제작자는 인터페이스(프로토콜)를 약속해야 합니다.
//    C++에서는 인터페이스를 만드는 별도의 문법이 제공되지 않습니다.
//    C++에서는 순수 가상 함수만을 가지는 클래스를 인터페이스라고 부릅니다.

class BlackBox {
public:
    virtual ~BlackBox() { }

    virtual void StartRecording() = 0;
    virtual void StopRecording() = 0;
};

// 2) 자동차의 제작자는 인터페이스를 이용하는 코드를 작성합니다.
class Car {
    BlackBox* camera;

public:
    Car(BlackBox* p)
        : camera { p }
    {
    }

    void Go()
    {
        camera->StartRecording();
        // ...
        camera->StopRecording();
    }
};

// 3) 모든 카메라의 제작자는 BlackBox의 인터페이스를 기반으로 제공되어야 합니다.
//   - "인터페이스를 상속한다" 라고 하지 않고
//     class Camera extends BlackBox {}
//     "인터페이스를 구현한다" 라고 합니다.
//     class Camera implements BlackBox {}

class Camera : public BlackBox {
public:
    void StartRecording() override
    {
        cout << "StartRecording" << endl;
    }
    void StopRecording() override
    {
        cout << "StopRecording" << endl;
    }
};

class FHDCamera : public BlackBox {
public:
    void StartRecording() override
    {
        cout << "[FHD]StartRecording" << endl;
    }
    void StopRecording() override
    {
        cout << "[FHD]StopRecording" << endl;
    }
};

int main()
{
    // Camera camera;
    FHDCamera camera; // !!
    Car car { &camera };

    car.Go();
}

// 디자인 패턴
// - 결론: 우리의 디자인 패턴은 리팩토링의 결과로 나온 구조를 반영한다.
//         디자인 패턴은 리팩토링의 목표점이 된다.
// 리팩토링(마틴 파울러)
// - 1판(자바) / 2판(자바스크립트 => 객체 지향 + 함수형)
// - 서론: 패턴은 도달하고 싶은 곳이고, 리팩토링은 그곳으로 가는 방법이다.

// 객체 지향 설계 5대 원칙 - SOLID
// 1) SRP(단일 책임 원칙)
// - 모든 것(클래스, 함수, 변수, 모듈)은 단 하나의 책임을 가져야 한다.

// 2) OCP(개방 폐쇄 원칙)
// - 확장에는 열려 있고, 수정에는 닫혀 있어야 한다.
//   새로운 기능이 추가되어도, 기존 코드는 수정되면 안된다.

// 3) LSP(리스코프의 치환 원칙)
// - 자식 클래스는 부모 클래스로 대체할 수 있어야 한다.(Upcasting)
// - 자식 클래스의 공통의 기능이 부모로부터 비롯되어야 한다.
// => 다형성

// 4) ISP(인터페이스 분리 원칙)
// - 범용 인터페이스보다 세분화된 인터페이스가 좋다.

// 5) DIP(의존 관계 역전 원칙)
// - 구체적인 타입에 의존하는 것이 아니라, 추상 타입(인터페이스, 추상 클래스)에 의존해야 한다.