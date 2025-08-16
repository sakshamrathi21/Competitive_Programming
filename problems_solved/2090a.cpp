/**
 *    Author: Saksham Rathi
 *    Created: Sat Aug 16 23:31:38 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int x, y, a;
    cin >> x >> y >> a;
    a = a % (x + y);
    if (a >= x) cout << "YES\n";
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
