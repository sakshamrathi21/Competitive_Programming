/**
 *    Author: Saksham Rathi
 *    Created: Mon Jun 10 18:52:09 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        // reverse(a.begin(), a.end());
        vector<int> d(n+1, 0);
        while (q--) {
            int l, r;
            cin >> l >> r;
            d[l-1]++;
            d[r]--;
        }
        vector<int> b(n, 0);
        b[0] = d[0];
        for (int i = 1 ; i < n ; i ++) {
            b[i] = b[i-1]+d[i];
        }
        sort(b.begin(), b.end());
        int cnt = 0;
        for (int i = 0 ; i < n ; i ++) cnt+=a[i]*b[i];
        cout << cnt;
    }
}
