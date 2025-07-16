/**
 *    Author: Saksham Rathi
 *    Created: Wed Jul 16 20:35:04 IST 2025
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    vii dp(n, vector<int>(n));
    for (int i = 0 ; i < n ; i ++) dp[i][i] = a[i];
    vector<int> psum(n+1, 0);
    for (int i = 0 ; i < n ; i ++) psum[i+1] = psum[i] + a[i];
    for (int l = 1 ; l < n ; l ++ ) {
        for (int i = 0 ; i + l < n ; i ++) {
            // cout << psum[i+l-1]-psum[i-1] << endl;
            dp[i][i+l] = max(a[i] - dp[i+1][i+l] + psum[i+l+1]-psum[i+1], a[i+l] - dp[i][i+l-1] + psum[i+l]-psum[i]);
        }
    }
    cout << dp[0][n-1] << "\n";
}
