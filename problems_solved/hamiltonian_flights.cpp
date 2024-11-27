#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1000000007;

int n, m;
vector<vector<int>> adj(21);

vector<bool> visited(21, false);

int DFS(int current_city) {
    if (visited[current_city]) return 0;
    visited[current_city] = true;
    int count = 0 ;
    if (current_city == n) {
        visited[current_city] = false;
        for (int i = 1 ; i < n ; i ++) {
            if (!visited[i]) return 0;
        }
        return 1;
    }
    for (auto x : adj[current_city]) {
        count += DFS(x);
        count %= MOD;
    }
    visited[current_city] = false;

    return count;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0 ; i < m ; i ++ ) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    cout << DFS(1);
}
