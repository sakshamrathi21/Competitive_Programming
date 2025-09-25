/**
 *    Author: Saksham Rathi
 *    Created: Thu Sep 25 23:14:54 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll count_at_most_k(const vector<int>& a, int K, int lenL, int lenR) {
    if (K < 0) return 0;            
    int n = (int)a.size();
    if (lenL > n) return 0;          
    unordered_map<int,int> freq;
    freq.reserve(1024);
    int distinct = 0;
    int r = 0;
    ll res = 0;
    for (int l = 0; l < n; ++l) {
        while (r < n && (distinct + (freq.count(a[r])==0 ? 1 : (freq.at(a[r])==0 ? 1 : 0))) <= K) {
            if (freq[a[r]] == 0) ++distinct;
            ++freq[a[r]];
            ++r;
        }
        int c_low  = l + lenL - 1;
        int c_high = l + lenR - 1;
        int c_max  = min(r - 1, c_high);
        if (c_max >= c_low && c_low < n) {
            res += (ll)(c_max - c_low + 1);
        }
        freq[a[l]]--;
        if (freq[a[l]] == 0) {
            freq.erase(a[l]);
            --distinct;
        }
    }
    return res;
}

void solve() {
    int n, k, l, r;
    cin >> n >> k >> l >> r;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    cout << count_at_most_k(a, k, l, r) - count_at_most_k(a, k-1, l, r) << "\n";
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
