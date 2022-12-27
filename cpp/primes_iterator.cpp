#include <iostream>
#include <unordered_map>
#include <vector>

class PrimeIterator {
   private:
    std::unordered_map<int, std::vector<int>> D;
    int q;

   public:
    PrimeIterator() : D{{4, {2}}}, q(2) {}

    int operator*() { return q; }

    PrimeIterator& operator++() {
        while (true) {
            if (D.find(++q) == D.end()) {
                D[q * q] = {q};
                break;
            } else {
                for (int p : D[q]) {
                    D[p + q].push_back(p);
                }
                D.erase(q);
            }
        }
        return *this;
    }
};

int main() {
    PrimeIterator it;
    for (int i = 0; i < 100; ++i) {
        std::cout << *it << ' ';
        ++it;
    }
    return 0;
}
