/**
 *    Author: Saksham Rathi
 *    Created: Mon Aug 18 11:17:56 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int r = -1, l = -1;
    r = a[(n + k)/2];
    if ((n-k) % 2 == 0) l = a[(n - k)/2 - 1];
    else l = a[(n - k)/2];
    cout << r - l + 1 << "\n";
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
