// 24_Builder2.cpp
#include <iostream>
#include <string>
using namespace std;

#if 0
class User {
    // 필수적
    string name;
    int age;

    // 선택적
    string address;
    string school;

public:
    User(const string& name, int age) { }
    User(const string& name, int age, const string& address) { }
    User(const string& name, int age, const string& address, const string& school) { }
};

int main()
{
    User user { "Tom", 42, "Seoul", "Suwon" };
}
#endif

class User {
    // 필수적
    string name;
    int age;

    // 선택적
    string address;
    string school;

    User(const string& n, int a, const string& addr, const string& s)
        : name { n }
        , age { a }
        , address { addr }
        , school { s }
    {
    }

public:
    class Builder {
        string name;
        int age;
        string address;
        string school;

    public:
        Builder(const string& n, int a)
            : name { n }
            , age { a }
        {
        }

        Builder& SetAddress(const string& s)
        {
            address = s;
            return *this;
        }
        Builder& SetSchool(const string& s)
        {
            school = s;
            return *this;
        }

        User Build()
        {
            return User { name, age, address, school };
        }
    };
};

int main()
{
    // User user { "Tom", 42, "Seoul", "Suwon" };

    // 빌더: 생성자의 인자가 많을 경우, 빌더를 고려하라.
    User user = User::Builder { "Tom", 42 }
                    .SetAddress("Suwon")
                    .SetSchool("Seoul")
                    .Build();
}