#include <functional>
#include <iostream>

int main() {
    std::function<int()> next_num = [n = 0]() mutable { return ++n; };
    for (int i = 0; i < 10; ++i) {
        std::cout << next_num() << ' ';
    }
    std::cout << std::endl;
}