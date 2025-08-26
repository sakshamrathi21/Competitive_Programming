/**
 *    Author: Saksham Rathi
 *    Created: Tue Aug 26 21:09:41 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

vector<int> primes;
vector<int> pp;

void pre() {
    int MAXN = 6e6 + 10;
    vector<bool> vis(MAXN);
    for (int i = 2 ; i < MAXN ; i ++) {
        if (vis[i]) continue;
        vis[i] = true;
        primes.push_back(i);
        for (int j = 2 * i ; j < MAXN ; j += i) vis[j] = true;
    }
    pp.push_back(primes[0]);
    for (int i = 1 ; i < primes.size() ; i ++) pp.push_back(pp[i-1] + primes[i]);
}


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    int p = -1;
    for (int i = 0 ; i < primes.size() ; i ++) if (k % primes[i]) {
        p = primes[i];
        break;
    }
    for (int i = 0 ; i < n ; i ++) {
        while (a[i] % p) {
            a[i] += k;}
    }
    for (auto x : a) cout << x << " ";
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
