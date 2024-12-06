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
vi sst;
vi sd;

int DFS(vii &child, int node, int parent, int dis) {
    if (visited[node]) return sst[node];
    visited[node] = 1;
    d[node] = dis;
    sst[node] = 1;
    for (auto c : child[node]) {
        if (c == parent) continue;
        int cnt = DFS(child, c, node, dis + 1);
        sst[node] += cnt;
    }
    return sst[node];
}

void DFS2(vii &child, int node, int parent) {
    if (visited[node]) return;
    visited[node] = 1;
    if (node != 0) sd[node] = sd[parent] + child.size() - 2 * (sst[node]);
    for (auto c : child[node]) {
        if (c == parent) continue;
        DFS2(child, c, node);
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
    sd.assign(n, 0);
    sst.assign(n, 0);
    visited.assign(n, 0);
    DFS(child, 0, -1, 0);
    for (auto x : d) sd[0] += x;
    visited.assign(n, 0);
    DFS2(child, 0, -1);
    for (auto x : sd) cout << x << " ";
}
