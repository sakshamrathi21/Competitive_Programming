/**
 *    Author: Saksham Rathi
 *    Created: Thu Aug 21 23:08:48 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<int> s(16, 0), t(16, 0);
    s[1] = 45;
    t[1] = 9;
    for (int i = 2 ; i <= 14 ; i ++) {
        s[i] = s[i-1]*9 + 45*pow(10, i -1);
        t[i] = pow(10, i - 1)*i*9;
    }
    int tot = 0;
    int i = 1;
    for ( ; i <= 14 ; i ++) {
        if (n >= t[i]) {
            n -= t[i];
            tot += s[i];
        }
        break;
    }
    int dlen = i;
    while (true) {
        int x = n / pow(10, i - 1);
        tot += x*t[i-1] + x*(x+1)*pow(10, i - 1)/2;
        
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
