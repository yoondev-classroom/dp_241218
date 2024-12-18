// 9_Composite.cpp

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 공통의 부모: Item
//            - GetSize()

class Item {
    string name;

public:
    // 부모 클래스의 소멸자는 반드시 가상이어야 한다.
    virtual ~Item() { }

    Item(const string& s)
        : name { s }
    {
    }

    virtual int GetSize() const = 0;
};

class Folder : public Item {
    vector<Item*> items; // 재귀적 포함

public:
    Folder(const string& s)
        : Item { s }
    {
    }

    // 자신이 포함하는 자원을 정리해야하는 책임이 존재합니다.
    ~Folder()
    {
        for (auto e : items) {
            delete e; // !!
        }

        cout << "Folder 삭제" << endl;
    }

    void AddItem(Item* p) { items.push_back(p); }

    int GetSize() const override
    {
        int sum = 0;
        for (auto e : items) {
            sum += e->GetSize();
        }

        return sum;
    }
};

class File : public Item {
    int size;

public:
    File(const string& s, int n)
        : Item { s }
        , size { n }
    {
    }
    ~File() { cout << "파일 삭제" << endl; }

    int GetSize() const override { return size; }
};

int main()
{
    Folder* fol1 = new Folder("ROOT");
    Folder* fol2 = new Folder("A");

    File* f1 = new File("a.txt", 10); // 이름, 크기
    File* f2 = new File("b.txt", 20);

    fol2->AddItem(f1);
    fol1->AddItem(f2);
    fol1->AddItem(fol2);
    cout << f2->GetSize() << endl; // 20
    cout << fol2->GetSize() << endl; // 10
    cout << fol1->GetSize() << endl; // 30

    // 자원의 정리
    delete fol1; // 루트만 삭제하면 하위 객체가 모두 정리되어야 합니다.
}