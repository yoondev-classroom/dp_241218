// 6_공통성과가변성의분리9.cpp
#include <iostream>
using namespace std;

// 함수 포인터 버전
#if 0
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
#endif

// 함수 객체
struct Compare {
    inline bool operator()(int a, int b) const { return a < b; }
};

struct Compare2 {
    inline bool operator()(int a, int b) const { return a > b; }
};
// 일반 함수
inline bool cmp1(int a, int b) { return a > b; }
inline bool cmp2(int a, int b) { return a < b; }

// void Sort(int* x, int n, Compare cmp)

// C++에서는 함수에서 정책을 템플릿 기반으로 전달받습니다.
// 1) 정책으로 함수 객체를 사용할 수 있습니다.
//   - 정책으로 호출되는 함수가 인라인 최적화가 가능합니다.
// 2) 정책으로 함수도 사용할 수 있습니다.
//   - 하나의 구현을 통해 여러개의 정책을 교체할 수 있습니다.
//   - 인라인 최적화가 불가능합니다.

template <typename C>
void Sort(int* x, int n, C cmp)
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

int main()
{
    int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
    Compare cmp;
    Sort(x, 10, &cmp1); // Sort(int, int, bool(*)(int, int));

    Sort(x, 10, [](int a, int b) { // 템플릿 기반이므로, 람다 표현식(함수 객체)으로도 정책을 교체할 수 있습니다.
        return a > b;
    });

    for (auto e : x) {
        cout << e << endl;
    }
}