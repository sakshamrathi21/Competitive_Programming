/**
 *    Author: Saksham Rathi
 *    Created: Fri Aug  1 08:51:21 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve()
{
    int n, s;
    cin >> n >> s;
    vector<int> c(3, 0);
    vector<int> a(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
        c[a[i]]++;
    }
    int sum = c[1] + c[2] * 2;
    if ((s-sum) > 1 || (s-sum) == 0) {
        cout << "-1\n";
        return;
    }
    for (int i = 0 ; i < c[0] ; i ++) cout << "0 ";
    for (int i = 0 ; i < c[2] ; i ++) cout << "2 ";
    for (int i = 0 ; i < c[1] ; i ++) cout << "1 ";
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
