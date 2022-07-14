#include <iostream>
#include <vector>

template <template <typename...> typename T, typename V, typename... Args>
V& get_by_index(const T<V, Args...>& t, int i) {
    return t[i];
}

int main() {
    std::vector<int> v = {1, 2, 3};
    int x = get_by_index(v, 1);
    std::cout << "x=" << x << '\n';
}
