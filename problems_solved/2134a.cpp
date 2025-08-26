/**
 *    Author: Saksham Rathi
 *    Created: Tue Aug 26 21:01:04 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (n % 2 != b% 2) cout << "NO\n";
    else {
        if (b >= a) cout << "YES\n";
        else if (n% 2 != a% 2) cout << "NO\n";
        else cout << "YES\n";
    }
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
