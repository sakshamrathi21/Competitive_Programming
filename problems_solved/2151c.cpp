/**
 *    Author: Saksham Rathi
 *    Created: Fri Sep 26 09:57:44 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<int> a(2*n);
    for (int i = 0 ; i < 2*n ; i ++) {
        cin >> a[i];
    }
    vector<int> psum(2*n + 1, 0), asum(2*n + 1, 0);
    for (int i = 0 ; i < 2*n ; i ++) {
        psum[i + 1] = psum[i] + a[i];
        asum[i + 1] = asum[i] + a[i] * (i % 2 == 0 ? 1 : -1);
    }
    for (int k = 1 ; k <= n ; k ++) {
        int ans = 0;
        ans -= psum[k] - psum[0];
        ans += psum[2*n] - psum[2*n - k];
        ans += (asum[2*n - k] - asum[k])*(k % 2 == 0 ? 1 : -1);
        cout << ans << " ";
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
