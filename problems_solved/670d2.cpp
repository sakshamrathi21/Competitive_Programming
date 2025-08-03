/**
 *    Author: Saksham Rathi
 *    Created: Sun Aug  3 18:15:44 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

bool possible(vector<int> & a, vector<int>&b, int k, int c) {
    int req = 0;
    for (int i = 0 ;i < a.size() ; i ++) req += a[i]*c > b[i] ? a[i]*c - b[i] : 0;
    if (req > k) return false;
    return true;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    for (int i = 0 ; i < n ; i ++) {
        cin >> b[i];
    }
    int l = 0, r = (b[0]+k)/a[0] + 1;
    while (r - l > 1) {
        int m = midpoint(l, r);
        if (possible(a, b, k, m)) l = m;
        else r = m;
    }
    cout << l << "\n";
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
