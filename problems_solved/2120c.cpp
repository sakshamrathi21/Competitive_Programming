/**
 *    Author: Saksham Rathi
 *    Created: Fri Jul 18 10:01:29 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve()
{
    int n, m;
    cin >> n >> m;
    if (m > n*(n+1)/2 || m < n) {cout << -1 << "\n"; return;}
    int d = m - n;
    vector<int> ans;
    int curr = 0;
    set<int> vis;
    for (int i = n - 1 ;i >= 0 ; i --) {
        if (curr + i <= d) {ans.push_back(i+1); curr += i; vis.insert(i+1);}
    }
    if (ans.back() != 1) ans.push_back(1);
    for (int i = 2 ; i <= n ; i ++) {
        if (vis.find(i) == vis.end()) ans.push_back(i);
    }
    cout << ans[0] << "\n";
    for (int i = 1 ; i < ans.size() ; i ++) {
        cout << ans[i-1] << " " << ans[i] << "\n";
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
