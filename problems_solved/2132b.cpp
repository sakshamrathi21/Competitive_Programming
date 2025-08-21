/**
 *    Author: Saksham Rathi
 *    Created: Thu Aug 21 22:33:56 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<int>x;
    int curr_num = 1;
    for (int i = 1 ; i <= 18 ; i ++) {
        curr_num *= 10LL;
        int d = curr_num + 1ll;
        // cout << d << " " << n % d << " hello\n";
        if (n % d == 0) x.push_back(n/d);
    }
    reverse(x.begin(), x.end());
    cout << x.size() << "\n";
    if (x.size()) {
        for (auto y : x) cout << y << " ";
        cout << "\n";
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
