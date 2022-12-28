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
    int prime_index;
    std::cout << "Enter prime number index: ";
    std::cin >> prime_index;
    for (int i = 1; i < prime_index; ++i) {
        ++it;
    }
    std::cout << "Prime number #" << prime_index << " is " << *it << std::endl;
    return 0;
}
