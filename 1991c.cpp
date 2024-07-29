/**
 *    Author: Saksham Rathi
 *    Created: Mon Jul 29 15:59:04 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        int bit = a[0]%2;
        bool poss = true;
        for (int i = 1 ; i < n ; i ++ ) {
            if (a[i]%2 != bit) {
                poss  = false;
                break;
            }
        }
        if (!poss) {
            cout << "-1\n";
            continue;
        }
        vector<int> res;
        for (int i = 29 ; i >= 0 ; i --) {
            for (int j = 0 ; j < n ; j ++ ) {
                a[j] = abs(a[j]-(1<<i));
            }
            res.push_back(1<<i);
        }
        if (a[0] == 1) {
            res.push_back(1);
        }
        cout << res.size() << "\n";
        for (int i = 0 ; i < res.size() ; i ++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}
