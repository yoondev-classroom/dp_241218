// 17_Iterator3.cpp
#include <iostream>
using namespace std;

// C++은 반복자를 배열에서 포인터의 역활과 동일하게 사용할 수 있도록 설계되어 있습니다.
// 1) 반복자의 모든 연산은 인라인 최적화가 가능합니다. - 가상 함수가 아닙니다.
// 2) 배열을 다루는 방식과 컨테이너를 다루는 방식이 동일합니다.
//    컨테이너를 다루는 모든 연산을 배열과 함께 사용할 수 있습니다.

#if 1
template <typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& a, Node* n)
        : data { a }
        , next { n }
    {
    }
};

template <typename T>
class SListIterator {
    Node<T>* current;

public:
    SListIterator(Node<T>* p = nullptr)
        : current { p }
    {
    }

    // 참조: *p
    inline T& operator*() { return current->data; }

    // 다음 위치 이동: ++p
    // void operator++()

    inline SListIterator& operator++()
    {
        current = current->next;
        return *this; // !!
        // 연쇄 호출이 가능합니다.
    }

    // 비교: == / !=
    inline bool operator!=(const SListIterator& rhs)
    {
        return current != rhs.current;
    }

    inline bool operator==(const SListIterator& rhs)
    {
        return current == rhs.current;
    }
};

template <typename T>
class SList {
    Node<T>* head;

public:
    using iterator = SListIterator<T>;

    SList()
        : head { nullptr }
    {
    }

    void push_front(const T& data) { head = new Node<T>(data, head); }
    T& front() { return head->data; }

    // 모든 컨테이너의 설계자는 자신이 설계한 컨테이너 요소의 처음과 마지막 다음을 가르키는
    // 반복자를 꺼내는 연산을 제공해야 합니다.
    iterator begin() { return SListIterator<T> { head }; }
    iterator end() { return SListIterator<T>(nullptr); }
};

#include <list>

#if 0
// 연산자 오버로딩을 구현할 때, 기본 타입이 동작하는 방식과 동일하게 구현되어야 합니다.
int main()
{
    int n = 0;
    ++ ++n;

    cout << n << endl;
}
#endif

#if 1
int main()
{
    SList<int> s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);

    // SList<int>::iterator p1 = s.begin();
    // SList<int>::iterator p2 = s.end();

    auto p1 = begin(s); // s.begin()
    auto p2 = end(s); // s.end()

    while (p1 != p2) {
        cout << *p1 << endl;
        ++p1;
    }
}
#endif

#endif

// C++은 반개 구간을 사용합니다.
// - [begin, end)
#if 0
int main()
{
    //             p1            p2
    //              |             |
    int data[5] = { 1, 2, 3, 4, 5 };

    // int* p1 = &data[0];
    int* p1 = data; // C/C++에서 배열의 이름은 배열의 첫번째 원소의 주소로 해석됩니다. - Decay
    int* p2 = data + 5;

    while (p1 != p2) { // 1) 현재 가르키는 위치가 동일한지 동일하지 않은지 비교하는 연산자
        cout << *p1 << endl; // 2) 현재 가르키는 위치의 요소를 참조하는 연산자
        ++p1; // 3) 다음 위치로 이동하는 연산자
    }
}
#endif

#if 0
// 반복자 패턴
// - 컨테이너의 내부 구조에 상관없이 요소를 열거하는 객체

#include <vector>
#include <list>

int main()
{
    // double data[5] = { 1, 2, 3, 4, 5 };
    // vector<int> data = { 1, 2, 3, 4, 5 };
    list<int> data = { 1, 2, 3, 4, 5 };

    // begin(): 시작 위치
    // end() : 끝 다음 위치(past the end)
    auto p1 = begin(data);
    auto p2 = end(data);

    while (p1 != p2) {
        cout << *p1 << endl;
        ++p1;
    }
}
#endif