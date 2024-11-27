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
        int c[n][m];
        vector<vector<int>> s(m, vector<int>(n));
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < m ; j ++) {
                cin >> c[i][j];
                s[j][i] = c[i][j];
            }
        }
        int total = 0;
        for (int i = 0 ; i < m ; i ++) {
            sort(s[i].begin(), s[i].end());
            int curr = -(n-1);
            for (int j = 0 ; j < n ; j ++) {
                total += curr*s[i][j];
                curr += 2;
            }
        }
        cout << total << "\n";
    }
}
