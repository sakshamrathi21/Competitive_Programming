/**
 *    Author: Saksham Rathi
 *    Created: Wed Aug 20 14:24:00 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

int low(int x, int n, int m) {
    if (x == 0) return x;
    // cout << x << " " << n << " " << m << " low" << endl;
    if (n == 0 && m == 0) return x;
    if (x == 1 && m > 0) return low(x, n, 0);
    if (m > 0) {
        x = (x % 2) ? (x/2 + 1) : x/2;
        return low(x, n, m - 1);
    }
    return low(x/2, n - 1, m);
}

int high(int x, int n, int m) {
    if (x == 0) return x;
    if (x == 1 && m > 0) return high(x, n, 0);
    if (n == 0 && m == 0) return x;
    if (n > 0) return high(x/2, n - 1, m);
    x = (x % 2) ? (x/2 + 1) : x/2;
    return high(x, n, m - 1);
}

void solve() {
    int x, n, m;
    cin >> x >> n >> m;
    cout << low(x, n, m) << " " << high(x, n, m) << "\n";
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
