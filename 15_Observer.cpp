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

// 관찰의 대상
class Table {
    int data[5];
    vector<IObserver*> observers;

public:
    Table() { memset(data, 0, sizeof(data)); }

    void Notify()
    {
        for (auto e : observers) {
            e->OnUpdate(data);
        }
    }

    void Attach(IObserver* p) { observers.push_back(p); }
    void Edit()
    {
        while (1) {
            int index;
            cout << "index: ";
            cin >> index;

            cout << "data: ";
            cin >> data[index];

            Notify();
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