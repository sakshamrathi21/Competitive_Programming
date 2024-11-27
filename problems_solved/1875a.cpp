/**
 *    Author: Saksham Rathi
 *    Created: Fri Jun  7 18:26:16 IST 2024
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
        int x, y, n;
        cin >> x >> y >> n;
        vector<int> a(n);
        int total = y;
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
            total += min(x-1, a[i]);
        }
        cout << total << "\n";
    }   
}
