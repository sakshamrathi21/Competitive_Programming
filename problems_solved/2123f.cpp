/**
 *    Author: Saksham Rathi
 *    Created: Thu Aug 14 16:47:35 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

set<int> primes;

void pre() {
    int n = 2e5 + 10;
    vector<bool> vis(n+1, false);
    map<int, vector<int>> eq;
    for (int i = 2 ; i <= n ; i ++) {
        if (vis[i]) continue;
        primes.insert(i);
        vis[i] = true;
        for (int j = 2 * i ; j <= n ; j += i) {
            vis[j] = true;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1, 0);
    vector<bool> vis(n+1, false);
    map<int, vector<int>> eq;
    a[1] = 1;
    for (auto it = primes.rbegin(); it != primes.rend(); ++it) {
        int i = *it;
        // cout << *it << " " << "check" <<endl;
        for (int j = i ; j <= n ; j += i) {
            if (vis[j]) continue;
            eq[i].push_back(j);
            vis[j] = true;
        }
    }
    for (auto & e : eq) {
        // cout << e.first << " " << e.second.size() << " hello " << endl;
        for (int i = 0 ; i < e.second.size() ; i ++) {
            a[e.second[e.second.size() - 1 - i]] = e.second[i];
        }
        if (e.second.size() > 1 && e.second.size() % 2) {
            swap(a[e.second[e.second.size()/2]], a[e.second[e.second.size()/2 - 1]]);
        }
    }
    for (int i = 1 ; i <= n ; i ++ ) cout << a[i] << " ";
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
