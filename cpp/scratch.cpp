#include <iostream>
#include <ranges>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    
    auto evens = v | std::views::filter([](int x){ return x % 2 == 0; });

    for (int x : evens) {
        std::cout << x << ' ';
    }

    std::cout << '\n';
}