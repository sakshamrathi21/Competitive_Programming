/**
 *    Author: Saksham Rathi
 *    Created: Tue Jul 23 10:25:00 IST 2024
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
        bool b1 = false, b2 = false;
        int ans = 0;
        for (int i = 0 ; i < n ; i ++) {
            if (!b1 && !b2) {
                if (a[i] == 0) continue;
                ans++;
                if (a[i] <= 2) b1 =true;
            }
            else if (b1) {
                b1 = false;
                if (a[i] <= 2) continue;
                ans ++ ;
                if (a[i] <= 4) b2 = true;
            }
            else {
                b2 = 0;
                if (a[i] ==0) continue;
                ans++;
                if (a[i] <= 4) b1 =true;
            }
        }
        cout << ans << "\n";
    }
}
