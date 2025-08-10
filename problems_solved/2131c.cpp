/**
 *    Author: Saksham Rathi
 *    Created: Sun Aug 10 22:46:01 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n, k;
    cin >> n >> k;
    // vector<int> s(n), t(n);
    map<int, int> p;
    // set<int> pr;
    for (int i = 0 ; i < n ; i ++) {
        int x;
        cin >> x;
        p[x % k]++;
        // pr.insert(x % k);
    }
    for (int i = 0 ; i < n ; i ++) {
        int x;
        cin >> x;
        p[x % k]--;
        // pr.insert(x % k);
    }
    for (auto t : p) {
        if (t.second + p[k - t.first] != 0) {cout << "NO\n"; return;}
    }
    cout << "YES\n";
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
