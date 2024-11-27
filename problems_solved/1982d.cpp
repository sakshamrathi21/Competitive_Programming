/**
 *    Author: Saksham Rathi
 *    Created: Tue Jun 25 21:33:03 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int x, int y) {
    if (y == 0) return x;
    if (x < y) return gcd(y, x);
    if (x%y ==0) return y;
    return gcd(x%y, y);
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int a[n][m];
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < m ; j ++) {
                cin >> a[i][j];
            }
        }
        int totSum = 0;
        int b[n][m];
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < m ; j ++) {
                char x;
                cin >> x;
                if (x == '0') {
                    b[i][j] = -1;
                }
                else b[i][j] = 1;
                totSum += a[i][j]*b[i][j];
            }
        }
        if (totSum == 0) {
            cout << "YES\n";
            continue;
        }
        
        // int b[n-k+1][m-k+1];
        vector<vector<int>> cumSum(n+1, vector<int>(m+1, 0));
        for (int i = 1 ; i <= n ; i ++) {
            for (int j = 1 ; j <= m ; j ++) {
                // cout << " hello " << i << j << endl;
                cumSum[i][j] = b[i-1][j-1] + cumSum[i-1][j] + cumSum[i][j-1] - cumSum[i-1][j-1];  
                
            }
        }
        // cout << " hello " << endl;
        // int totSum = 0;
        // for (int i = 0 )
        vector<int> f;
        for (int i = 0 ; i <= n-k ; i ++) {
            for (int j = 0 ; j <= m-k ; j ++) {
                int q = cumSum[i+k][j+k] - cumSum[i][j+k] - cumSum[i+k][j] + cumSum[i][j];
                // cout << q << " ";
                if (q != 0) f.push_back(abs(q));
                // cout << 
            }
            // cout << endl;
        }
        if (f.size() == 0) {
            cout << "NO\n";
            continue;
        }
        int g = f[0];
        for (int i = 0 ; i < f.size() ; i ++ ) {
            g = gcd(f[i], g);
        }
        totSum = abs(totSum);
        // cout << " hello " << totSum << g << endl;
        if (totSum%g == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}
