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
        multiset<int> s;
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
            s.insert(a[i]);
        }
        int cnt = s.count(*s.rbegin());
        if (cnt%2) {
            cout << "YES\n";
        }
        else cout << "NO\n";

    }
}
