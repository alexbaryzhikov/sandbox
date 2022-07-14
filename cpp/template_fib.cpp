#include <iostream>

template <int N>
struct Fib {
    static constexpr int value = Fib<N - 1>::value + Fib<N - 2>::value;
};

template <>
struct Fib<0> {
    static constexpr int value = 1;
};

template <>
struct Fib<1> {
    static constexpr int value = 1;
};

int main() {
    std::cout << Fib<0>::value << ' ' << Fib<1>::value << ' ' << Fib<2>::value << ' ' << Fib<3>::value << ' '
              << Fib<4>::value << ' ' << Fib<5>::value << '\n';
}