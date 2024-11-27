/**
 *    Author: Saksham Rathi
 *    Created: Thu Jun  6 08:00:14 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    vector<int> p(n-1, 0);
    for (int i = 1 ; i < n-1 ; i ++) {
        int pos = (a[i]<= a[i-1]) && (a[i+1] <= a[i]);
        p[i] = p[i-1]+pos;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (l == r) cout << 1 << "\n";
        else {
            cout << (r-l+1)+p[l]-p[r-1] << "\n";
        }
    }
}
