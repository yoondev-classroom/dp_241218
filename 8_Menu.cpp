// 8_Menu.cpp
#include <string>
#include <iostream>
#include <vector>
using namespace std;

#if 0


class PopupMenu {
    string title;

public:
    string GetTitle() const { return title; }
};

class MenuItem {
    string title;

public:
    string GetTitle() const { return title; }

    void Command()
    {
        cout << GetTitle() << " 선택됨" << endl;
    }
};

#endif

// 1) PopupMenu
// - MenuItem 뿐 아니라, PopUpMenu도 포함할 수 있습니다.
// => MenuItem과 PopupMenu는 공통의 부모가 필요합니다.
// 2) PopupMenu와 MenuItem을 처리하는 메소드가 동일합니다. - Command
// => 부모 클래스(BaseMenu)를 통해 제공되는 기능입니다.

class BaseMenu {
    string title;

public:
    BaseMenu(const string& s)
        : title { s }
    {
    }

    virtual ~BaseMenu() { }

    string GetTitle() const { return title; }

    virtual void Command() = 0; // !
};

// PopupMenu => 재귀적 포함 설계가 적용되어 있습니다.
//           => Composite 패턴
class PopupMenu : public BaseMenu {
    vector<BaseMenu*> menus;

public:
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

    void Command() override
    {
        cout << GetTitle() << " 선택됨" << endl;
        getchar();
        getchar();
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

    root->Command();

    delete root;
}

// Ownership - 소유권