#include <iostream>
#include <vector>
#include <limits>

int main() {
    int a = std::numeric_limits<int>().min();
    std::cout << a << std::endl;
    std::cout << -a << std::endl;
}
