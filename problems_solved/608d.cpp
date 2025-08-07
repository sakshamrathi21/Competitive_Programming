/**
 *    Author: Saksham Rathi
 *    Created: Thu Aug  7 10:31:30 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
int n;
vector<int> c;
int dp[510][510];

int calc_dp(int i, int j) {
    if (i == j) return 1;
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int cost = 1 + calc_dp(i + 1, j);
    if (i + 1 < n && c[i] == c[i+1]) cost = min(cost, 1 + calc_dp(i + 2, j));
    for (int k = i + 2 ; k <= j ; k ++) if (c[i] == c[k]) cost = min(cost, calc_dp(i + 1, k - 1) + calc_dp(k + 1, j));
    // cout << i << " " << j << " " << cost << endl;
    return dp[i][j] = cost;
}

void solve() {
    cin >> n;
    c.resize(n);
    for (int i = 0 ; i < n ; i ++) cin >> c[i];
    memset(dp, -1, sizeof(dp));
    cout << calc_dp(0, n - 1) << "\n";
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
