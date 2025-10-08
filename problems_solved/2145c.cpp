/**
 *    Author: Saksham Rathi
 *    Created: Wed Oct  8 12:07:02 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> p(n + 1, 0);
    for (int i = 1 ; i <= n ; i ++) {
        p[i] = p[i - 1] + (s[i - 1] == 'a' ? 1 : -1);
    }
    map<int, int> pos;
    int diff = p[n];
    int min_r = n;
    for (int i = 0 ; i <= n ; i ++) {
        if (pos.find(p[i] - diff) != pos.end()) min_r = min(min_r, i - pos[p[i] - diff]);
        pos[p[i]] = i;
    }
    if (diff == 0) cout << "0\n";
    else cout << (min_r == n ? -1 : min_r) << "\n";
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
