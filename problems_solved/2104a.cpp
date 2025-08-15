/**
 *    Author: Saksham Rathi
 *    Created: Fri Aug 15 09:29:59 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int sum = a + b +c;
    if (sum%3 || b > sum/3) {cout << "NO\n"; return;}
    else {cout << "YES\n"; return;}
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
