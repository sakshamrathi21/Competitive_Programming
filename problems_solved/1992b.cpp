/**
 *    Author: Saksham Rathi
 *    Created: Thu Jul 11 20:15:25 IST 2024
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
        vector<int> a(k);
        int m = -1, tot = 0;
        for (int i = 0 ; i < k ; i ++) {
            cin >> a[i];
            m = max(m, a[i]);
            tot += a[i];
        }
        cout << (tot-m-k+1)+(tot-m) << "\n";

    }
}
