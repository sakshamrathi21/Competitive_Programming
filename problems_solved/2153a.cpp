/**
 *    Author: Saksham Rathi
 *    Created: Fri Oct 10 22:45:56 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    cout << s.size() << "\n";
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
