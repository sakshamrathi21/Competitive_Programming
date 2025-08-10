/**
 *    Author: Saksham Rathi
 *    Created: Sun Aug 10 17:54:30 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
int n, m, k;
vector<vector<int>> dp;

int get(int i, int j) {
    if (i < 0 || j < 0) return 0;
    if (i >= n) i = n - 1;
    if (j >= m) j = m - 1;
    return dp[i][j];
}

void solve() {

    cin >> n >> m >> k;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0 ; i < n ; i ++) for (int j = 0 ; j < m ; j ++) cin >> a[i][j];
    dp.assign(n, vector<int>(m, 0));
    dp[0][0] = (a[0][0] == 'g');
    for (int i = 1 ; i < n ; i ++) dp[i][0] = dp[i-1][0] + (a[i][0] == 'g');
    for (int j = 1 ; j < m ; j ++) dp[0][j] = dp[0][j-1] + (a[0][j] == 'g');
    for (int i = 1 ; i < n ; i ++) for (int j = 1 ; j < m ; j ++) dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + (a[i][j] == 'g');

    int min_g = n*m;
    for (int i = 0 ; i < n ; i ++) {
        for (int j = 0 ; j < m ; j ++) {
            if (a[i][j] != '.') continue;
            min_g = min(min_g, get(i + k - 1, j + k - 1) + get(i - k, j - k) - get(i + k - 1, j - k) - get(i - k, j + k - 1));
            // cout << min_g << " hello" << endl;
        }
    }
    cout << dp[n-1][m-1] - min_g << "\n";
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
