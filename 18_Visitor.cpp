// 18_Visitor.cpp
#include <string>
#include <iostream>
#include <vector>
using namespace std;

// 방문자 패턴
// => 복합 객체의 내부 구조에 상관없이 요소 연산을 추가할 수 있는 객체

class PopupMenu;
class MenuItem;
class IMenuVisitor {
public:
    virtual ~IMenuVisitor() { }

    virtual void Visit(PopupMenu* p) = 0;
    virtual void Visit(MenuItem* p) = 0;
};

class IMenuAcceptor {
public:
    virtual ~IMenuAcceptor() { }
    virtual void Accept(IMenuVisitor* visitor) = 0;
};

class BaseMenu : public IMenuAcceptor {
    string title;

public:
    BaseMenu(const string& s)
        : title { s }
    {
    }

    virtual ~BaseMenu() { }

    string GetTitle() const { return title; }
    void SetTitle(const string& s) { title = s; } // !!!

    virtual void Command() = 0; // !
};

class PopupMenu : public BaseMenu {
    vector<BaseMenu*> menus;

public:
    void Accept(IMenuVisitor* visitor) override
    {
        visitor->Visit(this); // 자신을 전달합니다.

        for (auto e : menus) {
            e->Accept(visitor); // !!!
        }
    }

    PopupMenu(const string& s)
        : BaseMenu { s }
    {
    }

    ~PopupMenu()
    {
        for (auto e : menus) {
            delete e; // !!!
        }
    }

    void AddMenu(BaseMenu* p) { menus.push_back(p); }

    void Command() override
    {
        while (1) {
            system("cls");

            int sz = menus.size();
            for (int i = 0; i < sz; ++i) {
                cout << i + 1 << ". " << menus[i]->GetTitle() << endl;
            }
            cout << sz + 1 << ". 상위 메뉴로" << endl;

            cout << "메뉴를 선택하세요 >> ";
            int cmd;
            cin >> cmd;

            if (cmd == sz + 1) { // 상위 메뉴 선택
                break;
            }

            if (cmd < 1 || cmd > sz + 1) {
                continue;
            }

            menus[cmd - 1]->Command(); // 명령을 수행
        }
    }
};

class MenuItem : public BaseMenu {
public:
    MenuItem(const string& s)
        : BaseMenu { s }
    {
    }

    void Accept(IMenuVisitor* visitor) override
    {
        visitor->Visit(this); // 자신을 전달합니다.
    }

    void Command() override
    {
        cout << GetTitle() << " 선택됨" << endl;
        getchar();
        getchar();
    }
};

//-- 메뉴 시스템에 다양한 기능을 추가하는 방문자를 제공합니다.
// => 방문자 패턴을 적용하면, 기존의 클래스의 캡슐화 정책을 위배할 수 있습니다.
class TitleDecorator : public IMenuVisitor {
public:
    void Visit(PopupMenu* p) override
    {
        string s = p->GetTitle() + " >";
        p->SetTitle(s); // !!!
    }

    void Visit(MenuItem* p) override
    {
        string s = p->GetTitle() + " *";
        p->SetTitle(s);
    }
};

int main()
{
    PopupMenu* root = new PopupMenu("MENUBAR");
    PopupMenu* p1 = new PopupMenu("화면 설정");
    PopupMenu* p2 = new PopupMenu("소리 설정");

    root->AddMenu(p1);
    // root->AddMenu(p2);

    p1->AddMenu(p2);

    p1->AddMenu(new MenuItem("해상도 설정"));
    p1->AddMenu(new MenuItem("색상 설정"));
    p1->AddMenu(new MenuItem("기타 설정"));

    p2->AddMenu(new MenuItem("볼륨 설정"));
    p2->AddMenu(new MenuItem("음색 설정"));

    TitleDecorator d;
    root->Accept(&d);

    root->Command();

    delete root;
}