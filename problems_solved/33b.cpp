/**
 *    Author: Saksham Rathi
 *    Created: Tue Aug  5 09:29:55 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 100000007;

void solve() {
    string s, t;
    cin >> s >> t;
    vector<vector<int>> dp(26, vector<int>(26, MOD));
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i ++) {
        char a, b;
        int c;
        cin >> a >> b >> c;
        dp[a - 'a'][b - 'a'] = min(dp[a - 'a'][b - 'a'], c);
    }
    for (int k = 0 ; k < 26 ; k ++) {
        for (int i = 0 ; i < 26 ; i ++) {
            for (int j = 0 ; j < 26 ; j ++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }    
    }
    if (s.length() != t.length()) {
        cout << "-1\n";
        return;
    }
    int cost = 0;
    string res;
    for (int i = 0 ; i < s.length() ; i ++ ) {
        if (s[i] == t[i]) {res += s[i]; continue;}
        char min_car = 'a';
        int min_cost = MOD;
        for (int j = 0 ; j < 26 ; j ++) {
            if (dp[s[i] - 'a'][j] + dp[t[i] - 'a'][j] < min_cost) {min_car = j + 'a'; min_cost = dp[s[i] - 'a'][j] + dp[t[i] - 'a'][j];}
        }
        if (dp[s[i] - 'a'][t[i] - 'a'] < min_cost) {min_car = t[i]; min_cost = dp[s[i] - 'a'][t[i] - 'a'];}
        if (dp[t[i] - 'a'][s[i] - 'a'] < min_cost) {min_car = s[i]; min_cost = dp[t[i] - 'a'][s[i] - 'a'];}
        if (min_cost == MOD) {
            cout << "-1\n";
            return;
        }
        cost += min_cost;
        res += min_car;
    }
    cout << cost << "\n" << res << "\n";
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
