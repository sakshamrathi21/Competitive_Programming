/**
 *    Author: Saksham Rathi
 *    Created: Mon Jul 29 15:10:08 IST 2024
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
        int mx = -1;
        for (int i = 0 ; i < n ; i += 2) mx = max(mx, a[i]);
        cout << mx << "\n";
    }
}
