/**
 *    Author: Saksham Rathi
 *    Created: Sun Aug 17 14:42:19 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    int m = 1e10, M = -1;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
        m = min(m, a[i]);
        M = max(M, a[i]);
    }
    cout << M - m << "\n";
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
