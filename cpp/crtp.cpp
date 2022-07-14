#include <iostream>

template <typename T>
struct A {
    void f() { static_cast<T*>(this)->f(); }
};

struct B : public A<B> {
    void f() { std::cout << "B.f()" << '\n'; }
};

int main() {
    B b;
    A<B>* a = &b;
    a->f();
}