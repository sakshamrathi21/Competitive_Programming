/**
 *    Author: Saksham Rathi
 *    Created: Fri Aug  8 23:20:11 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

int gcd(int x, int y) {
    if (y == 0) return x;
    if (x < y) return gcd(y, x);
    if (x%y ==0) return y;
    return gcd(x%y, y);
}

void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    int g = gcd(a, b);
    if (a/g <= k && b/g <= k) cout << "1\n";
    else cout << "2\n";
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
