/**
 *    Author: Saksham Rathi
 *    Created: Thu Jun 13 18:08:28 IST 2024
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
        int mex = 1;
        sort(a.begin(), a.end());
        for (int i = 0 ; i < n ; i ++) {
            if (a[i] == mex) mex++;
        }
        if (mex > a[n-1]) {
            if (a[n-1]%2) cout << "Alice\n";
            else cout << "Bob\n";
        }
        else {
            if (mex%2) cout << "Alice\n";
            else cout << "Bob\n";
        }
    }
}
