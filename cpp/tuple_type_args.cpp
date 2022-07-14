#include <iostream>
#include <string>
#include <tuple>

template <size_t I, typename T>
struct tuple_type_arg;

template <size_t I, typename Head, typename... Tail>
struct tuple_type_arg<I, std::tuple<Head, Tail...>> : tuple_type_arg<I - 1, std::tuple<Tail...>> {};

template <typename Head, typename... Tail>
struct tuple_type_arg<0, std::tuple<Head, Tail...>> {
    using type = Head;
};

template <size_t I>
struct tuple_type_arg<I, std::tuple<>> {
    static_assert(I < std::tuple_size<std::tuple<>>::value, "Tuple index is out of range.");
};

template <size_t I, typename T>
using tuple_type_arg_t = typename tuple_type_arg<I, T>::type;

template <typename... Ts>
struct type_list {
    template <size_t I>
    using type = tuple_type_arg_t<I, std::tuple<Ts...>>;
};

int main() {
    using types = type_list<int, bool, std::string>;
    types::type<0> a{44};
    types::type<1> b{true};
    types::type<2> c{"viva"};
    std::cout << std::boolalpha << a << ' ' << b << ' ' << c << std::endl;

    using types2 = std::tuple<int, std::string>;
    tuple_type_arg_t<0, types2> d{32};
    std::cout << d << std::endl;

    using types3 = std::tuple<int, std::string>;
    std::tuple_element_t<1, types3> e{"hello"};
    std::cout << e << std::endl;
}