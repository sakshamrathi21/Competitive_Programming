/**
 *    Author: Saksham Rathi
 *    Created: Mon Jun 24 16:31:23 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r, g, b;
    cin >> r >> g >> b;
    vector<int> x(r), y(g), z(b);
    for (int i = 0 ; i < r ; i ++) cin >> x[i];
    for (int i = 0 ; i < g ; i ++) cin >> y[i];
    for (int i = 0 ; i < b ; i ++) cin >> z[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());
    int dp[r+1][g+1][b+1];
    for (int i = 0 ; i <= r ; i ++) {
        for (int j = 0 ; j <= g ; j ++) {
            for (int k = 0 ; k <= b ; k ++) {
                dp[i][j][k] = 0;
            }
        }
    }
    int ans = -1;
    for (int i = 0 ; i <= r ; i ++) {
        for (int j = 0 ; j <= g ; j ++) {
            for (int k = 0 ; k <= b ; k ++) {
                if (i < r && j < g) dp[i+1][j+1][k] = max(dp[i+1][j+1][k], dp[i][j][k]+x[i]*y[j]);
                if (i < r && k < b) dp[i+1][j][k+1] = max(dp[i+1][j][k+1], dp[i][j][k]+x[i]*z[k]);
                if (k < b && j < g) dp[i][j+1][k+1] = max(dp[i][j+1][k+1], dp[i][j][k]+z[k]*y[j]);
                ans = max(ans, dp[i][j][k]);
                // cout << i << " " <<  j << " " << k << " " << dp[i][j][k] << endl;
            }
        }
    }
    // cout << z[0] << endl;
    cout << ans << "\n";
}
