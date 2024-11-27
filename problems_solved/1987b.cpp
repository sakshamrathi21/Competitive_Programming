/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun 30 19:53:57 IST 2024
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
        vector<int> diff;
        for (int i = 1 ; i < n ; i ++) {
            if (a[i] >= a[i-1]) continue;
            else {
                diff.push_back(a[i-1]-a[i]);
                a[i] = a[i-1];
            }
        }
        if (diff.size() == 0) {
            cout << "0\n";
            continue;
        }
        sort(diff.begin(), diff.end());
        int lm = diff[0], mm = diff[0];
        int cost = 0;
        int lastcmi = 0;
        for (int i = 0 ; i < diff.size() ; i ++) {
            // cout << lm << mm << cost << lastcmi << endl;
            diff[i] -= mm;
            if (diff[i] > 0) {
                cost += (diff.size()-lastcmi+1)*lm;
                lm = diff[i];
                mm += lm;
                lastcmi = i;
            }
        }
        cost += (diff.size()-lastcmi+1)*lm;
        cout << cost << "\n";
    }
}
