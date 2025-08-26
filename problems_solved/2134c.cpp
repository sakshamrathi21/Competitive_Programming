/**
 *    Author: Saksham Rathi
 *    Created: Tue Aug 26 22:31:20 IST 2025
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
    vector<int> d(n, 0);
    for (int i = 1 ; i < n ; i += 2) {
        if (i == n - 1) {
            d[i - 1] = max(d[ i - 1], a[ i - 1] - a[i]);
            break;
        }
        int diff = a[i-1] + a[i + 1] - a[i];
        diff -= d[i - 1];
        if (diff <= 0) continue;
        d[i + 1] = min(diff, a[i + 1]);
        diff -= d[i + 1];
        d[i - 1] += diff;
    }
    int s = 0;
    for (auto x : d) s += x;
    cout << s << "\n";
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
