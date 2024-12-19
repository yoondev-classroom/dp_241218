// 17_Iterator4.cpp
#include <iostream>
using namespace std;

// C++의 표준 라이브러리: STL(Standard Template Library)
// 1) 컨테이너
// 2) 반복자
// 3) 알고리즘 => 컨테이너를 이용하는 다양한 연산을 일반 함수로 제공하고 있습니다.

// 1979년: C++ 언어 탄생
// 1998년: C++ 1.0 - STL이 처음 도입

// * 반복자 지원하는 연산에 따라 종류가 있습니다.
// 1) 입력 반복자
//  - *p(읽기)
// 2) 출력 반복자
//  - *p(쓰기)
// 3) 전진형 반복자
//  - *p(읽기/쓰기) / 다음 위치로 이동
// 4) 양방향 반복자
//  - *p(읽기/쓰기) / 다음 위치로 이동 / 앞으로 이동
// 5) 임의 접근 반복자
//  - 모두 가능
// => 자료 구조의 특성에 따라서 지원되는 반복자의 종류가 다릅니다.

#include <algorithm> // sort
#include <vector>
#include <list> // 임의 접근 반복자가 아닌 양방향 반복자만 지원합니다.

bool cmp1(int a, int b) { return a > b; }

int main()
{
    int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
    // list<int> x = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

    // sort(begin(x), end(x), &cmp1);
    sort(begin(x), end(x), [](int a, int b) { return a > b; });
    // x.sort(); // 알고리즘 함수를 통해 사용할 수 없는 경우, 멤버 함수로 제공합니다.

    for (auto e : x) {
        cout << e << endl;
    }
}

// C++ -> Rust
//        언어가 메모리 안정성을 보장합니다.