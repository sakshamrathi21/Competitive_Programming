/**
 *    Author: Saksham Rathi
 *    Created: Thu Jun 13 09:32:44 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

bool cmp(pair<int, int> &a, pair<int, int> &b){
    if(a.first != b.first) return a.first> b.first;
    return a.second< b.second;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<pair<int, int>> a(k);
        map<pair<int, int>, int> idx;
        for (int i = 0 ; i < k ; i ++) {
            cin >> a[i].first >> a[i].second;
            idx[a[i]] = i;
        }
        sort(a.begin(), a.end(), cmp);
        vector<int> ans(k);
        int total = 0, curr = m+1, last = n;
        for (auto e : a) {
            if (curr > e.second) {
                ans[idx[e]] = 1;
                total += (curr - 1) *(last - e.first);
                curr = e.second;
                last = e.first;
            }
        }
        total += (curr-1)*last;
        cout << total << "\n";
        for (auto e : ans) cout << e << " ";
        cout <<"\n";

    }
}
