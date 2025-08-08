/**
 *    Author: Saksham Rathi
 *    Created: Fri Aug  8 22:56:32 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    string s;
    cin >> s;
    int n = 0, t = 0, f = 0;
    for (auto c : s) {
        if (c == 'N') n++;
        else if (c == 'T') t++;
        else if (c == 'F') f++;
        else cout << c;
    }
    for (int i = 0 ; i < t ; i ++) cout << "T";
    for (int i = 0 ; i < n ; i ++) cout << "N";
    for (int i = 0 ; i < f ; i ++) cout << "F";
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
