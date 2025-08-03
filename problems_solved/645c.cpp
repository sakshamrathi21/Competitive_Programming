/**
 *    Author: Saksham Rathi
 *    Created: Sun Aug  3 18:59:36 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

string s;

int nexte(int i) {
    i += 1;
    while (i < s.length() && s[i] == '1') i += 1;
    return i;
}

void solve() {
    int n, k;
    cin >> n >> k;
    
    cin >> s;
    vector<int> o;
    int l = -1;
    l = nexte(l);
    int m = l, r = l;
    for (int i = 0 ; i < k ; i ++ ) {
        r = nexte(r);
    }
    int mind = n;
    while (r < n) {
        while (max(nexte(m)-l, r-nexte(m)) <= max(m-l, r-m)) m = nexte(m);
        mind = min(mind, max(m-l, r-m));
        l = nexte(l);
        r = nexte(r);
    }
    cout << mind << '\n';
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
