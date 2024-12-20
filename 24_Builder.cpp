// 24_Builder.cpp

#include <iostream>
#include <string>
using namespace std;

// 축구 게임
//  - 나라 선택
//     머리색 / 유니폼 상의 / 유니폼 하의 / 신발

// * 캐릭터를 만드는 공정은 동일하지만,
//   각 공정에 따른 표현이 달라집니다.

using Head = string;
using Uniform = string;
using Sheos = string;

using Player = string;

// * 공통성과 가변성의 분리
// => 변하는 것을 인터페이스 기반의 클래스로 분리하는 설계
// 1) Strategy(행위) => 알고리즘
// 2) State(행위) => 상태에 따른 동작
// 3) Builder(생성) => 동일한 공정, 다른 표현

// 각 플레이어를 만들때 사용할 인터페이스를 정의합니다.
class IPlayerBuilder {
public:
    virtual ~IPlayerBuilder() { }

    virtual void MakeHead() = 0;
    virtual void MakeUniform() = 0;
    virtual void MakeSheos() = 0;

    virtual Player GetResult() = 0;
};

// 모든 플레이어를 만드는 공정은 동일합니다.
// 동일한 공정을 담은 클래스를 Director라고 부릅니다.
class Director {
    IPlayerBuilder* builder;

public:
    void SetBuilder(IPlayerBuilder* p) { builder = p; }

    Player Construct()
    {
        builder->MakeSheos();
        builder->MakeHead();
        builder->MakeUniform();

        return builder->GetResult();
    }
};

// 각 팀 별로 캐릭터를 만드는 빌더를 제공하면 됩니다.
class Korea : public IPlayerBuilder {
    Player c;

public:
    void MakeHead() override
    {
        c += "검은머리";
    }

    void MakeUniform() override
    {
        c += "빨간 유니폼";
    }

    void MakeSheos() override
    {
        c += "아디다스";
    }

    Player GetResult() override
    {
        return c;
    }
};

class America : public IPlayerBuilder {
    Player c;

public:
    void MakeHead() override
    {
        c += "노란머리";
    }

    void MakeUniform() override
    {
        c += "파란 유니폼";
    }

    void MakeSheos() override
    {
        c += "나이키";
    }

    Player GetResult() override
    {
        return c;
    }
};

int main()
{
    America a;
    Korea k;

    Director d;
    d.SetBuilder(&k);
    cout << d.Construct() << endl;

    d.SetBuilder(&a);
    cout << d.Construct() << endl;
}