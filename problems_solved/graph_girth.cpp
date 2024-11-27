#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 2510;
const int inf = 1000000007;

int n, m;
vector<int> adj[maxn];

int cycle_len(int start) {
    int ans = inf;

    vector<int> dist(n, -1);

    queue<int> bfs;

    dist[start] = 0;
    bfs.push(start);

    while (!bfs.empty()) {
        int node = bfs.front();
        bfs.pop();

        for (int adj_node : adj[node]) {
            if (dist[adj_node] == -1) {
                dist[adj_node] = dist[node] + 1;
                bfs.push(adj_node);
            }
            else if (dist[adj_node] >= dist[node] ) {
                ans = min(ans, 1 + dist[adj_node] + dist[node]);
            }
        }
    }

    return ans;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0 ; i < m ; i ++ ) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int res = inf;
    for (int i = 0 ; i < n ; i ++ ) {
        res = min(res, cycle_len(i));
    }
    if (res == inf) {
        cout << -1;
        return 0;
    }
    cout << res;
}
