/**
 *    Author: Saksham Rathi
 *    Created: Sat Jun 22 11:08:23 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i ++) {cin >> a[i]; a[i]%=m;}
    vector<bool> curr(m, false);
    vector<bool> prev(m, false);
    for (int i = 0 ; i < n ; i ++) {
        // cout << " hello " << i << dp[0] << dp[1] << dp[2] << dp[3] << dp[4] << endl;
        if (curr[0]) break;
        for (int j = 0 ; j < m ; j ++) {
            if (prev[j]) curr[(j+a[i])%m] = true;
        }
        curr[a[i]] = true;
        prev = curr;
    }
    if (curr[0]) cout << "YES\n";
    else cout << "NO\n";
}
