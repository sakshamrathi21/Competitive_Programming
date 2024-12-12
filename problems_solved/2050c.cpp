/**
 *    Author: Saksham Rathi
 *    Created: Thu Dec 12 19:36:37 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        vii dp(n + 1, vi(9, 0));
        int sum = 0;
        for (int i = 0 ; i < n ; i ++ ) {
            sum += (s[i] - '0');
            sum %= 9;
        }
        dp[0][0] = 1;
        for (int i = 0 ; i < n ; i ++ ) {
            for (int j = 0 ; j < 9 ; j ++ ) {
                if (dp[i][j]) {
                    dp[i + 1][j] = 1;
                    if (s[i] == '2' ||  s[i] == '3') { int c = (s[i] - '0'); dp[i + 1][(j + (c*c - c)) % 9] = 1;}
                }
                // cout << dp[i+1][j] << " hello " << endl;
            }
        }
        if (dp[n][(9-sum)%9]) cout << "YES\n";
        else cout << "NO\n";
    }
}
