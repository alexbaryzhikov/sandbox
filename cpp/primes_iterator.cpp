#include <iostream>
#include <unordered_map>
#include <vector>

class PrimeIterator {
   private:
    std::unordered_map<long, std::vector<long>> composites = {{4, {2}}};
    int q = 2;

   public:
    int operator*() { return q; }

    PrimeIterator operator++(int) {
        PrimeIterator tmp = *this;
        ++*this;
        return tmp;
    }

    PrimeIterator& operator++() {
        while (composites.find(++q) != composites.end()) {
            for (int p : composites[q]) {
                composites[p + q].push_back(p);
            }
            composites.erase(q);
        }
        composites[q * q] = {q};
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
