/**
 *    Author: Saksham Rathi
 *    Created: Sun Sep 28 10:50:34 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

bool cv(vector<int>&v1, vector<int>&v2) {
    if (v1.size() != v2.size()) return v1.size() < v2.size();
    for (size_t i = 0 ; i < v1.size() ; i ++) {
        if (v1[i] != v2[i]) return v1[i] < v2[i];
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a;
    for (int i = 0 ; i < n ; i ++) {
        int s;
        cin >> s;
        vector<int> x(s);
        for (int j = 0 ; j < s ; j ++) cin >> x[j];
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    vector<int> f = a[0];
    for (size_t i = 1 ; i < a.size() ; i ++) {
        for (size_t j = f.size() ; j < a[i].size() ; j ++) f.push_back(a[i][j]);
    }
    for (auto e : f) cout << e << " ";
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
