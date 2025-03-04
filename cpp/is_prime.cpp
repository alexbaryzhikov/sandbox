#include <iostream>

template<uint N, uint R = N / 2>
struct square_root {
    static constexpr uint value = (R * R <= N && (R + 1) * (R + 1) > N) ? R : square_root<N, (N / R + R) / 2>::value;
};

template<>
struct square_root<0> {
    static constexpr uint value = 0;
};

template<>
struct square_root<1> {
    static constexpr uint value = 1;
};

template<>
struct square_root<2> {
    static constexpr uint value = 1;
};

template<>
struct square_root<3> {
    static constexpr uint value = 1;
};

template<uint N>
constexpr uint square_root_v = square_root<N>::value;

template<uint N, uint D = square_root_v<N>>
struct is_prime {
    static constexpr bool value = N % D && is_prime<N, D - 1>::value;
};

template<>
struct is_prime<0, 0> {
    static constexpr bool value = false;
};

template<>
struct is_prime<1, 1> {
    static constexpr bool value = false;
};

template<uint N>
struct is_prime<N, 1> {
    static constexpr bool value = true;
};

template<uint N>
constexpr bool is_prime_v = is_prime<N>::value;

template<uint N>
constexpr std::vector<uint> primes(std::vector<uint>& result) {
    if constexpr (N) {
        primes<N - 1>(result);
    }
    if constexpr (is_prime_v<N>) {
        result.push_back(N);
    }
    return result;
}

template<uint N>
constexpr std::vector<uint> primes() {
    std::vector<uint> result;
    primes<N>(result);
    return result;
}

int main() {
    for (uint x : primes<100>()) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}
