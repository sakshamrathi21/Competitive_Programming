/**
 *    Author: Saksham Rathi
 *    Created: Sat Oct  4 10:55:05 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int cnt = 1;
    for (int i = 1 ; i < n ; i ++) {
        if (a[i] != a[i - 1]) cnt ++;
    }
    cout << 2*cnt - 1 << "\n";
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
