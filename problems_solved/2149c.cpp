/**
 *    Author: Saksham Rathi
 *    Created: Thu Sep 25 22:52:54 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n, k;
    cin >> n >> k;
    int count = 0;
    set<int> s;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
        if (a[i] < k) s.insert(a[i]);
        count += (a[i] == k);
    }
    int req = k - s.size();
    cout << max(req, count) << "\n";
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
