/**
 *    Author: Saksham Rathi
 *    Created: Sat Aug 30 17:16:53 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
vector<vector<char>> a;

int vot(int i1, int j1, int i2, int j2, int i3, int j3) {
    int sum = 0;
    if (a[i1][j1] == 'A') sum += 1;
    if (a[i2][j2] == 'A') sum += 1;
    if (a[i3][j3] == 'A') sum += 1;
    return sum >= 2 ? 1 : 0;
}

void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    a.resize(n + 1, vector<char>(2));
    for (int i = 0 ; i < n ; i ++) {
        a[i + 1][0] = s1[i];
        a[i + 1][1] = s2[i];
    }
    int dp[n + 5][3];
    memset(dp, 0, sizeof(dp));
    for (int i = 0 ; i <= n ; i ++) {
        dp[i + 3][0] = max(dp[i + 3][0], dp[i][0] + vot(i + 1, 0, i + 2, 0, i + 3, 0) + vot(i + 1, 1, i + 2, 1, i + 3, 1));
        dp[i + 2][1] = max(dp[i + 2][1], dp[i][0] + vot(i + 1, 0, i + 1, 1, i + 2, 0));
        dp[i + 2][2] = max(dp[i + 2][2], dp[i][0] + vot(i + 1, 0, i + 1, 1, i + 2, 1));
        dp[i + 3][0] = max(dp[i + 3][0], dp[i + 1][1])
    }
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
