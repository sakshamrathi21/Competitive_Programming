/**
 *    Author: Saksham Rathi
 *    Created: Sun Aug  3 10:32:30 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

int N = 500;
vector<vector<int>> adj(N);
vector<int> parent(N), depth(N);

void dfs(int u, int p) {
    parent[u] = p;
    for (int v : adj[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}

vector<int> get_path(int u, int v) {
    vector<int> path_u, path_v;
    int orig_u = u, orig_v = v;
    // u = parent[u];
    // v = parent[v];
    // if (u == -1 || v == -1) return vector<int>();
    while (u != v) {
        if (depth[u] > depth[v]) {
            if (u != orig_u) path_u.push_back(u);
            u = parent[u];
        } else {
            if (v != orig_v) path_v.push_back(v);
            v = parent[v];
        }
    }

    if (u != orig_u && u != orig_v) path_u.push_back(u); 

    reverse(path_v.begin(), path_v.end());
    path_u.insert(path_u.end(), path_v.begin(), path_v.end());
    
    // cout << orig_u << " " << orig_v << " path " ;
    // for (auto x : path_u) cout << x << " ";
    // cout << "\n";
    return path_u;
}


void solve()
{
    int n;
    cin >> n;
    
    for (int i = 1 ; i < n ; i ++) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    dfs(0, -1);
    vector<int> leaves;
    leaves.push_back(0);
    int x;
    // cout << n << " hello " << endl;
    while (cin >> x) leaves.push_back(x-1);
    
    leaves.push_back(0);
    // for (int i = 0 ; i < leaves.size() ; i ++) 
    vector<int> path;
    for (int i = 1 ; i < leaves.size() ; i ++ ) {
        // cout << n << " hello " << endl;
        vector<int> cpath = get_path(leaves[i-1], leaves[i]);
        path.push_back(leaves[i-1]);
        path.insert(path.end(), cpath.begin(), cpath.end());
    }
    path.push_back(leaves[leaves.size() - 1 ]);
    if (path.size() != (2*n-1)) {cout << "-1\n"; return;}
    for (auto p : path) cout << p + 1 << " ";
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
