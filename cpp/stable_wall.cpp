/*
1)
ZOAAMM
ZOAOMM
ZOOOOM
ZZZZOM

result: ZOAM

2)
XXOO
XFFO
XFXO
XXXO

result: -1

3)
XXX
XPX
XXX
XJX
XXX

result: -1

4)
AAABBCCDDE
AABBCCDDEE
AABBCCDDEE

result: EDCBA
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool is_supported(vector<string>& wall, set<char>& pieces, char c) {
  for (int i = 0; i < wall.size() - 1; i++) {
    for (int j = 0; j < wall[0].size(); j++) {
      if (wall[i][j] == c) {
        char _c = wall[i + 1][j];
        if (_c != c && pieces.count(_c)) return false;
      }
    }
  }
  return true;
}

string dfs(vector<string>& wall, set<char>& pieces) {
  for (auto it = pieces.begin(); it != pieces.end(); it++) {
    char c = *it;
    if (is_supported(wall, pieces, c)) {
      if (pieces.size() == 1) return string{c};
      pieces.erase(it);
      string result = dfs(wall, pieces);
      if (!result.empty()) {
        result += c;
        return result;
      }
      it = pieces.insert(c).first;
    }
  }
  return string();
}

int main() {
  vector<string> wall;
  set<char> pieces;
  for (string s; cin >> s;) {
    pieces.insert(s.begin(), s.end());
    wall.push_back(move(s));
  }
  auto result = dfs(wall, pieces);
  if (result.empty()) {
    cout << "-1";
  } else {
    reverse(result.begin(), result.end());
    cout << result;
  }
}