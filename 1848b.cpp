/**
 *    Author: Saksham Rathi
 *    Created: Fri Jun 14 08:25:17 IST 2024
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
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        vector<vector<int>> vv(k+1);
        vector<int> prev(k+1, -1);
        for (int i = 0 ; i < n ; i ++) {
            
            vv[a[i]].push_back(i-prev[a[i]]-1);
            // cout << a[i] << " hello " << vv[a[i]][0] << endl;
            prev[a[i]] = i;
        }
        // cout << vv[1][0] << " hello " << endl;
        int m1 = LLONG_MAX;
        for (int i = 0 ; i <= k ; i ++) {
            if (prev[i] == -1) continue;
            vv[i].push_back(n-prev[i]-1);
            
            sort(vv[i].begin(), vv[i].end());
            int m = vv[i][vv[i].size()-1];
            int hm = max((m-1)/2, (m-1)-(m-1)/2);
            // cout << i << hm << vv[i][vv[i].size()-2] << endl;
            hm = max(hm, vv[i][vv[i].size()-2]);
            // cout << i << hm << endl;
            m1 = min(hm, m1);
        }
        cout << m1 << "\n";
    }
}
