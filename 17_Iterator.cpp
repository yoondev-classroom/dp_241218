// 17_Iterator.cpp
#include <iostream>
using namespace std;

// Iterator Pattern
// : 반복자 패턴
// 의도 - 컨테이너의 내부 구조에 상관없이 요소를 열거하는 객체

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
class SList {
    Node<T>* head;

public:
    SList()
        : head { nullptr }
    {
    }

    void push_front(const T& data) { head = new Node<T>(data, head); }
    T& front() { return head->data; }
};

int main()
{
    SList<int> s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);

    cout << s.front() << endl;
}