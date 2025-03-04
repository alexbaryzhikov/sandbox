#include <iostream>
#include <functional>

template <typename... Types>
struct OverloadCall : Types... {
    using Types::operator()...;
};

template <typename... Types>
OverloadCall(Types...) -> OverloadCall<Types...>;

template <typename... Types>
struct OverloadSize : Types... {
    using Types::size...;
};

template <typename... Types>
OverloadSize(Types...) -> OverloadSize<Types...>;

int main() {
    auto o = OverloadCall {
        [](int x) { std::cout << "int: " << x << '\n'; },
        [](double x) { std::cout << "double: " << x << '\n'; },
        [](const std::string& x) { std::cout << "string: " << x << '\n'; },
    };
    o(1);
    o(1.0);
    o("hello");

    struct A { constexpr size_t size() const { return 1; } };
    struct B { constexpr size_t size() const { return 2; } };
    struct C { constexpr size_t size() const { return 3; } };

    auto s = OverloadSize{std::string("abcde"), std::vector<int>{1, 2, 3}};
    std::cout << "string size: " << static_cast<std::string&>(s).size() << '\n';
    std::cout << "vector size: " << static_cast<std::vector<int>&>(s).size() << '\n';
}