#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m;
vector<int> coins;

int sum(vector<int> &v) {
  int result{0};
  for (int i : v) {
    result += i;
  }
  return result;
}

int explore(int k, vector<int> &nums, int pos, int part_sum) {
  bool done{true};

  if (k == 0) {
    if (part_sum == n) {
      return sum(nums);
    }
    if (part_sum < n) {
      done = false;
    }
  } else if (k == 1) {
    for (size_t i = pos; i < coins.size(); i++) {
      if (part_sum + coins[i] == n) {
        return sum(nums) + 1;
      }
      if (part_sum + coins[i] < n) {
        done = false;
      }
    }
  } else {
    int rest_num = (coins.size() - pos - 1) * 2;
    if (k - 2 <= rest_num) {
      nums[pos] = 2;
      int result = explore(k - 2, nums, pos + 1, part_sum + coins[pos] * 2);
      if (result > 0) {
        return result;
      }
      if (result == 0) {
        done = false;
      }
      if (k - 1 <= rest_num) {
        nums[pos] = 1;
        int result = explore(k - 1, nums, pos + 1, part_sum + coins[pos]);
        if (result > 0) {
          return result;
        }
        if (result == 0) {
          done = false;
        }
        nums[pos] = 0;
        if (k <= rest_num) {
          int result = explore(k, nums, pos + 1, part_sum);
          if (result > 0) {
            return result;
          }
          if (result == 0) {
            done = false;
          }
        }
      } else {
        nums[pos] = 0;
      }
    }
  }

  return done ? -1 : 0;
}

int explore(int k) {
  vector<int> nums;
  for (int i = 0; i < m; i++) {
    nums.push_back(0);
  }
  return explore(k, nums, 0, 0);
}

void solve() {
  if (sum(coins) * 2 < n) {
    cout << -1 << endl;
    return;
  }

  if (sum(coins) * 2 == n) {
    cout << coins.size() * 2 << endl;
    return;
  }

  for (int i = 1; i <= m * 2; i++) {
    int result = explore(i);
    if (result > 0) {
      cout << result << endl;
      return;
    }
    if (result == -1) {
      break;
    }
  }

  cout << 0 << endl;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int c;
    cin >> c;
    coins.push_back(c);
  }

  solve();
}
