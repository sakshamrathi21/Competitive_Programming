/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun  8 16:04:36 BST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    int min_cost = 1e15;
    int left = 0;
    for (int i = 1 ; i < n ; i ++) {
        if (a[i] == a[i-1]) continue;
        else {
            min_cost = min(min_cost, left*a[left] + a[left]*(n-i));
            // cout << left << " " << right << " " << min_cost << "\n";
            left = i;
        }
    }
    if (left < n) {
        min_cost = min(min_cost, left*a[left]);
    }
    min_cost = min(min_cost, (n-1)*a[n-1]);
    cout << min_cost << "\n";
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
