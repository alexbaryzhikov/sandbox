#include <iostream>
#include <type_traits>

template <typename T> struct What { std::string category = "prvalue"; };
template <typename T> struct What<T&> { std::string category = "lvalue"; };
template <typename T> struct What<T&&> { std::string category = "xvalue"; };

template <typename T> concept Prvalue = !std::is_reference_v<T>;
template <typename T> concept Lvalue = std::is_lvalue_reference_v<T>;
template <typename T> concept Xvalue = std::is_rvalue_reference_v<T>;

template <Prvalue T> std::string valueCategory(std::remove_reference_t<T> value) { return "prvalue"; }
template <Lvalue T> std::string valueCategory(std::remove_reference_t<T>& value) { return "lvalue"; }
template <Xvalue T> std::string valueCategory(std::remove_reference_t<T>&& value) { return "xvalue"; }

//std::string overload(int value) { return "value"; }
std::string overload(int& value) { return "lvalue reference"; }
std::string overload(const int& value) { return "lvalue reference to const"; }
std::string overload(int&& value) { return "rvalue reference"; }

template<typename T> void g(T&& t) { std::cout << __PRETTY_FUNCTION__ << '\n'; }
template<typename T> void f(T&& t) { std::cout << __PRETTY_FUNCTION__ << " -> "; g(std::forward<T>(t)); }

int main() {
    int x = 1;
    int& rx = x;
    const int& rcx = x;
    int&& rrx = std::move(x);

    std::cout << "What(x) : " << What<decltype((x))>().category << '\n';
    std::cout << "What(rx) : " << What<decltype((rx))>().category << '\n';
    std::cout << "What(rcx) : " << What<decltype((rcx))>().category << '\n';
    std::cout << "What(rrx) : " << What<decltype((rrx))>().category << '\n';
    std::cout << "What(1) : " << What<decltype((1))>().category << '\n';
    std::cout << "What(std::move(x)) : " << What<decltype((std::move(x)))>().category << '\n';
    std::cout << '\n';
    
    std::cout << "valueCategory(x) : " << valueCategory<decltype((x))>(x) << '\n';
    std::cout << "valueCategory(rx) : " << valueCategory<decltype((rx))>(rx) << '\n';
    std::cout << "valueCategory(rcx) : " << valueCategory<decltype((rcx))>(rcx) << '\n';
    std::cout << "valueCategory(rrx) : " << valueCategory<decltype((rrx))>(rrx) << '\n';
    std::cout << "valueCategory(1) : " << valueCategory<decltype((1))>(1) << '\n';
    std::cout << "valueCategory(std::move(x)) : " << valueCategory<decltype((std::move(x)))>(std::move(x)) << '\n';
    std::cout << '\n';

    std::cout << "overload(x) : " << overload(x) << '\n';
    std::cout << "overload(rx) : " << overload(rx) << '\n';
    std::cout << "overload(rcx) : " << overload(rcx) << '\n';
    std::cout << "overload(rrx) : " << overload(rrx) << '\n';
    std::cout << "overload(1) : " << overload(1) << '\n';
    std::cout << "overload(std::move(x)) : " << overload(std::move(x)) << '\n';
    std::cout << '\n';

    f(x);
    f(rx);
    f(rcx);
    f(rrx);
    f(1);
    f(std::move(x));
}
