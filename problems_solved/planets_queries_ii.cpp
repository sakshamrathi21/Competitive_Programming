#include<bits/stdc++.h>
using namespace std;
#define int long long

int succ[21][2000005];
int vis[2000005];
int len[2000005];

void dfs(int s) {
    if (vis[s]) return;
    vis[s] = 1;
    dfs(succ[0][s]);
    len[s] = len[succ[0][s]] + 1;
}

int lift(int x, int d) {
    if (d <= 0 ) return x;
    int i = 0 ;
    while (d > 0) {
        if (d & 1) x = succ[i][x];
        d >>= 1;
        i ++;
    }
    return x;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1 ; i <= n ; i ++ ) {
        cin >> succ[0][i];
    }

    for (int i = 1 ; i <= 20 ; i ++ ) {
        for (int j = 1 ; j <= n ; j ++ ) {
            succ[i][j] = succ[i-1][succ[i-1][j]];
        }
    }

    for (int i = 1 ; i <= n ; i ++) {
        if (!vis[i]) dfs(i);
    }

    while (q-- ) {
        int x, y;
        cin >> x >> y;
        int xx = lift(x, len[x]);
        if (lift(x, len[x]-len[y]) == y) cout << len[x] - len[y] << endl;
        else if (lift(xx, len[xx] - len[y]) == y) cout << len[x] + len[xx] - len[y] << endl;
        else cout << -1 << endl;
    }
}
