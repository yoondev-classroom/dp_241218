// 19_Flyweight.cpp
#include <iostream>
#include <string>
#include <map>
using namespace std;

#include <unistd.h>

// 속성이 동일한 객체가 다수 생성되면, 하나의 객체를 공유해서 사용하자.
// => Flyweight Pattern
// 1) Factory(객체를 생성하는 역활) class

class Image {
    string url;

    // 생성자를 private 두면 외부에서 접근이 불가능합니다.
    Image(const string& s)
        : url { s }
    {
        cout << "Downloading image from " << url << endl;
        sleep(3);
    }

    friend class ImageFactory;

public:
    void Draw() const { cout << "Draw image: " << url << endl; }
};

// Image 객체를 생성하는 역활
// : Factory - 객체의 생성을 한곳에서 중앙집중적으로 관리하는 것이 목적입니다.
class ImageFactory {
    map<string, Image*> image_map;

public:
    Image* CreateImage(const string& url)
    {
        if (image_map[url] == nullptr) {
            image_map[url] = new Image { url };
        }

        return image_map[url];
    }
};

int main()
{
    ImageFactory factory;

    Image* img1 = factory.CreateImage("https://a.com/a.png");
    img1->Draw();

    Image* img2 = factory.CreateImage("https://a.com/a.png");
    img2->Draw();

    // Image* p = new Image { "https://a.com/a.png" };
    // p->Draw();
}
