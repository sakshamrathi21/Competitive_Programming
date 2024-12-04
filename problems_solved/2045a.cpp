#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using i128 = __int128;
using u128 = unsigned __int128;
template <typename T>
void chkmax(T &x, const T &y) {
  x = max(x, y);
}
template <typename T>
void chkmin(T &x, const T &y) {
  x = min(x, y);
}
constexpr int MAXN = 5010;
int cnt[26];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string str;
  cin >> str;
  for (auto c : str) ++cnt[c - 'A'];
  int vow = 0, y = cnt['Y' - 'A'], n = cnt['N' - 'A'], g = cnt['G' - 'A'];
  for (auto c : {'A', 'E', 'I', 'O', 'U'}) vow += cnt[c - 'A'];
  int rem = str.size() - vow - y - n - g;
  int ans = 0;
  for (int i = 0; i <= min(n, g); ++i) {
    int rvow = vow, ry = y,  rrem = n + g - i + rem;
    for (int len = 1; len <= rvow + ry; ++len) {
      if (ry >= max(len * 2 - rrem, 0) + max(len - rvow, 0))
        chkmax(ans, len * 3 + min(i, len * 2));
    }
  }
  cout << ans << "\n";
  return 0;
}