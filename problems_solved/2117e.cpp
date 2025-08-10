/**
 *    Author: Saksham Rathi
 *    Created: Sun Aug 10 09:06:25 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0 ; i < n ; i ++) cin >> a[i];
    for (int i = 0 ; i < n ; i ++) cin >> b[i];
    int ans = 0;
    set<int> lrset;
    for (int i = n - 1 ; i >= 0 ; i --) {
        if (a[i] == b[i] || (lrset.find(a[i]) != lrset.end()) || (lrset.find(b[i]) != lrset.end())) ans = i + 1;
        if (i < n - 1 && (a[i] == a[i+1] || b[i] == b[i+1])) ans = i + 1;
        if (i < n - 1) {
            lrset.insert(a[i+1]);
            lrset.insert(b[i+1]);
        }
        if (ans != 0) break;
    }
    cout << ans << "\n";
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
