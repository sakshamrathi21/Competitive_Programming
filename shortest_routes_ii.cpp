#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long

const int INF = 4e18;

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> adj(501, vector<int>(501, INF));
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        
        adj[a][b] = min(adj[a][b], c);
        adj[b][a] = min(adj[b][a], c);
    }
    vector<vector<int>> distance(501, vector<int>(501, INF));
    for (int i = 1 ; i <= n ; i ++ ) {
        for (int j = 1 ; j <= n ; j ++ ) {
            if (i == j) distance[i][j] = 0;
            else if (adj[i][j]) distance[i][j] = adj[i][j];
            else distance[i][j] = INF;
        }
    }

    // cout << " check " << adj[1][2];

    for (int k = 1 ; k <= n; k ++ ) {
        for (int i = 1 ; i <= n ; i ++ ) {
            for (int j = 1 ; j <= n ; j ++ ) {
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        if (distance[x][y] == INF) cout << -1 << '\n';
        else cout << distance[x][y] << '\n';
    }
}
