/**
 *    Author: Saksham Rathi
 *    Created: Tue Jun 11 20:24:57 IST 2024
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
        vector<vector<int>> a(n, vector<int>(m, 0));
        int max_h = -1, max_r = 0;
        for (int i = 0 ; i < n ; i ++) {
            int curr = 0;
            for (int j = 0 ; j < m ; j ++) {
                char c;
                cin >> c;
                if (c == '#') a[i][j] = 1;
                curr += a[i][j];
            }
            if (curr > max_h) {
                max_h = curr;
                max_r = i;
            }
        }
        int left = -1, right = -1;
        for (int i = 0 ; i < m ; i ++) {
            if (a[max_r][i] == 1 && left == -1) {
                left = i;
            }
            if (a[max_r][i] == 0 && left != -1) {
                // cout << " check" << endl;
                right = i-1;
                break;
            }
        }
        if (right == -1) right = m-1;
        // cout << left << " " << right << endl;
        cout << max_r+1 << " " << (left+right)/2+1 << "\n";
    }
}
