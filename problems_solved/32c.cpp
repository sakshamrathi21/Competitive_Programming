/**
 *    Author: Saksham Rathi
 *    Created: Wed Aug  6 08:11:06 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n, m, s;
    cin >> n >> m >> s;
    int rem1 = n % s, rem2 = m % s;
    if (rem1 == 0) rem1 += s;
    if (rem2 == 0) rem2 += s;
    int prod1 = (n / s + 1)* rem1, prod2 = (m/s + 1)*rem2;
    if (prod1 > n) prod1 = n;
    if (prod2 > m) prod2 = m;
    cout << prod1 * prod2 << "\n";
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
