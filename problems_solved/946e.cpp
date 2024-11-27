#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while (t--) {
        long long m, x;
        cin >> m >> x;
        long long c[m], h[m];
        for (long long i = 0 ; i < m ; i ++) cin >> c[i] >> h[i];
        long long sum_h = 0;
        for (long long i = 0 ; i < m ; i ++ ) sum_h += h[i];
        vector<long long> dp(sum_h+1, INT32_MAX);
        dp[0] = 0;

        for (long long i = 0 ; i < m ; i ++) {
            for (long long j = sum_h ; j >= h[i] ; j --) {
                if (dp[j-h[i]] + c[i] <= i*x) {
                    dp[j] = min(dp[j], dp[j-h[i]] + c[i]);
                }
            }
        }
        for (long long i = sum_h ; i >= 0 ; i --){
            // cout << i<< " hello " << dp[i] << " "<< INT32_MAX << endl;
            if (dp[i] < INT32_MAX) {
                cout << i << endl;
                break;
            }
        }
    }
}
