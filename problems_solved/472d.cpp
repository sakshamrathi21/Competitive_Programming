/**
 *    Author: Saksham Rathi
 *    Created: Tue Aug  5 16:29:46 IST 2025
**/

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

struct DSU {
    vector<int> par;
    DSU(int n) : par(n) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    bool merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        par[y] = x;
        return true;
    }
};

bool solve() {
    int n;
    cin >> n;
    vector<vector<int>> d(n, vector<int>(n));
    
    for (int i = 0 ; i < n ; i ++) {
        for (int j = 0 ; j < n ; j ++) {
            cin >> d[i][j];
        }
    }

    for (int i = 0 ; i < n ; i ++) {
        if (d[i][i] != 0) return false;
        for (int j = 0 ; j < n ; j ++) {
            if (d[i][j] != d[j][i]) return false;
            if (i != j && d[i][j] <= 0) return false;
        }
    }

    vector<tuple<int, int, int>> edges; 
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < i ; j++) {
            edges.emplace_back(d[i][j], i, j);
        }
    }
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    vector<vector<pair<int, int>>> tree(n); 

    for (auto [w, u, v] : edges) {
        if (dsu.merge(u, v)) {
            tree[u].emplace_back(v, w);
            tree[v].emplace_back(u, w);
        }
    }

    int edge_count = 0;
    for (auto& v : tree) edge_count += v.size();
    if (edge_count != 2 * (n - 1)) return false;

    vector<vector<int>> dist(n, vector<int>(n, -1));
    function<void(int,int,int)> dfs = [&](int u, int p, int cost) {
        dist[p][u] = cost;
        for (auto [v, w] : tree[u]) {
            if (dist[p][v] == -1)
                dfs(v, p, cost + w);
        }
    };

    for (int i = 0 ; i < n ; i++) {
        dfs(i, i, 0);
    }

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (d[i][j] != dist[i][j]) return false;
        }
    }

    return true;
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool res = solve();
    cout << (res ? "YES\n" : "NO\n");
}
