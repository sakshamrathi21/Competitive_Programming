/**
 *    Author: Saksham Rathi
 *    Created: Mon Jul  8 15:47:17 IST 2024
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
        vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
        for (int i = 0 ; i < n ; i ++) {
            string s;
            cin >> s;
            for (int j = 0 ; j < m ; j ++) {
                a[i][j] = s[j]-'0';
            }
        }

        for (int i = 0 ; i < n ; i ++) {
            string s;
            cin >> s;
            for (int j = 0 ; j < m ; j ++) {
                b[i][j] = s[j]-'0';
            }
        }
        bool poss = true;
        for (int i = 0 ; i < n ; i ++) {
            int diff = 0;
            for (int j = 0 ; j < m ; j ++) {
                diff += (3+a[i][j]-b[i][j])%3;
            }
            if (diff%3) {poss = false; break;}
        }
        for (int i = 0 ; i < m ; i ++) {
            int diff = 0;
            for (int j = 0 ; j < n ; j ++) {
                diff += (3+a[j][i]-b[j][i])%3;
            }
            if (diff%3) {poss = false; break;}
        }
        if (poss) cout << "YES\n";
        else cout << "NO\n";
    }
}
