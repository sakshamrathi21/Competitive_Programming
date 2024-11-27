/**
 *    Author: Saksham Rathi
 *    Created: Fri Jun 21 08:50:41 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e9;

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        int ans = 0;
        for (int mx = 0 ; mx < 31 ; mx++) {
            int cur = 0, best = 0;
            for (int i = 0 ; i < n ; i ++) {
                int val = a[i];
                if (a[i] > mx) val = -INF;
                cur += val;
                best = min(best, cur);
                ans = max(ans, (cur-best)-mx);
            }
        }
        cout << ans << "\n";
    }
}
