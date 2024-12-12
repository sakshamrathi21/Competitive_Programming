/**
 *    Author: Saksham Rathi
 *    Created: Thu Dec 12 20:53:01 IST 2024
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
    while (t--) {
        string a, b, c;
        cin >> a >> b >> c;
        int n = a.length(), m = b.length();
        vii dp(n+10, vi(m + 10, MOD));
        dp[0][0] = 0;
        for (int i = 0 ; i < n ; i ++) dp[i+1][0] = dp[i][0] + (a[i] != c[i]);
        for (int i = 0 ; i < m ; i ++) dp[0][i+1] = dp[0][i] + (b[i] != c[i]);
        for (int i = 1 ; i <= n ; i ++) {
            for (int j = 1 ; j <= m ; j ++ ) {
                dp[i][j] = min(dp[i - 1][j] + (a[i - 1] != c[i + j - 1]), dp[i][j - 1] + (b[j - 1] != c[i + j - 1]));
            }
        }
        cout << dp[n][m] << "\n";
    }
}
