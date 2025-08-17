/**
 *    Author: Saksham Rathi
 *    Created: Sun Aug 17 09:19:05 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

vector<int> primes;

void pre() {
    int MAXN = 1e5 + 10;
    vector<bool> vis(MAXN);
    for (int i = 2 ; i < MAXN ; i ++) {
        if (vis[i]) continue;
        vis[i] = true;
        primes.push_back(i);
        for (int j = 2 * i ; j < MAXN ; j += i) vis[j] = true;
    }
}

void solve() {
    int n;
    cin >> n;
    int l = n / 3, r = (2*n + 2)/3;
    int p = -1;
    // if (n <= 3) {
    //     for (int i = 1; i <= n ; i ++ ) cout << i << " ";
    //     cout << "\n";
    //     return;
    // }
    for (int i = 0 ; i < primes.size() ; i ++) if (primes[i] >= l && primes[i] <= r) {p = primes[i]; break;}
    int diff = min(p - 1, n - p);
    cout << p << " ";
    for (int i = 1 ; i <= diff ; i ++) {cout << p - i << " " << p + i << " ";}
    for (int j = 1 ; j < p - diff ; j ++) cout << j << " ";
    for (int j = p + diff + 1 ; j  <= n ; j ++) cout << j << " ";
    cout << "\n";
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    pre();
    while (t--) {
        solve();
    }
}
