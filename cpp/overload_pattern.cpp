#include <iostream>
#include <functional>

template <typename... Types>
struct Overload : Types... {
    using Types::operator()...;
};

template <typename... Types>
Overload(Types...) -> Overload<Types...>;

int main() {
    auto o = Overload {
        [](int x) { std::cout << "int: " << x << '\n'; },
        [](double x) { std::cout << "double: " << x << '\n'; },
        [](const std::string& x) { std::cout << "string: " << x << '\n'; },
    };
    o(1);
    o(1.0);
    o("hello");
} 