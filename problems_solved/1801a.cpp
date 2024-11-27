/**
 *    Author: Saksham Rathi
 *    Created: Fri Jun 14 18:40:38 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int a[256][256];
    int now = 0;
    for (int i = 0 ; i < 256 ; i += 2) {
        for (int j = 0 ; j < 256 ; j += 2) {
            a[i][j] = now;
            a[i][j+1] = now+1;
            a[i+1][j] = now+2;
            a[i+1][j+1] = now+3;
            now += 4;
        }
    }
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << n*m << "\n";
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < m ; j ++) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
