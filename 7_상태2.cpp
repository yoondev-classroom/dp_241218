// 7_상태.cpp
#include <iostream>
using namespace std;

// * 상태에 따른 동작의 변경
// 1) 변하는 것을 가상 함수로

class Hero {
    int gold = 0;

public:
    void AddGold(int n) { gold += n; }
    void PrintGold() { cout << gold << endl; }

    virtual void Run()
    {
        cout << "Normal Run" << endl;
    }
};

class FastItem : public Hero {
public:
    void Run() override
    {
        cout << "Fast Run" << endl;
    }
};

class SlowItem : public Hero {
public:
    void Run() override
    {
        cout << "Slow Run" << endl;
    }
};

int main()
{
    Hero* h;
    Hero normal;
    FastItem fast;
    SlowItem slow;

    // 초기 상태
    h = &normal;
    h->Run(); // Normal Run
    h->AddGold(1000);

    // 빠른 아이템을 획득
    h = &fast;
    h->Run(); // Fast Run
    h->PrintGold(); // ?

    // 느린 아이템을 획득
    h = &slow;
    h->Run(); // Slow Run
}