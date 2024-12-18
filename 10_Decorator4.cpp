// 10_Decorator4.cpp
#include <string>
#include <iostream>
using namespace std;

// * Java / C# 등의 언어에서 데코레이터 패턴을 통해 IO가 구현되어 있습니다.
class Stream {
public:
    virtual ~Stream() { }

    virtual void Write(const std::string& s) = 0;
};

class FileStream : public Stream {
    FILE* file;

public:
    FileStream(const char* s, const char* mode = "wt")
    {
        file = fopen(s, mode);
    }

    ~FileStream()
    {
        fclose(file);
    }

    void Write(const string& s) override
    {
        cout << s << " 쓰기" << endl;
    }
};

class ZipStream : public Stream {
    Stream* stream;

public:
    ZipStream(Stream* p)
        : stream { p }
    {
    }

    void Write(const string& s) override
    {
        std::string data = "압축: " + s;
        stream->Write(data); // 원래의 기능을 수행합니다.
    }
};

int main()
{
    FileStream fs("a.txt");
    // fs.Write("Hello");

    ZipStream zs(&fs);
    zs.Write("Hello");
}

// FileOutputStream fos = new FileOutputStream("a.txt");
// BufferedOutputStream oos = new BufferedOutputStream(fos);
// ZipOutputStream zos = new ZipOutputStream(oos);

// zos.write(...);
// => 자바에서는 성능의 이슈가 문제가 되어서, 새로운 IO 방식이 도입되었습니다.(NIO)