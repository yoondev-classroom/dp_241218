// 6_공통성과가변성의분리4.cpp
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// 변하는 것과 변하지 않는 것은 분리되어야 합니다.
// => "공통성과 가변성의 분리"
//  1) 변하는 정책을 가상함수를 통해 분리하고,
//     자식 클래스를 통해 재정의합니다. - Template Method Pattern

//  2) 변하는 것을 다른 클래스로 분리
//    - 인터페이스 기반의 클래스로 분리해야 합니다.(느슨한 결합) => 교체가 가능합니다.
//    - Strategy Pattern(전략 패턴) / Policy

// 인터페이스를 설계합니다.
class IValidator {
public:
    virtual ~IValidator() { }

    virtual bool validate(string s, char ch) = 0;
};

class EditBox {
    string data;
    IValidator* pValidator = nullptr;

public:
    void SetValidator(IValidator* p) { pValidator = p; }

    string GetData()
    {
        data.clear();

        while (1) {
            char ch = getch();
            if (ch == 13) {
                break;
            }

            if (pValidator == nullptr || pValidator->validate(data, ch)) { // 정책은 변할 수 있습니다.
                data.push_back(ch);
                cout << ch;
            }
        }

        cout << endl;
        return data;
    }
};

// Validation 정책을 담은 정책 클래스를 설계합니다.
class LimitDigitValidator : public IValidator {
    int value;

public:
    LimitDigitValidator(int v)
        : value { v }
    {
    }

    bool validate(string s, char ch) override
    {
        if (s.size() < value && isdigit(ch)) {
            return true;
        }

        return false;
    }
};

int main()
{
    EditBox edit;
    LimitDigitValidator v { 5 };

    edit.SetValidator(&v); // 정책의 변경
    string s = edit.GetData();

    cout << s << endl;
}