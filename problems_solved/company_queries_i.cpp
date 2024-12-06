/**
 *    Author: Saksham Rathi
 *    Created: Fri Dec  6 11:42:47 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
const int N = pow(2, 20);

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vii parents(21, vector<int>(n));
    for ( int i = 1 ; i < n ; i ++ ) {
        int x;
        cin  >> x; x--;
        parents[0][i] = x;
    }
    parents[0][0] = -1;
    for (int i = 1 ; i <= 20 ; i ++ ) {
        for (int j = 0 ; j < n ; j ++ ) {
            if (parents[i-1][j] == 0 || parents[i-1][j] == -1) parents[i][j] = -1;
            else parents[i][j] = parents[i-1][parents[i-1][j]];
        }
    }
    while (q--) {
        int x, k;
        cin >> x >> k;
        x--;
        for (int i = 0 ; i <= 20 ; i ++ ) {
            if (k & (1 << i)) x = parents[i][x];
            if (x == -1) break;
        }
        if (x != -1) x += 1;
        cout << x << "\n";
    }
}
