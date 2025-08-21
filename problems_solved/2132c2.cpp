/**
 *    Author: Saksham Rathi
 *    Created: Thu Aug 21 22:41:05 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a;
    int count = 0;
    while (n > 0) {
        a.push_back(n % 3);
        count += (n % 3);
        n /= 3;
    }
    if (count > k) {
        cout << "-1\n";
        return;
    }
    for (int i = a.size() - 1 ; i > 0 ; i --) {
        int ma = min((k-count)/2, a[i]);
        count += 2*ma;
        a[i] -= ma;
        a[i-1] += 3*ma;
    }
    int nc = 0;
    for (int i = 0 ; i < a.size() ; i ++) {
        nc += a[i]*(pow(3, i + 1) + i*pow(3, i - 1));
    }
    cout << nc << "\n";
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
