/**
 *    Author: Saksham Rathi
 *    Created: Fri Aug  1 08:39:33 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
        if (a[i] == 0) a[i] = 1;
        sum += a[i];
    }
    cout << sum << "\n";
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
