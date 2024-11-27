#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long

const int INF = 4e18;

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(1e5 + 1);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        // adj[b].push_back({a, c});
    }
    vector<int> distance(1e5 + 1, INF);
    distance[1] = 0;
    priority_queue<pair<int, int>> q;
    q.push({0, 1});
    vector<bool> processed(1e5+1, false);
    while (!q.empty()) {
        int a = q.top().second;
        q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            int p = u.first;
            int w = u.second;
            if (distance[a] + w < distance[p]) {
                distance[p] = distance[a] + w;
                q.push({-distance[p], p});
            }
        }
    }

    for (int i = 1 ; i <= n ; i ++ ) cout << distance[i] << " ";
    cout << endl;
}
