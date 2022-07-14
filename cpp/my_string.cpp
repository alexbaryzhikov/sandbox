#include <cstdio>
#include <cstring>
#include <utility>

struct String {
    char* str;
    int size;
    String();
    String(const char*, int);
    String(const String&);
    String(String&&);
    ~String();
    String& operator=(const String&);
    String& operator=(String&&);
};

String::String() {
    str = new char[1]{'\0'};
    size = 0;
}

String::String(const char* _str, int _size) {
    str = new char[_size];
    memcpy(str, _str, sizeof(char) * _size);
    size = _size;
}

String::String(const String& other) : String(other.str, other.size) {}

String::String(String&& other) {
    str = other.str;
    size = other.size;
    other.str = new char[1]{'\0'};
    other.size = 0;
}

String::~String() { delete[] str; }

String& String::operator=(const String& other) {
    if (&other != this) {
        delete[] str;
        str = new char[other.size];
        memcpy(str, other.str, sizeof(char) * other.size);
        size = other.size;
    }
    return *this;
}

String& String::operator=(String&& other) {
    if (&other != this) {
        delete[] str;
        str = other.str;
        size = other.size;
        other.str = new char[1]{'\0'};
        other.size = 0;
    }
    return *this;
}

int main() {
    String a("hello", 6);
    {
        String b(a);
        b.str[0] = 'H';
        printf("b=%s\n", b.str);
    }
    printf("a=%s\n", a.str);
}
