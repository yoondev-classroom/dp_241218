// 19_Flyweight.cpp
#include <iostream>
#include <string>
using namespace std;

#include <unistd.h>

// 속성이 동일한 객체가 다수 생성되면, 하나의 객체를 공유해서 사용하자.
// => Flyweight Pattern
// 2) 정적 팩토리 메소드
//  : new를 통해서 객체를 생성하는 것이 아니라, 정적 팩토리 메소드를 통해 객체를 생성하는
//    방법을 제공하는 것이 좋습니다.
//   1) 객체 생성의 정책을 유연하게 변경할 수 있습니다.
//   2) 가독성

#include <map>

class Image {
    string url;
    map<string, Image*> cache;

    Image(const string& s)
        : url { s }
    {
        cout << "Downloading image from " << url << endl;
        sleep(3);
    }

public:
    static Image* Create(const string& url)
    {
        // return new Image { url };
        if (cache[url] == nullptr) {
            return new Image { url };
        }

        return cache[url];
    }

    void Draw() const { cout << "Draw image: " << url << endl; }
};

int main()
{
    Image* img1 = Image::Create("https://a.com/a.png");
    img1->Draw();

    Image* img2 = Image::Create("https://a.com/a.png");
    img2->Draw();
}

class User {
public:
    // 객체를 생성하는 다양한 방법을 제공할 때
    // 1) 생성자 오버로딩
    User(const string& name) { }
    User(int id) { }

public:
    static User* CreateWithName(const string& name) { }
    static User* CreateWithId(int id) { }
};

// User* p = new User("Tom");
// User* p = new User(42);

// User* p = User::CreateWithName("Tom");
// User* p = User::CreateWithId(42);