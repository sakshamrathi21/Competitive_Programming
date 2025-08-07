/**
 *    Author: Saksham Rathi
 *    Created: Thu Aug  7 09:10:44 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

int n;
vector<int> a;
map<pair<int, int>, int> dp;

int calc_dp(int last_pos, int action) {
    if (last_pos == -1) return 0;
    pair<int, int> pf = make_pair(last_pos, action);
    if (dp.find(pf) != dp.end()) return dp[pf];
    if (a[last_pos] == 0 && action > 0) return MOD;
    if (a[last_pos] == 1 && action == 2) return MOD;
    if (a[last_pos] == 2 && action == 1) return MOD;
    if (action == 0) dp[pf] = 1 + min(calc_dp(last_pos - 1, 0), min(calc_dp(last_pos - 1, 1), calc_dp(last_pos - 1, 2)));
    if (action == 1) dp[pf] = min(calc_dp(last_pos - 1, 0), calc_dp(last_pos - 1, 2));
    if (action == 2) dp[pf] = min(calc_dp(last_pos - 1, 0), calc_dp(last_pos - 1, 1));
    // cout << last_pos << " " << action << " " << dp[pf] << endl;
    return dp[pf];
}

void solve() {
    cin >> n;
    a.resize(n);
    for (int i = 0 ; i < n ; i ++) cin >> a[i];
    cout << min(calc_dp(n - 1, 0), min(calc_dp(n - 1, 1), calc_dp(n - 1, 2))) << "\n";
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
