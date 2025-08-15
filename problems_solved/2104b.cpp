/**
 *    Author: Saksham Rathi
 *    Created: Fri Aug 15 10:01:12 IST 2025
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
    vector<int> prefix_max(n, 0), suffix_sum(n, 0);
    prefix_max[0] = a[0];
    suffix_sum[n-1] = a[n-1];
    for (int i = 1 ; i < n ; i ++) prefix_max[i] = max(prefix_max[i-1], a[i]);
    for (int i = n - 2 ; i >= 0 ; i --) suffix_sum[i] = suffix_sum[i+1] + a[i];
    
    for (int k = 1 ; k <= n ; k ++) {
        // cout << " hello " << k << endl;
        if (k == n) cout << suffix_sum[0] << " ";
        else cout << suffix_sum[n-k] + max(prefix_max[n-k-1] - a[n - k], 0LL) << " ";
    }
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
