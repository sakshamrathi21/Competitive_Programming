/**
 *    Author: Saksham Rathi
 *    Created: Sat Aug  9 15:43:54 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

int gcd(int x, int y) {
    if (y == 0) return x;
    if (x < y) return gcd(y, x);
    if (x%y ==0) return y;
    return gcd(x%y, y);
}

int lm(int x, int y) {
    return (x*y/gcd(x, y));
}

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> b[i];
    }
    vector<int> a = b;
    vector<int> gs;
    for (int i = n - 1 ; i >= 1 ; i --) {
        if (gcd(a[i],  a[i-1]) != a[i-1]) {
            int g = gcd(a[i], a[i-1]);
            gs.push_back(a[i-1]/g);
            a[i-1] = g;
        }
    }
    if (gs.size() != 0) {
        int common_g = gs[0];
        for (int i = 1 ; i < gs.size() ; i ++) common_g = lm(common_g, gs[i]);
        cout << common_g << "\n";
    }
    else {
        cout << "1\n";
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
