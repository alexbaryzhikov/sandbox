#include <iostream>
#include <string>
#include <tuple>

template <typename T>
struct template_args;

template <template <typename...> typename T, typename... Args>
struct template_args<T<Args...>> {
    using type = std::tuple<Args...>;
};

template <typename T>
using template_args_t = typename template_args<T>::type;

template <typename T>
struct paramentrized {};

int main() {
    using args = template_args_t<paramentrized<std::string>>;
    std::tuple_element_t<0, args> s{"hello"};
    std::cout << s << std::endl;
}