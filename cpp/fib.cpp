#include <expected>
#include <iostream>
#include <string>

auto fib(int64_t n, int64_t max_depth) -> std::expected<int64_t, std::string> {
    if (max_depth == 0) {
        return std::unexpected(std::to_string(n) + " exceeds max_depth");
    }
    if (n <= 2) return 1;
    auto n2 = fib(n - 2, max_depth - 1);
    if (!n2) return n2;
    auto n1 = fib(n - 1, max_depth - 1);
    if (!n1) return n1;
    return *n1 + *n2;
}

int main() {
    auto result = fib(15, 100);
    if (result) {
        std::cout << *result << std::endl;
    } else {
        std::cout << result.error() << std::endl;
    }
}
