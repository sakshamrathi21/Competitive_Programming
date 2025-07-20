/**
 *    Author: Saksham Rathi
 *    Created: Sat Jul 19 20:52:40 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve()
{
    int n, m;
    cin >> n >> m;
    if ( n == 1 || m == 1 ) cout << "NO\n";
    else if (n == 2 && m == 2) cout << "NO\n";
    else cout << "YES\n";
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
