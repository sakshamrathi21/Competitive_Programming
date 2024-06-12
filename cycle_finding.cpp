#include<bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 4e18;

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n+1);
    vector<pair<pair<int, int>, int>> edges;
    for (int i = 0 ; i < m ; i ++ ) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        edges.push_back({{a, b}, c});
    }

    vector<int> distance_from_root(n+1, INF);
    vector<int> parent(n+1, -1);

    distance_from_root[1] = 0;
    for (int i = 1 ; i <= n - 1 ; i ++ ) {
        
        for (auto e : edges) {
            int x = e.first.first, y = e.first.second, z = e.second;
            if (distance_from_root[y] > distance_from_root[x] + z) {
                parent[y] = x;
                distance_from_root[y] = distance_from_root[x] + z;
            }
        }
    }

    // int possible = false;
    int start = -1;
    for (auto e : edges) {
        int x = e.first.first, y = e.first.second, z = e.second;
        if (distance_from_root[y] > distance_from_root[x] + z) {
            parent[y] = x;
            start = x;
            break;
            // distance_from_root[y] = distance_from_root[x] + z;
        }
    }
    

    if (start == -1) {
        cout << "NO" ;
        return 0;
    }

    

    vector<int> ans(n+1, -1);
    int i = 1;
    int current = parent[start];
    cout << start <<  " hello " << parent[start] << endl;
    ans[0] = current;
    current = parent[current];
    while (current != parent[start]) {
        cout << current << endl;
        ans[i] = current;
        i ++;
        current = parent[current];
    }
    
    // ans[i] = start;
    cout << "YES" << '\n';

    for (int j = 1 ; j <= i ; j ++ ) {
        // if (ans[j] == -1) break;
        cout << ans[i-j] << " ";
    }
    cout << ans[i-1];
    // cout << ans[i];
    return 0;

}
