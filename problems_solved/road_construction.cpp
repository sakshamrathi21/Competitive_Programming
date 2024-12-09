/**
 *    Author: Saksham Rathi
 *    Created: Mon Dec  9 17:25:41 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

struct DSU {
    vector<int> e;
    void init(int n) { e = vector<int> (n, -1);}
    int get (int x) {
        return e[x] < 0 ? x : e[x] = get(e[x]);
    }
    bool sameSet (int x, int y) {
        return get(x) == get(y);
    }
    int size (int x) {
        return -e[get(x)];
    }
    bool unite (int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return 0;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return 1;
    }
};

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    DSU dsu;
    dsu.init(n);
    int cc = n, large = 1;
    while (m --) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (dsu.unite(x, y)) {
            large = max(large, dsu.size(x));
            cc--;
        }
        cout << cc << " " << large << "\n";
    }
}
