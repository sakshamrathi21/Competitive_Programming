/**
 *    Author: Saksham Rathi
 *    Created: Fri Jun 21 23:03:38 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> dp;
string s;

int cal(int left, int right) {
    if (dp[left][right] != -1) return dp[left][right];
    if (left > right) return dp[left][right] = 0;
    if (left == right) return dp[left][right] = 1;
    int m = cal(left+1, right)+1;
    for (int i = left+1; i <= right ; i ++) {
        if (s[i] == s[left]) m = min(m, cal(left+1, i-1)+cal(i, right));
    }
    dp[left][right] = m;
    return m;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cin >> s;
    dp.assign(n, vector<int>(n, -1));
    cout << cal(0, n-1) << "\n";
}
