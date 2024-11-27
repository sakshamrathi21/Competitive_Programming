#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n;

vector<vector<int>> adj(2e5+1);

vector<bool> visited(2e5+1, false);

vector<int> distance_from_root(2e5+1, 0);

void DFS(int val) {
    if (visited[val]) return;
    // cout << " hello " << val << endl;
    visited[val] = true;
    
    for (auto e : adj[val]) {
        // cout << val << " check " << distance_from_root[val] << endl;
        if (!visited[e])distance_from_root[e] = distance_from_root[val] + 1;
        DFS(e);
    }
}


int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for (int i = 1 ; i < n ; i ++ ) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DFS(1);
    int max_distance = 0;
    int max_index = 0;
    for (int i = 1 ; i<= n ; i ++) {
        if (distance_from_root[i] > max_distance) {max_index = i; max_distance = distance_from_root[i];}
    }
    // cout << " check " << max_distance << max_index << endl;;
    fill(visited.begin(), visited.end(), false);
    fill(distance_from_root.begin(), distance_from_root.end(), 0);
    DFS(max_index);
    max_distance = 0;
    max_index = 0;
    for (int i = 1 ; i<= n ; i ++) {
        if (distance_from_root[i] > max_distance) {max_index = i; max_distance = distance_from_root[i];}
    }

    cout << max_distance << '\n';
    return 0;

    // memset(visited, 0, )
}
