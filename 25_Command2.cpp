// 25_Command2.cpp
#include <iostream>
#include <vector>
using namespace std;

// Undo의 기능을 구현하고 싶습니다.
// => 명령을 객체로 캡슐화 : Command Pattern
//  : 객체이기 때문에, 저장도 가능하고, Undo, Redo ...

class Shape {
public:
    virtual ~Shape() { } // !!!

    virtual void Draw() const = 0;
};

class Rect : public Shape {
public:
    void Draw() const override { cout << "Draw Rect" << endl; }
};

class Circle : public Shape {
public:
    void Draw() const override { cout << "Draw Circle" << endl; }
};

struct ICommand {
    virtual ~ICommand() { }

    virtual void Execute() = 0;

    virtual void Undo() { }
    virtual bool CanUndo() { return false; }
};

class AddCommand : public ICommand {
    vector<Shape*>& shapes;

public:
    AddCommand(vector<Shape*>& r)
        : shapes { r }
    {
    }

    void Execute() override { shapes.push_back(CreateShape()); }
    // Factory Method Pattern
    //  : Template Method Pattern의 모양인데(변하는 것을 가상함수로 분리)
    //    자식이 재정의하는 것이 알고리즘(정책)이 아니라, 객체 생성일 경우

    bool CanUndo() override { return true; }

    void Undo() override
    {
        Shape* p = shapes.back();
        delete p;

        shapes.pop_back(); // 요소 제거
    }

protected:
    virtual Shape* CreateShape() = 0;
};

class AddRectCommand : public AddCommand {
public:
    AddRectCommand(vector<Shape*>& r)
        : AddCommand { r }
    {
    }

protected:
    Shape* CreateShape() override { return new Rect; }
};

class AddCircleCommand : public AddCommand {
public:
    AddCircleCommand(vector<Shape*>& r)
        : AddCommand { r }
    {
    }

protected:
    Shape* CreateShape() override { return new Circle; }
};

class DrawCommand : public ICommand {
    vector<Shape*>& shapes;

public:
    DrawCommand(vector<Shape*>& r)
        : shapes { r }
    {
    }

    void Execute() override
    {
        for (auto e : shapes) {
            e->Draw();
        }
    }
};

#include <stack>

int main()
{
    vector<Shape*> shapes;
    stack<ICommand*> undo;

    ICommand* pCommand = nullptr;
    while (1) {
        pCommand = nullptr;
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            pCommand = new AddRectCommand { shapes };
        } else if (cmd == 2) {
            pCommand = new AddCircleCommand { shapes };
        } else if (cmd == 9) {
            pCommand = new DrawCommand { shapes };
        }

        else if (cmd == 0) {
            ICommand* undoCommand = undo.top();
            undo.pop();

            undoCommand->Undo();
        }

        if (pCommand) {
            pCommand->Execute();

            if (pCommand->CanUndo()) {
                undo.push(pCommand);
            }
        }
    }
}