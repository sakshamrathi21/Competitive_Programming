/**
 *    Author: Saksham Rathi
 *    Created: Sat Jul 20 21:15:05 IST 2024
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
        map<int, int> freq;
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        bool found = false;
        for (auto p : freq) {
            if (p.second%2) {
                found = true;
                break;
            }
        }
        if (!found) cout << "NO\n";
        else cout << "YES\n";
    }
}
