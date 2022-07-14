template <typename T>
class Type {
    Type() = delete;
};

int main() {
    int x = 1;
    Type<decltype(++x)> t;
}
