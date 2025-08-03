/**
 *    Author: Saksham Rathi
 *    Created: Sun Aug  3 11:47:39 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void dfs(map<int, bool> &vis, int curr, map<int, vector<int>> &adj) {
    cout << curr << " ";
    vis[curr] = true;
    for (auto x: adj[curr]) {
        if (vis.find(x) == vis.end() || !vis[x]) dfs(vis, x, adj);
    }
}

void solve()
{
    int n;
    cin >> n;
    map<int, vector<int>> adj;
    for (int i = 0 ; i < n ; i ++) {
        int a, b;
        cin >> a >> b;
        if (adj.find(a) == adj.end()) adj[a] = vector<int>();
        if (adj.find(b) == adj.end()) adj[b] = vector<int>();
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int done = -1;
    for (auto x : adj) if (x.second.size() == 1) {done = x.first; break;}
    map<int, bool> vis;
    dfs(vis, done, adj);
    cout << "\n";
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
