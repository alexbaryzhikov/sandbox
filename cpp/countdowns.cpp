#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  string buf;
  getline(is, buf);
  stringstream ss{buf};
  for (T t; ss >> t;) v.push_back(move(t));
  return is;
}

int main() {
  vector<int> nums;
  int k;
  cin >> nums >> k;
  int result = 0;
  bool counting = false;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == k) {
      counting = true;
    } else if (counting) {
      if (nums[i] == nums[i - 1] - 1) {
        if (nums[i] == 1) {
          result++;
          counting = false;
        }
      } else {
        counting = false;
      }
    }
  }
  cout << result;
}