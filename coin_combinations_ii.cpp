#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0 ; i < n ; i ++ ) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    vector<vector<int>> dp(n + 1, vector<int>(x+1, 0));
    // for (int i = 0 ; i < x + 1 ; i ++ ) {
    //     dp[0][i] = 1;
    // }

    // for (int i = 0 ; i <= n ; i ++ ) {
    //     dp[i][0] = 1;
    // }

    dp[0][0] = 1;

    for (int i = 1 ; i <= n ; i ++ ) {
        for (int j = 0 ; j < x + 1 ; j ++ ) {
            (dp[i][j] += dp[i-1][j])%=(1000000007);
            if (j - arr[i-1] >= 0) {
                // cout << i << j;
                (dp[i][j] += dp[i][j - arr[i-1]])%=(1000000007);
                // cout << dp[i][j] << endl;
            }
        }
    }
    cout << dp[n][x] << '\n';
}
