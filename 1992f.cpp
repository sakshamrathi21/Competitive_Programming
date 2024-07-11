/**
 *    Author: Saksham Rathi
 *    Created: Thu Jul 11 20:55:22 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector<int> res;
    for (int l = 1 ; l <= t ; l ++ ) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        int ns = 0;
        set<int> s;
        for (int i = 0 ; i < n ; i ++) {
            // cout << i << " hello " << ns << s.size() << endl;
            if (a[i] > x || x%a[i] != 0 || a[i] == 1) continue;
            if (s.count(x/a[i])) {
                s.clear();
                ns++;
            }
            vector<int> vals;
            for (auto v : s) {
                // cout << " check " << v << endl;
                if (a[i]*v < x && x%(a[i]*v) == 0) vals.push_back(a[i]*v);
            }
            for (int j = 0 ; j < vals.size() ; j ++) s.insert(vals[j]);
            s.insert(a[i]);
        }
        res.push_back(ns+1); 
    }
    for (int i = 0 ; i < res.size() ; i ++) {
        cout << res[i] << "\n";
    }
}
