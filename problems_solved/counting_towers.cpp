/**
 *    Author: Saksham Rathi
 *    Created: Wed Jul 16 21:16:42 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vii dp(1e6+10, vector<int>(2));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2 ; i < 1e6+10 ; i ++) {
        dp[i][0] = 4*dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0] + 2*dp[i-1][1];
        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
    }
    while (t--) {
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1])%MOD << "\n";
    }
}
