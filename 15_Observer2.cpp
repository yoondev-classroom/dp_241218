// 15_Observer.cpp
// : 중요한 개념입니다.
//   - 관찰자 패턴
//   - publish-subscribe

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class IObserver {
public:
    virtual ~IObserver() { }

    virtual void OnUpdate(void* data) = 0;
};

// 관찰의 대상 - Subject
// - Subject의 로직은 변하지 않습니다.
// - 별도의 부모 클래스를 통해 변하지 않는 로직을 제공해줍니다.
class Subject {
    vector<IObserver*> observers;

public:
    virtual ~Subject() { }

    void Notify(void* p)
    {
        for (auto e : observers) {
            e->OnUpdate(p);
        }
    }

    void Attach(IObserver* p) { observers.push_back(p); }
};

class Table : public Subject {
    int data[5];

public:
    Table() { memset(data, 0, sizeof(data)); }

    void Edit()
    {
        while (1) {
            int index;
            cout << "index: ";
            cin >> index;

            cout << "data: ";
            cin >> data[index];

            Notify(data);
        }
    }
};

// 관찰자: 그래프
class PieGraph : public IObserver {
public:
    void OnUpdate(void* p)
    {
        int* data = static_cast<int*>(p);
        cout << "****** PieGraph ******" << endl;
        for (int i = 0; i < 5; ++i) {
            cout << i << ": " << data[i] << endl;
        }
    }
};

class BarGraph : public IObserver {
public:
    void OnUpdate(void* p)
    {
        int* data = static_cast<int*>(p);
        cout << "****** BarGraph ******" << endl;
        for (int i = 0; i < 5; ++i) {
            cout << i << ": " << data[i] << endl;
        }
    }
};

int main()
{
    Table table;
    PieGraph pg;
    BarGraph bg;

    table.Attach(&pg);
    table.Attach(&bg);

    table.Edit();
}