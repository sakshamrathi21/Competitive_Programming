/**
 *    Author: Saksham Rathi
 *    Created: Sat Jun  8 18:08:10 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int tt = 0;
        int m = -1;
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
            m = max(m, a[i]);
            tt += a[i];
        }
        if (m > tt-m) {
            cout << "NO";
            return 0;
        }
        cout << ((tt%2) ? "NO\n" : "YES\n");
    }
}
