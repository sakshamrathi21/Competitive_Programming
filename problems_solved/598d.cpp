/**
 *    Author: Saksham Rathi
 *    Created: Wed Aug  6 08:43:25 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

vector<vector<bool>> vis;
vector<vector<char>> a;
vector<vector<pair<int, int>>> p;
int mini = -1, minj = -1;

void dfs(int i, int j, int & count) {
    if (a[i][j] == '-') return;
    if (a[i][j] == '*') {count++; return;}
    if (vis[i][j]) return;
    vis[i][j] = true;
    p[i][j] = make_pair(mini, minj);
    dfs(i-1, j, count);
    dfs(i+1, j, count);
    dfs(i, j-1, count);
    dfs(i, j+1, count);
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    a.resize(n+2, vector<char>(m+2, '-'));
    for (int i = 1 ; i <= n ; i ++) {
        string s;
        cin >> s;
        for (int j = 1 ; j <= m ; j ++ ) a[i][j] = s[j-1];
    }
    vis.resize(n+2, vector<bool>(m+2, false));
    p.resize(n+2, vector<pair<int, int>>(m+2));
    map<pair<int, int>, int> vis_size;
    for (int i = 1 ; i <= n ; i ++) {
        for (int j = 1 ; j <= m ; j ++) {
            if (a[i][j] == '*' || vis[i][j]) continue;
            int count = 0;
            mini = i;
            minj = j;
            dfs(i, j, count);
            // cout << i << " " << j << " " << visited.size() << endl;
            vis_size[make_pair(i, j)] = count;
        }
    }
    for (int i = 0 ; i < k ; i ++) {
        int x, y;
        cin >> x >> y;
        cout << vis_size[p[x][y]] << "\n";
    }
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
