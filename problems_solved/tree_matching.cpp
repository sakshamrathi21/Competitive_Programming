/**
 *    Author: Saksham Rathi
 *    Created: Thu Dec  5 16:17:35 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

vii dp;
vi visited;

void DFS(vii &child, int node, int parent) {
    if (visited[node]) return;
    visited[node] = 1;
    // if (node == )
    for (auto c : child[node]) {
        if (c == parent) continue;
        DFS(child, c, node);
        dp[0][node] += max(dp[0][c], dp[1][c]);
        int opt = min(dp[0][c] - dp[1][c], 0LL);
        dp[1][node] = max(opt, dp[1][node]);
    }

    // for (auto c : child[node]) dp[1][node] += dp[0][c];
    dp[1][node] += dp[0][node];
    dp[1][node] ++;
    return;
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vii child(n);
    for (int i = 1; i < n ; i ++ ) {
        int a, b;
        cin >> a >> b;
        child[a-1].push_back(b-1);
        child[b-1].push_back(a-1);
    }
    dp.assign(2, vector<int>(n));
    for (int i = 0 ; i < n ; i ++) {
        dp[0][i] = 0;
        dp[1][i] = INT32_MIN;
    }
    visited.assign(n, 0);
    DFS(child, 0, -1);
    cout << max(dp[0][0], dp[1][0]) << "\n";
}
