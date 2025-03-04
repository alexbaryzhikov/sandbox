#include <iostream>

template<typename T>
std::remove_reference_t<T>&& mymove(T&& t) {
    std::cout << __PRETTY_FUNCTION__ << '\n';
    using U = std::remove_reference_t<T>;
    return static_cast<U&&>(t);
}

template <typename T>
T&& myforward(std::remove_reference_t<T>& t) {
    std::cout << __PRETTY_FUNCTION__ << '\n';
    return static_cast<T&&>(t);
}

template <typename T>
T&& myforward(std::remove_reference_t<T>&& t) {
    std::cout << __PRETTY_FUNCTION__ << '\n';
    static_assert(!std::is_lvalue_reference<T>::value, "cannot forward an rvalue as an lvalue");
    return static_cast<T&&>(t);
}

struct Foo {
    Foo() {}
    Foo(const Foo& o) { std::cout << "Foo is copied\n"; }
    Foo& operator=(const Foo& o) { std::cout << "Foo is copied\n"; return *this; }
};

void f(Foo& t) { std::cout << __PRETTY_FUNCTION__ << '\n'; }
void f(Foo&& t) { std::cout << __PRETTY_FUNCTION__ << '\n'; }

int main() {
    Foo foo;
    f(mymove(Foo()));
    f(mymove(foo));
    f(mymove(std::move(foo)));
    f(myforward<Foo>(Foo()));
    f(myforward<Foo&>(foo));
    f(myforward<Foo&&>(std::move(foo)));
}
