/**
 *    Author: Saksham Rathi
 *    Created: Thu Dec  5 15:57:13 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

map<int, int> ns;

int DFS(vii &child, int node) {
    if (ns.find(node) != ns.end()) return ns[node];
    int cnt = 0;
    for (auto c : child[node]) cnt += DFS(child, c);
    ns[node] = cnt;
    return cnt + 1;
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vii child(n);
    for (int i = 1 ; i < n ; i ++ ) {
        int x;
        cin >> x;
        x--;
        if (x == i) continue;
        child[x].push_back(i);
    }
    DFS(child, 0);
    for (auto p : ns) cout << p.second << " ";
}
