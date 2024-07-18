/**
 *    Author: Saksham Rathi
 *    Created: Thu Jul 18 20:07:13 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        vector<vector<int>> b(n, vector<int>(m));
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < m ; j ++) {
                cin >> a[i][j];
                b[i][j] = n*m+1 - a[i][j];
            }
        }
        if (n*m == 1) {
            cout << "-1\n";
            continue;
        }
        if (n*m%2) {
            int f = (n*m+1)/2;
            int posi = -1, posj = -1;
            for (int i = 0 ; i < n ; i ++) {
                for (int j = 0 ; j < m ; j ++) {
                    if (a[i][j] == f) {
                        posi = i;
                        posj = j;
                        break;
                    }
                }
            }
            if (posi+1 < n) swap(b[posi][posj], b[posi+1][posj]);
            else if (posi-1 >= 0 ) swap(b[posi][posj], b[posi-1][posj]);
            else if (posj+1 < m) swap(b[posi][posj], b[posi][posj+1]);
            else if (posj-1 >= 0 ) swap(b[posi][posj], b[posi][posj-1]);
        }
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < m ; j ++) {
                cout << b[i][j] << " ";
            }
            cout << "\n";
        }

    }
}
