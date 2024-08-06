/**
 *    Author: Saksham Rathi
 *    Created: Tue Aug  6 21:07:52 IST 2024
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
        int n, s, m;
        cin >> n >> s >> m;
        int mx = -1;
        int l, r;
        cin >> l >> r;
        // m--;
        mx = l-0;
        for (int i = 1 ; i < n ; i ++ ) {
            int l1, r1;
            cin >> l1 >> r1;
            mx = max(mx, l1-r);
            r = r1;
            l = l1;
        }
        mx = max(m-r, mx);
        if (mx >= s) cout << "YES\n";
        else cout << "NO\n";
    }
}
