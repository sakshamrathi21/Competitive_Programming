/**
 *    Author: Saksham Rathi
 *    Created: Fri Aug  8 10:44:48 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    x--;
    int l = -1, r = MOD;
    for (int i = 0 ; i < x ; i ++) {
        if (s[i] == '#') l = max(l, i);
    }
    for (int i = x + 1 ; i < n ; i ++ ) {
        if (s[i] == '#') r = min(r, i);
    }
    if (l == -1 && r == MOD) {cout << "1\n"; return;}
    cout << max(min(x + 1, n - r + 1), min(l + 2,  n - x)) << "\n";
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
