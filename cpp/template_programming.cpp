#include <iostream>
#include <vector>

template <typename T>
struct Is_const : public std::false_type {};

template <typename T>
struct Is_const<const T> : public std::true_type {};

template <typename A, typename B>
struct Is_equal : public std::false_type {};

template <typename T>
struct Is_equal<T, T> : public std::true_type {};

template <typename T>
struct Rank {
    static constexpr int value = 0;
};

template <typename T, int N>
struct Rank<T[N]> {
    static constexpr int value = Rank<T>::value + 1;
};

int main() {
    const int x = 1;
    int y = 2;
    std::cout << std::boolalpha;
    std::cout << "Is_const(x)=" << Is_const<decltype(x)>::value << '\n';
    std::cout << "Is_const(y)=" << Is_const<decltype(y)>::value << '\n';
    std::cout << "Is_equal(x, x)=" << Is_equal<decltype(x), decltype(x)>::value << '\n';
    std::cout << "Is_equal(x, y)=" << Is_equal<decltype(x), decltype(y)>::value << '\n';

    int a[2][3][4];
    std::cout << "Rank(a)=" << Rank<decltype(a)>::value << '\n';
}
