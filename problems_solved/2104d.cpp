/**
 *    Author: Saksham Rathi
 *    Created: Fri Aug 15 10:43:58 IST 2025
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
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int ans = -1;
    for (int k = 0 ; k < n ; k ++) {
        sum += a[k];
        if (sum >= pp[k]) ans = max(ans, k + 1);
        else break;
    }
    cout << n - ans << "\n";
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
