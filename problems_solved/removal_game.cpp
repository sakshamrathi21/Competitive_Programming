#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    ll arr[n];
    for (int i = 0 ; i < n ; i ++ ) {
        cin >> arr[i];
    }

    ll dp[n][n];

    for (int i = 0 ; i < n ; i ++ ) {
        for (int j = 0 ; j < n ; j ++ ) {
            dp[i][j] = 0;
        }
    }

    ll sum = 0;

    for (int i = 0 ; i < n ; i ++) {
        sum += arr[i];
    }

    for (int i = n-1 ; i >= 0 ; i -- ) {
        for (int j = i ; j < n ; j ++ ) {
            if (i == j) dp[i][j] = arr[i];
            else {
                dp[i][j] = max(arr[i] - dp[i+1][j], arr[j] - dp[i][j-1]);
            }
        }
    }

    cout << (sum + dp[0][n-1]) / 2 << '\n';
}
