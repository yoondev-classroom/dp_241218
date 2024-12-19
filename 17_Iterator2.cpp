// 17_Iterator2.cpp
#include <iostream>
using namespace std;

// 반복자는 컨테이너의 설계자가 제공합니다.
template <typename T>
class IEnumerator {
public:
    virtual ~IEnumerator() { }

    virtual bool MoveNext() = 0;
    // 다음 위치로 이동하고, 요소가 존재하는지 여부를 반환하는 메소드
    virtual T& GetObject() = 0;
};

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

// 반복자
template <typename T>
class SListIterator : public IEnumerator<T> {
    Node<T>* current;

public:
    SListIterator(Node<T>* p = nullptr)
        : current { p }
    {
    }

    // 반복자는 2개의 가상함수를 재정의해야 합니다.
    bool MoveNext() override
    {
        current = current->next;
        return current != nullptr; // 존재하지 않을 경우, false를 반환합니다.
    }

    T& GetObject()
    {
        return current->data;
    }
};

// 모든 컨테이너는 자신의 요소를 순회하는 반복자를 제공하는 기능을 약속해야 합니다.
template <typename T>
class IEnumerable {
public:
    virtual ~IEnumerable() { }

    virtual IEnumerator<T>* GetEnumeratorN() = 0;
};

template <typename T>
class SList : public IEnumerable<T> {
    Node<T>* head;

public:
    SList()
        : head { nullptr }
    {
    }

    void push_front(const T& data) { head = new Node<T>(data, head); }
    T& front() { return head->data; }

    // ---
    IEnumerator<T>* GetEnumeratorN() override
    {
        return new SListIterator<T>(head);
    }
};

int main()
{
    SList<int> s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);

    IEnumerator<int>* pEnum = s.GetEnumeratorN();

    do {
        cout << pEnum->GetObject() << endl;
    } while (pEnum->MoveNext());
}