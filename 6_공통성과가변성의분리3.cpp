// 6_공통성과가변성의분리3.cpp
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

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

            if (Validate(ch)) { // 정책은 변할 수 있습니다.
                data.push_back(ch);
                cout << ch;
            }
        }

        cout << endl;
        return data;
    }

    virtual bool Validate(char ch)
    {
        return true;
    }
};

// * 라이브러리의 사용자는 새로운 정책이 필요할 때마다, 새로운 클래스를 정의해서
//   정책 함수를 재정의하면 됩니다.
class NumberEditBox : public EditBox {
public:
    bool Validate(char ch) override
    {
        return isdigit(ch);
    }
};

int main()
{
    // EditBox edit;
    NumberEditBox edit; // !!
    string s = edit.GetData();

    cout << s << endl;
}