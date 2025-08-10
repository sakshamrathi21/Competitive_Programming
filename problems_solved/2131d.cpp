/**
 *    Author: Saksham Rathi
 *    Created: Sun Aug 10 23:15:50 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
vector<vector<int>> adj;
vector<int> degree;
int n;
int leaves = 0;
int max_leaves = 0;

void dfs(int node, int parent) {
    if (degree[node] == 1) leaves++;
    int nl = 0;
    for (auto l : adj[node]) {
        if (l != parent && degree[l] == 1) nl++;
    }
    max_leaves = max(max_leaves, nl);
    for (auto l : adj[node]) if (l != parent) dfs(l, node);
}

void solve() {
    cin >> n;
    adj.assign(n, vector<int>(0));
    degree.assign(n, 0);
    for (int i = 0 ; i < n - 1 ; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
        degree[x-1]++;
        degree[y-1]++;
    }
    leaves = 0;
    max_leaves = 0;
    int all_set = 0;
    for (int i = 0 ; i < n ; i ++) all_set += (degree[i] == 1);
    if (n == 2 || all_set == n-1) {cout <<"0\n"; return;}
    int node_found = -1;
    for (int i = 0 ; i < n ; i ++ ) if (degree[i] > 1) {node_found = i; break;}
    dfs(node_found, -1);
    cout << leaves - max_leaves << "\n";
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
