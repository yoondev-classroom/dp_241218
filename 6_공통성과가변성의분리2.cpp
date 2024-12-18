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

            if (isdigit(ch)) {
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