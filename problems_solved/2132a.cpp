/**
 *    Author: Saksham Rathi
 *    Created: Thu Aug 21 22:30:23 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n, m;
    cin >> n;
    string a, b, c;
    cin >> a;
    cin >> m;
    cin >> b >> c;
    for (int i = 0; i < m ; i ++) {
        if (c[i] == 'D') {
            a.push_back(b[i]);
        }
        else a.insert(a.begin(), b[i]);
    }
    cout << a << "\n";
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
