#include <cstdio>
#include <vector>

struct Mod {
    int divisor;
    Mod(int d) : divisor(d) {}
    auto get() {
        return [d = divisor](int x) { return x % d; };
    }
};

int main() {
    auto f2 = Mod(2).get();
    auto f5 = Mod(5).get();
    int a = f2(3);
    int b = f5(7);
    printf("a=%d b=%d", a, b);
}
