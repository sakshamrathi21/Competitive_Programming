/**
 *    Author: Saksham Rathi
 *    Created: Sat Aug 30 13:21:06 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

int dp[1009][1009];
int n, m;

vector<vector<pair<int, int>>> p;

int calc(vector<int>&a, vector<int>&b, int i, int j) {
    // cout << i << " " << j << " " << dp[i][j] << endl;
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (a[i] == b[j]) {
        p[i][j] = {i - 1, j - 1};
        return dp[i][j] = 1 + calc(a, b, i - 1, j - 1);
    }
    int x = calc(a, b, i - 1, j);
    int y = calc(a, b, i, j -1);
    if (x > y) p[i][j] = {i - 1, j};
    else p[i][j] = {i, j - 1};
    return dp[i][j] = max(x, y);
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    p.resize(n, vector<pair<int, int>>(m, {-1000, -1000}));
    vector<int> a(n), b(m);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    for (int i = 0 ; i < m ; i ++) {
        cin >> b[i];
    }
    cout << calc(a, b, n - 1, m - 1) << "\n";
    vector<int> vals;
    int curri = n - 1, currj = m - 1;
    while (true) {
        if (a[curri] == b[currj]) vals.push_back(a[curri]);
        pair<int, int> par = p[curri][currj];
        if (par.first == -1 || par.second == -1) break;
        curri = par.first;
        currj = par.second;
    }
    reverse(vals.begin(), vals.end());
    for (auto x : vals) cout << x << " ";
    cout << "\n";
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
