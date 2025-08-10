/**
 *    Author: Saksham Rathi
 *    Created: Sun Aug 10 22:33:50 IST 2025
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
        if (i % 2) a[i] = 3;
        else a[i] = -1;
    }
    if (n % 2 == 0) a[n - 1] = 2;
    for (auto x : a) cout << x << " ";
    cout << "\n";
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
