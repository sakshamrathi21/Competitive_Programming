/**
 *    Author: Saksham Rathi
 *    Created: Fri Aug 29 11:47:01 IST 2025
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
    map<int, vector<int>> vali;
    vector<int> dp(n + 1, 0);
    for (int i = 0 ; i < n ; i ++) {
        dp[i + 1] = dp[i];
        if (a[i] == 1) dp[i+1] = dp[i] + 1;
        else if (vali[a[i]].size() >= a[i] - 1) {
            // cout << " hello " << endl;
            int index = vali[a[i]][vali[a[i]].size() - a[i] + 1];
            // cout << index << endl;
            dp[i + 1] = max(dp[i + 1], a[i] + dp[index]);
        }
        vali[a[i]].push_back(i);
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
