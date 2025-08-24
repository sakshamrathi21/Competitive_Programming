/**
 *    Author: Saksham Rathi
 *    Created: Sun Aug 24 21:02:07 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<int> g(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> g[i];
    }
    sort(g.begin(), g.end());
    int gm = 0;
    for (int i = n - 1 ; i >= 0 ; i -= 2) gm += g[i];
    cout << gm << "\n";
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
