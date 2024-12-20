// 23_AbstractFactory.cpp
#include <iostream>
using namespace std;

struct IButton {
    virtual ~IButton() { }
    virtual void Draw() = 0;
};

struct IEdit {
    virtual ~IEdit() { }
    virtual void Draw() = 0;
};

class WinButton : public IButton {
public:
    void Draw() override { }
};

class WinEdit : public IEdit {
public:
    void Draw() override { }
};

class GTKButton : public IButton {
public:
    void Draw() override { }
};

class GTKEdit : public IEdit {
public:
    void Draw() override { }
};

// 핵심: 공장도 교체 가능해야 합니다.
// => Abstract Factory Pattern
struct IFactory {
    virtual ~IFactory() { }

    virtual IButton* CreateButton() = 0;
    virtual IEdit* CreateEdit() = 0;
};

// 제품군을 생산하는 팩토리 클래스를 도입하였습니다.
class WinFactory : public IFactory {
public:
    IButton* CreateButton() override { return new WinButton; }
    IEdit* CreateEdit() override { return new WinEdit; }
};

class GTKFactory : public IFactory {
public:
    IButton* CreateButton() override { return new GTKButton; }
    IEdit* CreateEdit() override { return new GTKEdit; }
};

int main(int argc, char** argv)
{
    IFactory* factory;

    if (strcmp(argv[1], "gtk") == 0) {
        factory = new GTKFactory;
    } else {
        factory = new WinFactory;
    }
}

#if 0
int main(int argc, char** argv)
{
    IButton* button = nullptr;
    IEdit* edit = nullptr;

    if (strcmp(argv[1], "gtk") == 0) {
        button = new GTKButton;
        edit = new GTKEdit;
    } else {
        button = new WinButton;
        edit = new WinEdit;
    }

    button->Draw();
    edit->Draw();
}
#endif