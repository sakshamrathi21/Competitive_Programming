/**
 *    Author: Saksham Rathi
 *    Created: Mon Jul 21 19:42:59 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve()
{
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    if (n%2) {cout << l << "\n"; return;}
    int p = 1;
    while (p < l) p*=2;
    if (p == l) p*=2;
    // cout << " hello " << p << " " << endl;
    if (p > r || n == 2) {cout << "-1\n"; return;}
    if (n-k < 2) cout << p;
    else cout << l;
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
