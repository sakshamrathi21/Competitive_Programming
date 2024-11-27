#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m;

const int INF = 4e18;

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(2*n+1);

    for (int i = 0 ; i < m ; i ++ ) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[n+a].push_back({b+n, c});
        adj[a].push_back({b+n, c/2});
    }

    vector<int> distance_from_S(2*n+1, INF);
    distance_from_S[1] = 0;
    vector<bool> processed(2*n+1, false);
    priority_queue<pair<int, int>> q;
    q.push({0, 1});
    while (!q.empty()) {
        int x = q.top().second;
        q.pop();
        if (processed[x]) continue;
        processed[x] = true;
        for (auto u : adj[x]) {
            int p = u.first, w = u.second;
            if (distance_from_S[x] + w < distance_from_S[p]) {
                distance_from_S[p] = distance_from_S[x] + w;
                q.push({-distance_from_S[p], p});
            }
        }
    }

    cout << distance_from_S[2*n];
    return 0;

}
