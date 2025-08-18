/**
 *    Author: Saksham Rathi
 *    Created: Mon Aug 18 22:10:19 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

int vecs(vector<int>&x, int k) {
    int n = x.size();
    if (n == 0 || n == 1) return 0;
    vector<int> lsum(n, 0), rsum(n, 0);
    lsum[1] = (x[1] - x[0])/k;
    for (int i = 2 ; i < n - 1; i += 2) {
        lsum[i+1] = (x[i+1] - x[i])/k + lsum[i-1];
    }
    
    rsum[n-2] = (x[n-1]-x[n-2])/k;
    for (int i = n - 3 ; i >= 1 ; i -= 2) {
        rsum[i-1] = (x[i] - x[i-1])/k + rsum[i+1];
    }
    int m = rsum[1];
    for (int i = 2 ; i < n - 1 ; i += 2) {
        m = min(m, lsum[i-1] + rsum[i+1]);
    }
    m = min(m, lsum[n-2]);
    return m;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    map<int, vector<int>> f;
    for (int i = 0 ; i < n ; i ++) f[a[i] % k].push_back(a[i]);
    int no = 0;
    for (auto& e : f) {sort(e.second.begin(), e.second.end()); if (e.second.size() % 2) no++;}
    if (no > 1) {
        cout << "-1\n";
        return;
    }
    int sum = 0;
    for (auto& e : f) {
        if (e.second.size() % 2) {
            sum += vecs(e.second, k);
        }
        else {
            for (int i = 0 ; i < e.second.size() ; i += 2) sum += (e.second[i+1] - e.second[i])/k;
        }
    }
    cout << sum << "\n";
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
