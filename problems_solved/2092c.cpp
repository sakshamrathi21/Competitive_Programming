/**
 *    Author: Saksham Rathi
 *    Created: Sun Aug 17 20:55:41 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int no = 0;
    int sum = 0;
    int ma = -1;
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
        if (a[i]%2 == 1) no++;
        sum += a[i];
        ma = max(ma, a[i]);
    }
    if (no == 0 || no == n) cout << ma << "\n";
    else cout << sum - no + 1 << "\n";
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
