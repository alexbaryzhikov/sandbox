#include <iostream>

void function() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

struct Functor {
    void operator()() const {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

template<typename F>
void call(F f) {
    std::cout << __PRETTY_FUNCTION__ << " -> ";
    f();
}

int main() {
    call(function);
    call(Functor());
    call([]{ std::cout << __PRETTY_FUNCTION__ << std::endl; });
    return 0;
}
