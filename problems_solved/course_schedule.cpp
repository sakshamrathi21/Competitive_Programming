#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int maxN = 1e5 + 1;

int N, M, a, b, cnt, in[maxN];
vector<int> ans, G[maxN];
queue<int> Q;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0 ; i < M ; i ++ ) {
        cin >> a >> b;
        G[a].push_back(b);
        in[b] ++;
    }

    for (int i = 1 ; i <= N ; i ++) {
        if (in[i] == 0) Q.push(i);
    }

    cnt = N;

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        ans.push_back(u);
        cnt -- ;
        for (int v : G[u]) {
            in[v] -- ;
            if (in[v] == 0) Q.push(v);
        }
    }

    if (cnt) cout << "IMPOSSIBLE" << endl;
    else {
        for (int i = 0 ; i < N ; i ++ ) {
            cout << ans[i] << " ";
        }
    }
}
