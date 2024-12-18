// 7_상태3.cpp
// 7_상태.cpp
#include <iostream>
using namespace std;

// * 상태에 따른 동작의 변경
// => 상태 패턴
// - 패턴의 이름은 패턴의 의도에 의해서 결정됩니다.
// * 전략 패턴: 객체가 사용하는 알고리즘을 실행시간에 교체
// * 상태 패턴: 객체의 상태에 따른 동작의 변화를 구현하는 설계

class IState {
public:
    virtual ~IState() { }

    virtual void Run() = 0;
    virtual void Attack() = 0;
};

class Hero {
    IState* state;
    int gold = 0;

public:
    void AddGold(int n) { gold += n; }
    void PrintGold() { cout << gold << endl; }
    void SetState(IState* s) { state = s; }

    void Run() { state->Run(); }
};

// 다양한 Item에 따른 동작을 정의합니다.
class NormalState : public IState {
public:
    void Run() override { cout << "Normal Run" << endl; }
    void Attack() override { }
};

class FastState : public IState {
public:
    void Run() override { cout << "Fast Run" << endl; }
    void Attack() override { }
};

class SlowState : public IState {
public:
    void Run() override
    {
        cout << "Slow Run" << endl;
    }
    void Attack() override { }
};

int main()
{
    NormalState ns;
    FastState fs;
    SlowState ss;

    Hero s;
    s.SetState(&ns);
    s.Run();
    s.AddGold(1000);

    s.SetState(&fs);
    s.Run();

    s.PrintGold();

    s.SetState(&ss);
    s.Run();
}