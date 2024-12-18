// 4_추상클래스3.cpp
#include <iostream>
using namespace std;

// 1. 원인
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