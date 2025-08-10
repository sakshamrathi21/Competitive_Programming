/**
 *    Author: Saksham Rathi
 *    Created: Sun Aug 10 22:29:08 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    for (int i = 0 ; i < n ; i ++) cin >> b[i];
    int sum = 1;
    for (int i = 0 ; i < n ; i ++) {
        if (a[i] > b[i]) sum += (a[i] - b[i]);
    }
    cout << sum << "\n";
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
