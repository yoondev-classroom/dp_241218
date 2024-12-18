// 6_공통성과가변성의분리8.cpp
#include <iostream>
using namespace std;

// 변하지 않는 전체 알고리즘에서 변해야 하는 정책 코드는 분리되어야 합니다.
// - 일반 함수에서는 변해야 하는 것을 함수 인자(함수 포인터)를 통해 뽑아냅니다.

void Sort(int* x, int n, bool (*cmp)(int, int))
{
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // if (x[i] < x[j]) {
            if (cmp(x[i], x[j])) {
                swap(x[i], x[j]);
            }
        }
    }
}

inline bool cmp1(int a, int b) { return a > b; }
inline bool cmp2(int a, int b) { return a < b; }

// 결론: 인라인 함수라고 하더라도, 함수 포인터를 통해 호출하면, 인라인 최적화가 불가능합니다.

int main()
{
    int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
    Sort(x, 10, &cmp2);

    for (auto e : x) {
        cout << e << endl;
    }
}