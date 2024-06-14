/**
 *    Author: Saksham Rathi
 *    Created: Fri Jun 14 09:16:34 IST 2024
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
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        vector<int> d;
        for (int i = 0 ; i < n-1 ; i ++ ) d.push_back(abs(a[i]-a[i+1]));
        sort(d.begin(), d.end());
        int cnt = 0;
        for (int i = 0 ; i < n-k ;  i ++) cnt += d[i];
        cout << cnt << "\n";

    }
}
