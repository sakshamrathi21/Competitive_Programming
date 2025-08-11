/**
 *    Author: Saksham Rathi
 *    Created: Mon Aug 11 08:20:41 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    for (int i = 0 ; i < n ; i ++) cin >> b[i];
    for (int i = 0 ; i < n - 1; i ++) {
        if (a[i] == b[i]) continue;
        if ((a[i] ^ a[i+1]) == b[i]) a[i] = b[i];
    }
    for (int i = n - 2 ; i >= 0 ; i --) {
        if (a[i] == b[i]) continue;
        if ((a[i] ^ a[i+1]) == b[i]) a[i] = b[i];
    }
    for (int i = 0 ; i < n ; i ++) {
        if (a[i] != b[i]) {cout << "NO\n"; return;}
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
