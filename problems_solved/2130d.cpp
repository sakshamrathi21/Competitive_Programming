/**
 *    Author: Saksham Rathi
 *    Created: Fri Aug  1 09:58:06 IST 2025
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
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 0 ; i < n ; i ++) {
        int lb = 0, rb = 0;
        for (int j = 0 ; j < i ; j ++) if (a[j] > a[i]) lb++;
        for (int j = i + 1 ; j < n ; j ++) if (a[j] > a[i]) rb++;
        sum += min(lb, rb);
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
