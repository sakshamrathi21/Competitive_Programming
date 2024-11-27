#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    // cout << "HELLO" << endl;
    if (n%4 == 2 || n%4 == 1) {
        cout << 0 << '\n';
        return 0;
    }
    vector<vector<int>> dp(n + 1, vector<int>(n*(n+1)/2, 0));

    dp[0][0]  = 1;

    for (int i = 1 ; i <= n ; i ++ ) {
        for (int j = 0 ; j < i*(i+1)/2 ; j ++ ) {
            (dp[i][j] = dp[i-1][j])%=1000000007;
            if (j -i >= 0) {
                (dp[i][j] += dp[i-1][j-i])%=1000000007;
            }
        }
    }

    cout << dp[n][n*(n+1)/4] << '\n';
}
