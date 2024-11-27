/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun 30 09:09:43 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        for (int i = 0 ; i < n ; i ++) {
            cin >> b[i];
        }

        int max_sum = 0;
        int tot = 0, ls = 0;
        for (int i = 0 ; i < n ; i ++) {
            tot += a[i]*a[i] + b[i]*b[i];
            max_sum += max(a[i], b[i]);
            ls += (a[i]+b[i]);
        }
        vector<vector<bool>> dp(n, vector<bool>(max_sum+1, false));
        dp[0][a[0]] = true;
        dp[0][b[0]] = true;
        for (int i = 1 ; i < n ; i ++) {
            for (int j = 0 ; j <= max_sum ; j ++) {
                if (j-a[i] >= 0) dp[i][j] = dp[i-1][j-a[i]];
                if (j-b[i] >= 0 && dp[i-1][j-b[i]]) dp[i][j] = true;
            }
        }
        int min_sum= LLONG_MAX;
        for (int i = 0 ; i <= max_sum ; i ++) {
            if (dp[n-1][i]) min_sum = min(min_sum, i*i+(ls-i)*(ls-i));
        }
        cout << tot*(n-2)+min_sum << "\n";
    }
}
