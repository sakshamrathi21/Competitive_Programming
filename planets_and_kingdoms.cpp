#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m;

vector<vector<int>> adj(1e5+1);

vector<bool> visited(1e5+1, false);

vector<int> componentids(1e5+1, 0);

void DFS(int val, int componentID) {
    if (visited[val]) return;
    visited[val] = true;
    componentids[val] = componentID;
    for (auto u : adj[val]) DFS(u, componentID);
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    while (m-- ) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    int componentID = 1;
    for (int i = 1 ; i <= n ; i ++ ) {
        if (!visited[i]) DFS(i, componentID);
        componentID ++;
    }

    cout << componentID - 1 << endl;
    for (int i = 1 ; i <= n ; i ++) cout << componentids[i] << " ";
}
