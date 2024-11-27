#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int n, m;
 
vector<vector<int>> adj(1e5+1);
 
vector<int> longest_route;
 
vector<bool> visited(1e5+1);
 
void DFS(int val, vector<int> route_now) {
    route_now.push_back(val);
    if (val == n) {
        if (route_now.size() > longest_route.size()) longest_route = route_now;
    }
    for (auto u : adj[val]) {
        DFS(u, route_now);
    }
}
 
signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
 
    while (m-- ) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<int> route;
    DFS(1, route);
    if (longest_route.size() == 0) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << longest_route.size() << '\n';
    for (int i = 0 ; i < longest_route.size() ; i ++ ) {
        cout << longest_route[i] << " ";
    }
    return 0;
}
