/**
 *    Author: Saksham Rathi
 *    Created: Thu Jun  6 20:03:12 IST 2024
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
        int mm = LLONG_MAX;
        for (int i = 0 ; i < n-1 ; i ++) {
            mm = min(max(a[i], a[i+1]), mm);
        }
        cout << mm-1 << "\n";
    }
}
