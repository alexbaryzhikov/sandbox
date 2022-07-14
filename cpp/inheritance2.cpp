#include <iostream>

struct A {
    int a;
    A(int a) : a(a) {}
    void f() { std::cout << "A.f()\n"; }
};

struct B : public A {
    int b;
    B(int a, int b) : A(a), b(b) {}
    void f() { std::cout << "B.f()\n"; }
};

int main() {
    A a(1);
    B b(2, 3);
    A& aref = b;
    
    a.f();
    b.f();
    aref.f();
    
    static_cast<B&>(aref).f();
    static_cast<B&>(a).f();
    std::cout << "a.b=" << static_cast<B&>(a).b << '\n';

    int c = 1;
    reinterpret_cast<A&>(c).f();
}
