/**
 *    Author: Saksham Rathi
 *    Created: Sun Aug 17 14:49:22 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int ao = 0, ae = 0, bo = 0, be = 0;
    for (int i = 0 ; i < n ; i ++) {
        if (i % 2) {
            if (a[i] == '1') ao ++;
            if (b[i] == '0') bo ++;
        }
        else {
            if (a[i] == '1') ae ++;
            if (b[i] == '0') be ++;
        }
    }
    if (ao > be || ae > bo) cout << "NO\n";
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
