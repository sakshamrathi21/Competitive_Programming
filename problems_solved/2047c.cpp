/**
 *    Author: Saksham Rathi
 *    Created: Tue Dec  3 20:52:39 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;


signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> a(2, vector<int>(n));\
        for (int i = 0 ; i < 2 ; i ++ ) {
            for (int j = 0 ; j < n ; j ++ ) {
                cin >> a[i][j];
            }
        }
        // vector<pair<int, int>> diff;
        int max_ind = 0;
        int sum = 0;
        for (int i = 0 ; i < n ; i ++) {
            sum += max(a[0][i], a[1][i]);
            if (min(a[0][i], a[1][i]) > min(a[0][max_ind], a[1][max_ind])) max_ind = i;
        }
        sum += min(a[0][max_ind], a[1][max_ind]);
        cout << sum << "\n";
    }
}
