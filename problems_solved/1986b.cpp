/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun 23 19:43:33 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

int ni(vector<vector<int>> &a, int i, int j) {
    
    int m = -1;
    if (i >= 1) m = max(a[i-1][j], m);  
    if (j >= 1) m = max(a[i][j-1], m);
    if (i < a.size()-1) m = max(a[i+1][j], m);
    if (j < a[0].size()-1) m = max(a[i][j+1], m);
    // if (a[i][j] == 3) cout << "hello" << i << j << m << endl;
    if (m < a[i][j]) return m;
    return a[i][j];
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < m ; j ++) {
                cin >> a[i][j];
            }
        }
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < m ; j ++) {
                cout << ni(a, i, j) << " ";
            }
            cout << "\n";
        }
    }
}
