// 4_추상클래스2.cpp
#include <iostream>
using namespace std;

class Camera {
public:
    void StartRecording() { cout << "StartRecording" << endl; }
    void StopRecording() { cout << "StopRecording" << endl; }
};

// FHDCamera가 새롭게 개발되었습니다.
class FHDCamera {
public:
    void StartRecording() { cout << "[FHD]StartRecording" << endl; }
    void StopRecording() { cout << "[FHD]StopRecording" << endl; }
};

// OCP(Open Close Principle, 개방 폐쇄 원칙)
// - 확장에는 열려 있고,(새로운 기능이 추가되어도,)
//   수정에는 닫혀 있어야 한다.(기존 코드는 수정되면 안된다.)

// - 강한 결합이 형성되어 있기 때문입니다.
//   강한 결합: 구체적인 타입에 의존하고 있습니다.

class Car {
    Camera* camera;

public:
    Car(Camera* p)
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

int main()
{
    // FHDCamera camera;
    Camera camera;
    Car car { &camera };

    car.Go();
}
