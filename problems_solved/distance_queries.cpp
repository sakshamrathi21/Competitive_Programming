/**
 *    Author: Saksham Rathi
 *    Created: Sun Dec  8 19:22:00 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
const int N = pow(2, 20);

vi dist;

void DFS(vii & child, int node, int dis, int parent, vii &parents) {
    dist[node] = dis;
    parents[0][node] = parent;
    for (auto c : child[node]) if (c != parent) DFS(child, c, dis + 1, node, parents);
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vii parents(21, vector<int>(n));
    vii child (n);
    for ( int i = 1 ; i < n ; i ++ ) {
        int a, b;
        cin >> a >> b;
        a -- , b -- ;
        child[a].push_back(b);
        child[b].push_back(a);
    }
    dist.assign(n, -1);
    DFS(child, 0, 0, -1, parents);
    parents[0][0] = -1;
    for (int i = 1 ; i <= 20 ; i ++ ) {
        for (int j = 0 ; j < n ; j ++ ) {
            if (parents[i-1][j] == 0 || parents[i-1][j] == -1) parents[i][j] = -1;
            else parents[i][j] = parents[i-1][parents[i-1][j]];
        }
    }
    
    while (q--) {
        int a, b, k, x;
        cin >> a >> b;
        a--, b--;
        int a1 = a, b1 = b;
        bool on = true;
        if (dist[a] > dist[b]) {
            x = a, k = dist[a] - dist[b];
        }
        else {
            on = false;
            x = b, k = dist[b] - dist[a];
        }
        for (int i = 0 ; i <= 20 ; i ++ ) {
            if (k & (1 << i)) x = parents[i][x];
            if (x == -1) break;
        }
        if (on) a = x;
        else b = x;
        while (a != b) {
            int i;
            for (i = 0 ; i < 15 ; i ++) {
                if (parents[i][a] == parents[i][b]) break;
            }
            i = max(i-1, 0LL);
            a = parents[i][a], b = parents[i][b];
        }
        cout << abs(dist[a] - dist[a1]) + abs(dist[b] - dist[b1]) << "\n";
    }
}
