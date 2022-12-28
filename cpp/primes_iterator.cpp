#include <iostream>
#include <unordered_map>
#include <vector>

class PrimeIterator {
   private:
    std::unordered_map<long, std::vector<long>> D = {{4, {2}}};
    int q = 2;

   public:
    int operator*() { return q; }

    PrimeIterator& operator++() {
        while (D.find(++q) != D.end()) {
            for (int p : D[q]) {
                D[p + q].push_back(p);
            }
            D.erase(q);
        }
        D[q * q] = {q};
        return *this;
    }
};

int main() {
    PrimeIterator it;
    for (int i = 0; i < 100; ++i) {
        std::cout << *it << ' ';
        ++it;
    }
    std::cout << std::endl;
}
