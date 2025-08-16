/**
 *    Author: Saksham Rathi
 *    Created: Sat Aug 16 23:36:58 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    for (int i = n - 1 ; i >= 0 ; i --) {
        for (int j = m - 1 ; j >= 0 ; j --) {
            if (a[i][j] == '0') continue;
            if (i == 0 || j == 0) continue;
            if (a[i-1][j] == '1' || a[i][j-1] == '1') continue;
            cout << "NO\n";
            return;
        }
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
