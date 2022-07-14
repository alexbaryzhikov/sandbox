#include <iostream>
#include <string>

struct A {
    int a = 'a';
    virtual ~A() {};
    std::string f() { return "A.f()"; }
};

struct B : A {
    int b = 'b';
    std::string f() { return "B.f()"; }
};

int main() {
    B* bptr = new B;
    std::cout << bptr << '\n';
    A* aptr = bptr;
    delete aptr;
}