/**
 *    Author: Saksham Rathi
 *    Created: Wed Aug  6 15:41:40 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;


int n; 
vector<vector<int>> adj; 

vector<pair<int, int>> bridge_edges;

void IS_BRIDGE(int v,int to) {
    bridge_edges.emplace_back(v, to);
}

vector<bool> visited;
vector<int> tin, low, subtree;
int timer;

int dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    int count = 0;
    for (int to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            count += dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
    subtree[v] = count + 1;
    return subtree[v];
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    subtree.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}


void solve() {
    int m;
    cin >> n >> m;
    adj.clear();
    bridge_edges.clear();
    adj.resize(n);
    for (int i = 0 ; i < m ; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    find_bridges();
    int max_val = 0;
    for (auto e : bridge_edges) max_val = max(max_val, min(subtree[e.first], subtree[e.second])*(n-min(subtree[e.first], subtree[e.second])));
    cout << n*(n-1)/2 - max_val << "\n";
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
