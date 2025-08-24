/**
 *    Author: Saksham Rathi
 *    Created: Sun Aug 24 20:59:43 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> f;
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
        f[a[i]]++;
    }
    bool found = false;
    for (auto e : f) {
        if (e.second >= 2) found = true;
    }
    if (found) cout << "YES\n";
    else cout << "NO\n";
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
