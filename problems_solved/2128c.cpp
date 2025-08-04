/**
 *    Author: Saksham Rathi
 *    Created: Mon Aug  4 11:18:20 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    set<int> e;
    e.insert(a[0]);
    for (int i = 1 ; i < n ; i ++) {
        if (*e.begin() <= 0.5*a[i]) {cout << "NO\n"; return;}
        e.insert(a[i]);
    }
    cout << "YES\n";
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
