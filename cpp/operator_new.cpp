#include <iostream>
#include <new>

struct A {
    int a = 1;
    void* operator new(size_t sz) {
        std::cout << "Allocating A\n";
        if (void* p = malloc(sz)) {
            return p;
        }
        throw std::bad_alloc();
    }
};

int main() {
    A* a = new A;
    std::cout << a->a << '\n';
    delete a;
}