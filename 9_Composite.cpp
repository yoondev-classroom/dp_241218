// 9_Composite.cpp

#include <iostream>
#include <string>
using namespace std;

// 공통의 부모: Item
//              - GetSize()

int main()
{
    Folder* fol1 = new Folder("ROOT");
    Folder* fol2 = new Folder("A");

    File* f1 = new File("a.txt", 10); // 이름, 크기
    File* f2 = new File("b.txt", 20);

    fol2->AddItem(f1);
    fol1->AddItem(f2);
    fol1->AddItem(fol2);
    cout << f2->GetSize() << endl;
    cout << fol2->GetSize() << endl;
    cout << fol1->GetSize() << endl;
}