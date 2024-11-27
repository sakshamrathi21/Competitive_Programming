#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[20][10][2][2];

int solve(string& number, int n, int x, bool leading_zeros, bool tight) {
    if (n == 0 ) return 1;
    if (x != -1 && dp[n][x][leading_zeros][tight] != -1) return dp[n][x][leading_zeros][tight];
    int lb = 0;
    int ub = tight ? (number[number.length()-n] - '0') : 9;

    int answer = 0;

    for (int dig = lb ; dig <= ub ; dig ++) {
        if (dig == x && leading_zeros == 0) continue;
        answer += solve(number, n-1, dig, (leading_zeros && dig == 0), tight & (dig == ub));
    }
    return dp[n][x][leading_zeros][tight] = answer;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    string A = to_string(a-1);
    string B = to_string(b);
    int ans1 = solve(B, B.length(), -1, 1, 1);
    memset(dp, -1, sizeof(dp));
    int ans2 = solve(A, A.length(), -1, 1, 1);
    cout << ans1 - ans2;
    return 0;
}
