#include <chrono>
#include <iostream>

using namespace std;

int main() {
  using chrono::duration_cast;
  using chrono::high_resolution_clock;
  using chrono::microseconds;

  auto t0 = high_resolution_clock::now();
  cout << "hello\n";
  auto t1 = high_resolution_clock::now();
  cout << duration_cast<microseconds>(t1 - t0).count() << "us";
}