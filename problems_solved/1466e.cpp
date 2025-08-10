/**
 *    Author: Saksham Rathi
 *    Created: Sun Aug 10 08:29:21 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
const int M = 61;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    vector<int> sum(M, 0);
    for (int j = 0 ; j < M ; j ++) for (int i = 0 ; i < n ; i ++) sum[j] += ((a[i] & (1LL << j)) > 0);
    int tot = 0;
    for (int j = 0 ; j < n ; j ++) {
        int prod1 = 0, prod2 = 0;
        for (int c = 0 ; c < M ;c ++) {
            int f = ((1LL << c) & a[j]) > 0;
            prod1 += sum[c]*f*((1LL<<c)%MOD); 
            prod1 %= MOD;
            prod2 += ((1LL<<c)%MOD)*(n - (1-f)*(n-sum[c]));
            prod2 %= MOD;
        }
        tot += (prod1 * prod2)%MOD;
        tot %= MOD;
    }
    cout << tot << "\n";
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
