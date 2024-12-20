// 28_Mediator.cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// UI - RadioButton
// > 당신의 성별은 무엇입니까?

// ------------------------ RadioGroup
//  [ ] 남자 : RadioButton
//  [*] 여자 : RadioButton
//  [ ] 비밀 : RadioButton
//  [ ] 둘다아님: RadioButton

// 중재자의 인터페이스
class RadioButton;
class IMediator {
public:
    virtual ~IMediator() { }

    virtual void OnUpdate(RadioButton* sender) = 0;
};

class RadioButton {
    string title;
    bool isChecked;

    IMediator* pMediator = nullptr;

public:
    void SetMediator(IMediator* p) { pMediator = p; }

    RadioButton(const string& s)
        : title { s }
        , isChecked { false }
    {
    }

    void SetChecked(bool b)
    {
        isChecked = b;

        if (isChecked) {
            pMediator->OnUpdate(this);
        }
    }

    void Display()
    {
        cout << title << ": " << isChecked << endl;
    }
};

class RadioGroup : public IMediator {
    vector<RadioButton*> v;

public:
    void AddRadioButton(RadioButton* p)
    {
        v.push_back(p);
        p->SetMediator(this); // !!
    }

    void OnUpdate(RadioButton* sender) override
    {
        // ...
        for (auto e : v) {
            if (e != sender) {
                e->SetChecked(false);
            }
        }
    }
};

int main()
{
    RadioButton b1 { "남자" };
    RadioButton b2 { "여자" };
    RadioButton b3 { "모름" };
    RadioButton b4 { "비밀" };

    RadioGroup m;
    m.AddRadioButton(&b1);
    m.AddRadioButton(&b2);
    m.AddRadioButton(&b3);
    m.AddRadioButton(&b4);

    b1.SetChecked(true);
    b1.Display();
    b2.Display();
    b3.Display();
    b4.Display();
    cout << "-------" << endl;

    b2.SetChecked(true);
    b1.Display();
    b2.Display();
    b3.Display();
    b4.Display();

    cout << "-------" << endl;

    b3.SetChecked(true);
    b1.Display();
    b2.Display();
    b3.Display();
    b4.Display();

    cout << "-------" << endl;

    b4.SetChecked(true);
    b1.Display();
    b2.Display();
    b3.Display();
    b4.Display();
}