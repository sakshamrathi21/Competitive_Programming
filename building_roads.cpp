#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;

vector<bool> visited;

vector<vector<int>> adjacency;

void DFS(int x) {
    visited[x] = 1;
    for (int i = 0 ; i < adjacency[x].size() ; i ++ ) {
        if (!visited[adjacency[x][i]])
        DFS(adjacency[x][i]);
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    vector<int> push_vec;
    for (int i = 0 ; i < n ; i ++ ) {
        visited.push_back(0);
        adjacency.push_back(push_vec);
    }
    for (int i = 0 ; i < m ; i ++ ) {
        int x, y;
        cin >> x >> y;
        adjacency[x-1].push_back(y-1);
        adjacency[y-1].push_back(x-1);
    }

    vector<int> connected_heads;
    for (int i = 0 ; i < n ; i ++ ) {
        if (!visited[i]) {
            DFS(i);
            connected_heads.push_back(i);
        }
    }

    cout << connected_heads.size() - 1 << endl;
    for (int i = 0 ; i < connected_heads.size() - 1 ; i ++ ) {
        cout << connected_heads[i] + 1 << " " << connected_heads[i+1] + 1 << '\n';
    }

}
