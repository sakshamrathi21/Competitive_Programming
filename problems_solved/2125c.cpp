/**
 *    Author: Saksham Rathi
 *    Created: Sat Aug  9 08:12:44 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

int all(int r) {
    int count = r;
    count -= (r/2 + r/3 + r/5 + r/7);
    count += (r/6 + r/10 + r/14 + r/15 + r/21 + r/35);
    count -= (r/30 + r/70 + r/42 + r/105);
    count += (r/210);
    return count;
}

void solve() {
    int l, r;
    cin >> l >> r;
    cout << all(r) - all(l-1) << "\n";
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
