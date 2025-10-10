/**
 *    Author: Saksham Rathi
 *    Created: Fri Oct 10 22:45:56 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int x, y, z;
    cin >> x >> y >> z;
    vector<int> a(35, 0);
    for (int i = 0 ; i < 35 ; i ++) {
        int cnt = ((x & (1 << i)) > 0) + ((y & (1 << i)) > 0) + ((z & (1 << i)) > 0);
        if (cnt == 2) {cout << "NO\n"; return;}
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
