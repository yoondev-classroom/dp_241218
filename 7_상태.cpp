// 7_상태.cpp
#include <iostream>
using namespace std;

// * 상태에 따른 동작의 변경
// 1) 조건 분기
// => 새로운 아이템이 추가되면 조건 분기 문이 수정되어야 한다.
//    "OCP를 만족할 수 없습니다."
// => Replace type code with Strategy or State

class Hero {
    int item;

public:
    void SetItem(int n) { item = n; }

    void Attack()
    {
        if (item == 0) {
            cout << "Normal Attack" << endl;
        } else if (item == 1) {
            cout << "Fast Attack" << endl;
        } else if (item == 2) {
            cout << "Slow Attack" << endl;
        }
    }

    void Run()
    {
        if (item == 0) {
            cout << "Normal Run" << endl;
        } else if (item == 1) {
            cout << "Fast Run" << endl;
        } else if (item == 2) {
            cout << "Slow Run" << endl;
        }
    }
};