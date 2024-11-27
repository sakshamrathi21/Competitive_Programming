/**
 *    Author: Saksham Rathi
 *    Created: Thu Jun 13 17:43:18 IST 2024
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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        map<int, int> f;
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
            f[a[i]]++;
        }
        int bank = 0;
        for (auto &e : f) {
            int fact = e.second/k;
            e.second -= fact*k;
            bank += (k-1)*fact;
            // if (e.second == 0) f.erase(e.first);
            // 
        }
        
        for (int i = 0 ; i < 100 ; i ++) {
            for (auto &e : f) {
                if (e.second > 0 && bank > 0) {
                    bank -= (k-e.second);
                    bank += k-1;
                    e.second = 0;
                    // f.erase(e.first);
                }
            }
        }
        // cout << bank << " hello " << endl;
        if (bank == 0) {
            int cnt = 0;
            for (auto e: f) {
                cnt += e.second;
            }
            cout << cnt << "\n";
            continue;
        }
        while (bank >= k) {
            bank -= 1;
        }
        cout << bank%k << "\n";


        
    }
}
