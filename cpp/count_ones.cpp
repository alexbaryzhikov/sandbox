#include <iostream>

using namespace std;

int countOnes(int i) {
  int out = 0;
  while (i) {
    if (i % 10 == 1) out++;
    i /= 10;
  }
  return out;
}

int main() {
  long long acc = 0;
  for (int i = 0; i <= 1000000000; i++) {
    acc += countOnes(i);
    switch (i) {
      case 0:
      case 10:
      case 100:
      case 1000:
      case 10000:
      case 100000:
      case 1000000:
      case 10000000:
      case 100000000:
      case 1000000000:
        cout << "        {" << i << ", " << acc << "},\n";
    }
  }
}
