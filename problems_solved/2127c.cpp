/**
 *    Author: Saksham Rathi
 *    Created: Fri Aug  8 11:07:36 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    vector<pair<int, int>> inter;
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    int value = 0;
    for (int i = 0 ; i < n ; i ++) {
        cin >> b[i];
        inter.push_back(make_pair(min(a[i], b[i]), max(a[i], b[i])));
        value += abs(b[i] - a[i]);
    }
    sort(inter.begin(), inter.end());
    // for (int i = 0 ; i < n ; i ++) cout << inter[i].first << " " << inter[i].second << endl;
    // cout << " hello " << value << endl;
    int min_diff = 2*MOD;
    for (int i = 0 ; i < n - 1 ; i ++) {
        if (inter[i].second >= inter[i+1].first) {cout << value << "\n"; return;}
        min_diff = min(min_diff, inter[i+1].first - inter[i].second);
    }
    cout << value + 2*min_diff << "\n";
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
