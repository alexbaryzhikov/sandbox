#include <iostream>

struct Foo {
    int id = 0;
    void release() { std::cout << "Foo-" << id << " released" << std::endl; }
};

struct Bar {
    int id = 0;
    void release() { std::cout << "Bar-" << id << " released" << std::endl; }
};

struct Releaser {
    void operator()(auto* ptr) const { ptr->release(); }
};

int main() {
    {
        auto foo = std::shared_ptr<Foo>(new Foo(1), Releaser());
        auto bar = std::shared_ptr<Bar>(new Bar(2), Releaser());
    }
    return 0;
}
