/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun 16 14:25:24 IST 2024
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
        vector<int> a(n-1);
        int m = -1;
        for (int i = 0 ; i < n-1 ; i ++) {
            cin >> a[i];
            m = max(m, a[i]);
        }
        int x;
        cin >> x;
        cout << m+x << "\n";
    }
}
