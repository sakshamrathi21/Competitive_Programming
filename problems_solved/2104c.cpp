/**
 *    Author: Saksham Rathi
 *    Created: Fri Aug 15 10:07:36 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

bool check(string & s, char c) {
    int n = s.length();
    if (n == 2) return s[0] == c;
    if (s[n-1] == s[n-2] && s[n-1] == c) return true;
    if (s[n-1] == s[0]  && s[n-1] == c) return true; 
    for (int i = 0 ; i < n - 1 ; i ++) if (s[i] != c) return false;
    return true;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (check(s, 'A')) cout << "Alice\n";
    else cout << "Bob\n";
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
