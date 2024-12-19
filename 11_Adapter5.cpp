// 11_Adapter5.cpp
#include <iostream>
using namespace std;

// 클라이언트가 stack을 요구합니다.
// 그런데 우리에게 list가 이미 있습니다.
#include <list>

// 기존 list를 한쪽으로 데이터를 넣고/빼는 형태로 스택처럼 사용할 수 있도록
// 만들어봅시다.

// public 상속
// - 부모의 인터페이스(외부로 공개된 함수)도 물려 받습니다.

// private 상속
// - 부모로부터 구현은 물려받지만(자식이 내부적으로 사용하지만)
//   인터페이스는 물려 받지 않겠다.(부모 함수를 외부에 노출하지 않겠다.)

#if 0
template <typename TYPE>
class stack : private list<TYPE> {
public:
    void push(const TYPE& a) { list<TYPE>::push_back(a); }
    void pop() { list<TYPE>::pop_back(); }
    TYPE& top() { return list<TYPE>::back(); }
};

int main()
{
    stack<int> s;

    s.push(100);
    s.push(200);
    s.push(300);

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();
}
#endif

// 대부분의 C++ 표준 라이브러리 구현에서,
// 상속을 통한 어답터가 아니라, 포함을 통한 어답터로 구현되어 있습니다.
#include <deque>

template <typename TYPE, typename Container = deque<TYPE>>
class stack {
    // list<TYPE> c;
    Container c;

public:
    void push(const TYPE& a) { c.push_back(a); }
    void pop() { c.pop_back(); }
    TYPE& top() { return c.back(); }
};

#include <vector>
#include <list>
// #include <stack>

int main()
{
    stack<int, vector<int>> s;
    stack<int, list<int>> s2;

    s.push(100);
    s.push(200);
    s.push(300);

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();
}