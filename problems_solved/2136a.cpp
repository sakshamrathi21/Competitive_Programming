/**
 *    Author: Saksham Rathi
 *    Created: Thu Aug 28 20:34:42 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

bool poss(int a, int b) {
    if (a < b) return poss(b, a);
    // cout << a << " " << b << "\n";
    if (b == 0 && a < 3) return true;
    if (b == 0) return false;
    
    if (a/(b + 1) >= 2 && a != (b + 1)*2) return false;
    return true;
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    // cout << a << " " << b << " " << c << " " << d << "\n";
    if (poss(a, b) && poss(c - a, d - b)) cout << "YES\n";
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
