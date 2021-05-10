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

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  bool first = true;
  for (auto& elem : v) {
    if (first)
      first = false;
    else
      os << ' ';
    os << elem;
  }
  return os;
}

int value(vector<int>::iterator l, vector<int>::iterator r) {
  int result = 0;
  for (int sign = 1, coef = 1; l < r; l++, sign = -sign, coef++) {
    result += sign * coef * *l;
  }
  return result;
}

int main() {
  vector<int> nums;
  cin >> nums;
  int a, b;
  int result = 0;
  cout << "> ";
  for (char c; cin >> c;) {
    cin >> a >> b;
    switch (c) {
      case 'u':
      case 'U':
        nums[a] = b;
        cout << nums << '\n';
        break;
      case 'q':
      case 'Q':
        int v = value(nums.begin() + a, nums.begin() + b);
        result += v;
        cout << v << '/' << result << '\n';
        break;
    }
    cout << "> ";
  }
}