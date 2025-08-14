/**
 *    Author: Saksham Rathi
 *    Created: Wed Aug 13 16:56:46 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
vector<int> a, d;
vector<vector<int>> dp;

int gcd(int x, int y) {
    if (y == 0) return x;
    if (x < y) return gcd(y, x);
    if (x%y ==0) return y;
    return gcd(x%y, y);
}

int findans(int L, int R) {
    // for (int i = 0 ; i )
    int K = 19;
    int g = 0;
    // cout << L << " " << R << endl;
    for (int i = K; i >= 0; i--) {
        if ((1 << i) <= R - L + 1) {
            // cout << i << " " << L << " hello " << dp[L][i] << endl;
            g = gcd(g, dp[L][i]);
            L += 1 << i;
        }
    }
    return g;
}

void solve() {
    d.clear();
    int n, q;
    cin >> n >> q;
    a.resize(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    for (int i = 0 ; i < n - 1 ; i++) d.push_back(abs(a[i] - a[i+1]));
    dp.resize(n + 10, vector<int>(20, 0));
    for (int i = 0 ; i < n - 1 ; i++) dp[i][0] = d[i];
    for (int i = 1 ; i < 20 ; i ++) {
        for (int j = 0 ; j < n - 1 ; j ++) {
            if ((j + (1<<(i-1))) < n - 1) dp[j][i] = gcd(dp[j][i-1], dp[j + (1<<(i-1))][i-1]);
            else break;
        }
    } 
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l == r) {cout << "0 "; continue;}
        l--;
        r-= 2;
        cout << findans(l, r) << " ";
    }
    cout << "\n";
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
