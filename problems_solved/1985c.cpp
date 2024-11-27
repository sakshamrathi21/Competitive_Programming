/**
 *    Author: Saksham Rathi
 *    Created: Tue Jun 11 20:17:06 IST 2024
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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        int curr_sum = 0;
        int curr_max = -1;
        int gp = 0;
        for (int i = 0 ; i < n ; i ++) {
            curr_sum += a[i];
            curr_max = max(curr_max, a[i]);
            // cout << curr_sum << " hello " << curr_max << endl;
            if (curr_sum-curr_max == curr_max) gp++;
        }
        cout << gp << "\n";
    }
}
