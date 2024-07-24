/**
 *    Author: Saksham Rathi
 *    Created: Wed Jul 24 16:18:41 IST 2024
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
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> uniq;
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        map<int, int> freq;
        for (int i = 0 ; i < n ; i ++) {
            freq[a[i]]++;
        }
        for (auto e : freq){
            uniq.push_back(e.first);
        }
        int mx = -1;
        for (int i = 0 ; i < uniq.size()-1 ; i ++) {
            if (uniq[i+1]-uniq[i] != 1) {
                mx = max(mx, min(m/uniq[i], freq[uniq[i]])*uniq[i]);
                continue;
            }
            int q1 = freq[uniq[i]];
            // int q2 = freq[uniq[i+1]];
            for (int k1 = 0 ; k1 <= q1 ; k1 ++ ){
                if (k1*uniq[i] > m) break;
                mx = max(mx, k1*uniq[i]+min((m-k1*uniq[i])/uniq[i+1], freq[uniq[i+1]])*uniq[i+1]);
            }
            // cout << " hello " << mx << endl;
        }
        mx = max(mx, min(m/uniq[uniq.size()-1], freq[uniq[uniq.size()-1]])*uniq[uniq.size()-1]);
        // mx = max(mx, m/uniq[uniq.size()-1]*uniq[uniq.size()-1]);
        cout << mx << "\n";
    }  
}
