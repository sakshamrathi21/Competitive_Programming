/**
 *    Author: Saksham Rathi
 *    Created: Fri Aug  8 10:24:21 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> all;
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
        if (a[i] != -1) all.insert(a[i]);
    }
    if (all.find(0) != all.end() || all.size() >= 2) cout << "NO\n";
    else cout << "YES\n"; 
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
