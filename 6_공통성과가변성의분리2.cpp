// 6_공통성과가변성의분리2.cpp
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

#if 0
class EditBox {
    string data;

public:
    string GetData()
    {
        getline(cin, data);
        return data;
    }
};

int main()
{
    EditBox edit;
    string s = edit.GetData();

    cout << s << endl;
}
#endif

// 변하는 것과 변하지 않는 것은 분리되어야 합니다.
// => "공통성과 가변성의 분리"
//  1) 변하는 정책을 가상함수를 통해 분리하고,
//     자식 클래스를 통해 재정의합니다. - Template Method Pattern

class EditBox {
    string data;

public:
    string GetData()
    {
        data.clear();

        while (1) {
            char ch = getch();
            if (ch == 13) {
                break;
            }

            if (isdigit(ch)) { // 정책은 변할 수 있습니다.
                data.push_back(ch);
                cout << ch;
            }
        }

        cout << endl;
        return data;
    }
};

int main()
{
    EditBox edit;
    string s = edit.GetData();

    cout << s << endl;
}