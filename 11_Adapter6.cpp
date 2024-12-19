// 11_Adapater6.cpp
#include <iostream>
#include <vector>
using namespace std;

// [begin, end): 반개 구간

int main()
{
    //               p1                            p2(마지막 요소 다음 위치)
    //                |                             |
    vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Iterator(반복자)
    vector<int>::iterator p1 = v.begin(); // 첫번째 요소를 가르키는 포인터의 역활을 수행하는 객체
    vector<int>::iterator p2 = v.end();
    // 마지막 요소를 가르키는 포인터의 역활을 수행하는 객체
    // - past the end

    while (p1 != p2) {
        cout << *p1 << endl; // 요소 참조
        ++p1; // 다음 위치 이동
    }

    // STL Iterator Adapter
    std::reverse_iterator<vector<int>::iterator> p3 { v.end() };
    std::reverse_iterator<vector<int>::iterator> p4 { v.begin() };

    while (p3 != p4) {
        cout << *p3 << endl; // 요소 참조
        ++p3; // 다음 위치 이동
    }
}