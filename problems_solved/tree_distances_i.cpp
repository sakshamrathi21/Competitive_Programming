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

vi d;
vi visited;

void DFS(vii &child, int node, int parent, int dis) {
    if (visited[node]) return;
    visited[node] = 1;
    d[node] = dis;
    for (auto c : child[node]) {
        if (c == parent) continue;
        DFS(child, c, node, dis + 1);
    }
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
    d.assign(n, 0);
    visited.assign(n, 0);
    DFS(child, 0, -1, 0);
    int mx_node = 0;
    for (int i = 0 ; i < n ; i ++) {
        if (d[mx_node] < d[i]) mx_node = i;
    }
    // int a = mx_node;
    d.assign(n, 0);
    visited.assign(n, 0);
    DFS(child, mx_node, -1, 0);
    for (int i = 0 ; i < n ; i ++) {
        if (d[mx_node] < d[i]) mx_node = i;
    }
    vector<int> da = d;
    int b = mx_node;
    d.assign(n, 0);
    visited.assign(n, 0);
    DFS(child, b, -1, 0);
    for (int i = 0 ; i < n ; i ++ ) {
        cout << max(d[i], da[i]) << " ";
    }
}
