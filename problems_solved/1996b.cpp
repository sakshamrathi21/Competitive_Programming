/**
 *    Author: Saksham Rathi
 *    Created: Sat Jul 27 13:37:34 IST 2024
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
        int n, k;
        cin >> n >> k;
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0 ; i < n ; i ++) {
            string s;
            cin >> s;
            for (int j = 0 ; j < n ; j ++) {
                a[i][j] = s[j]-'0';
            }
        }
        // cout << " hello " << n << endl;
        for (int i = 0 ; i < n ; i += k) {
            for (int j = 0 ; j < n ; j += k) {
                
                cout << a[i][j];
            }
            cout << "\n";
            // cout << " hello " << i << n << k << endl;
        }
    }
}
