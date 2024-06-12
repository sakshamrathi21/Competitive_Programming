#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5+1;

int N, M, K, a, b, p[maxN], dist[maxN];
bool vis[maxN];
vector<int> G[maxN];

vector<int> level(maxN, 1);

bool possible = true;

void BFS(int val) {
    queue<int> Q;
    Q.push(val);
    level[val] = 0;
    vis[val] = true;
    while(!Q.empty()){
        if (!possible) return;
        int u = Q.front(); Q.pop();
        for(int v : G[u]){
            if(!vis[v]){
                dist[v] = dist[u]+1;
                vis[v] = true;
                p[v] = u;
                Q.push(v);
                level[v] = (level[u] + 1)%2;
            }
            else {
                if (level[v]%2 == level[u]%2) {
                    cout << "IMPOSSIBLE";
                    possible = false;
                    // return 0;
                }
            }
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    for (int i = 1 ; i <= N ; i ++ ) {
        if (!vis[i]) BFS(i);
        if (!possible) return 0;
    }
    for (int i = 1 ; i <= N ; i ++ ) {
        cout << level[i] + 1 << " ";
    }
}