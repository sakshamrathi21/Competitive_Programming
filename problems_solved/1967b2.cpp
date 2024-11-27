/**
 *    Author: Saksham Rathi
 *    Created: Sun Jul 28 16:29:14 IST 2024
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
        int cnt = 0;
        for (int p = 1 ; p*p <= n ; p ++) {
            for (int q = 1 ; q*q <= m ; q ++ ) {
                cnt += min(n/p, m/q)/(p+q);
            }
        }
        cout << cnt << "\n";
    }
}
