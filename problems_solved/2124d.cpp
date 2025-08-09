/**
 *    Author: Saksham Rathi
 *    Created: Sat Aug  9 15:02:59 IST 2025
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
    vector<int> b = a;
    sort(b.begin(), b.end());
    int x = b[k-1];
    vector<int> c;
    for (int i = 0 ; i < n ; i ++) if (a[i] <= x) c.push_back(a[i]);
    int l = 0, r = c.size() - 1;
    int rem_ind = 0;
    while (l < r) {
        // cout << l << " " << r << " " << a[l] << " " << a[r] << " " << x << endl;
        if (c[l] == c[r]) {l++; r--; continue;}
        if (c[l] < x && c[r] < x) {cout << "NO\n"; return;}
        if (c[l] == x) {rem_ind++; l ++;}
        if (c[r] == x) {rem_ind++; r--;}
    }
    if (c.size() - rem_ind >= k-1) cout << "YES\n";
    else cout << "NO\n";
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
