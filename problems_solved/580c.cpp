/**
 *    Author: Saksham Rathi
 *    Created: Wed Dec  4 11:48:55 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

int num_l = 0;
vector<bool> visited;

void DFS(vector<vector<int>> &adj, vector<int> &a, int curr, int cons, int &m) {
    // cout << " hello " << curr << " " << cons << " " << (curr != 0 && adj[curr].size() <= 1 && cons+a[curr] <= m) << endl;
    if (curr != 0 && adj[curr].size() <= 1 && cons+a[curr] <= m) {
        num_l ++;
        return;
    }
    
    if (visited[curr]) return;
    visited[curr] = true;
    if (cons+a[curr] > m) return;
    for (auto c : adj[curr]) {
        if (a[curr]) DFS(adj, a, c, cons+a[curr], m);
        else DFS(adj, a, c, 0, m);
    }
    return;
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i ++) cin  >> a[i];
    vector<vector<int>> adj(n);
    for (int i = 0 ; i < n-1 ; i ++ ) {
        int x, y;
        cin  >> x >> y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    visited.assign(n, false);
    DFS(adj, a, 0, 0, m);
    cout << num_l;
}
