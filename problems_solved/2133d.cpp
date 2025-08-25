/**
 *    Author: Saksham Rathi
 *    Created: Mon Aug 25 15:57:21 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i + 1];
    }
    vector<int> dp(n + 1, 0);
    dp[1] = a[1];
    for (int i = 2 ; i <= n ; i ++) {
        dp[i] = min(dp[i-1] + a[i] - 1, dp[i - 2] + max(0ll, a[i] - (i - 1)) + a[i-1]);
    }
    cout << dp[n] << "\n";
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
