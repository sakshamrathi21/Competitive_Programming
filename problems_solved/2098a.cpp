/**
 *    Author: Saksham Rathi
 *    Created: Mon Aug 18 11:06:30 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> f(10, 0);
    for (int i = 0 ; i < n ; i ++) f[s[i] - '0']++;
    for (int i = 0 ; i < n ; i ++) {
        int j = 10 - i - 1;
        while (f[j] == 0) j++;
        cout << j;
        f[j]--;
    }
    for (int i = 0 ; i < n ; i ++) for (int j = 0 ; j < f[i] ; j ++) cout << i;
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
