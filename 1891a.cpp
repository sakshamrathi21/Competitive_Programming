/**
 *    Author: Saksham Rathi
 *    Created: Thu Jun 13 22:59:39 IST 2024
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
        int curr = 1;
        int prev = 1;
        bool poss = true;
        while (curr <= n) {
            // cout << " hello " << prev << curr << endl;
            for (int i = prev+1 ; i < curr ; i ++) {
                if (a[i-1] > a[i]) poss = false;
            }
            prev = curr;
            curr*=2;
        }
        // cout << curr << " hello " << n;
        for (int i = prev+1 ; i < n ; i ++) {
            if (a[i-1] > a[i]) poss = false;
        }
        cout << ((poss) ? "YES\n": "NO\n");
    }
}
