/**
 *    Author: Saksham Rathi
 *    Created: Thu Aug 28 23:32:48 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int curr_len = 0;
    for (int i = 0 ; i < n ; i ++) {
        if (s[i] == '0') curr_len = 0;
        else curr_len ++;
        if (curr_len >= k) {
            cout << "NO\n";
            return;
        }
    }
    if (curr_len >= k) {
        cout << "NO\n";
        return;
    }
    int x = 1;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i ++) {
        if (s[i] == '1') a[i] = x++;
    }
    for (int i = 0 ; i < n ; i ++) {
        if (s[i] == '0') a[i] = x++;
    }
    cout << "YES\n";
    for (auto y : a) cout << y << " ";
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
