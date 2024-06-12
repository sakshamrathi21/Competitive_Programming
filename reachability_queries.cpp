#include<bits/stdc++.h>
using namespace std;

const int maxN = 5e4+1;
int N, M, a, b, in[maxN];
bitset<maxN> ans[maxN];
vector<int> G[maxN];
queue<int> Q;

int main () {
    int q;
    cin >> N >> M >> q;
    for (int i = 0 ; i < M ; i ++ ) {
        cin >> a >> b;
        G[b].push_back(a);
        in[a] ++;
    }

    for (int i = 1 ; i <= N ; i ++ ) {
        // cout << i << " check " << in[i] << endl; 
        if (in[i] == 0) {
            // cout << i << " check" << endl;
            ans[i].set(i);
            Q.push(i);
        }
    }

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v : G[u]) {
            ans[v] |= ans[u];
            in[v] --;
            if (in[v] == 0) {
                ans[v].set(v);
                Q.push(v);
            }
        }
    }

    // for (int i = 1 ; i < 10 ; i ++ ) {
    //     // ans[1].set(i);
    //     cout << ans[2].test(i) << endl;
    // }
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (ans[x].test(y)) cout << "YES" <<'\n';
        else cout << "NO" << '\n';
    }
}