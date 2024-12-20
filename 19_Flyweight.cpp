// 19_Flyweight.cpp
#include <iostream>
#include <string>
using namespace std;

#include <unistd.h>

// 속성이 동일한 객체가 다수 생성되면, 하나의 객체를 공유해서 사용하자.
// => Flyweight Pattern

class Image {
    string url;

public:
    Image(const string& s)
        : url { s }
    {
        cout << "Downloading image from " << url << endl;
        sleep(3);
    }

    void Draw() const { cout << "Draw image: " << url << endl; }
};

int main()
{
    Image* img1 = new Image("https://a.com/a.png");
    img1->Draw();

    Image* img2 = new Image("https://a.com/a.png");
    img2->Draw();
}