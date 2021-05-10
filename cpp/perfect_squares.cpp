/* 
2 2 6
result: 1

30 30 9 1 30
result: 3

4 0 0 16
result: 9
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> nums;
  int sum_neg = 0;
  int sum_pos = 0;
  for (int i; cin >> i;) {
    nums.push_back(i);
    if (i < 0)
      sum_neg -= i;
    else
      sum_pos += i;
  }

  vector<int> t(sum_neg + sum_pos + 1, 0);
  t[sum_neg] = 1;

  int result = 0;
  int sum_cur = 0;
  for (int x : nums) {
    sum_cur += x;
    int i = sum_neg + sum_cur;
    for (int q = 0, j = i; j >= 0; q++, j = i - q * q) result += t[j];
    t[i]++;
  }
  cout << result;
}