/*
You have coins of m different values, 2 of each.
Find minimum number of coins that sum to n.
Output this number, 0 if not found, or -1 if not enough money.
*/

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

int try_samples(int size, vector<int> &sample, int index, int sample_value) {
  bool done{true};

  if (size == 0) {
    if (sample_value == n) {
      return sum(sample);
    }
    if (sample_value < n) {
      done = false;
    }
  } else if (size == 1) {
    for (size_t i = index; i < coins.size(); i++) {
      if (sample_value + coins[i] == n) {
        return sum(sample) + 1;
      }
      if (sample_value + coins[i] < n) {
        done = false;
      }
    }
  } else {
    int rest_num = (coins.size() - index - 1) * 2;
    if (size - 2 <= rest_num) {
      sample[index] = 2;
      int result = try_samples(size - 2, sample, index + 1, sample_value + coins[index] * 2);
      if (result > 0) {
        return result;
      }
      if (result == 0) {
        done = false;
      }
      if (size - 1 <= rest_num) {
        sample[index] = 1;
        int result = try_samples(size - 1, sample, index + 1, sample_value + coins[index]);
        if (result > 0) {
          return result;
        }
        if (result == 0) {
          done = false;
        }
        sample[index] = 0;
        if (size <= rest_num) {
          int result = try_samples(size, sample, index + 1, sample_value);
          if (result > 0) {
            return result;
          }
          if (result == 0) {
            done = false;
          }
        }
      } else {
        sample[index] = 0;
      }
    }
  }

  return done ? -1 : 0;
}

int try_samples(int size) {
  vector<int> sample;
  for (int i = 0; i < m; i++) {
    sample.push_back(0);
  }
  return try_samples(size, sample, 0, 0);
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

  for (int size = 1; size <= m * 2; size++) {
    int result = try_samples(size);
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
    int coin;
    cin >> coin;
    coins.push_back(coin);
  }

  solve();
}
