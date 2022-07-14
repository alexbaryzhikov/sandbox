#include <iostream>

struct A {
    int a = 0;
    A(int a) : a(a) {}
};

struct B : public A {
    int b = 1;
    B(int a, int b) : A(a), b(b) {}
}; 

struct C : public B {
    int c = 2;
    
    C(int a, int b, int c) : B(a, b), c(c) {}

    int f() {
        B b(10, 11);
        return b.a;
    }
};

int main() {
    A a(1);
    B b(2, 3);
    C c(4, 5, 6);
    std::cout << "a=" << a.a << " b=" << b.b << " c=" << c.c << '\n';
    std::cout << "f()=" << c.f() << '\n';
}
