/**
 *    Author: Saksham Rathi
 *    Created: Sat Jul 20 21:33:27 IST 2024
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
        int tot = 0;
        for (int i = 0 ; i < n ; i ++) {
            tot += a[i];
        }
        // for (int i = 0 ; i < n ; i ++) cout << a[i] << " ";
        int maxu = 0;
        vector<int> c(n+1, false);
        for (int i = 0 ; i < n ; i ++) {
            if (c[a[i]]) {
                maxu = max(maxu, a[i]);
            }
            c[a[i]] = true;
            a[i] = maxu;
            // tot += a[i];
        }
        for (int i = 0 ; i < n ; i ++) tot+=a[i];
        maxu = 0;
        // cout << " hello " << tot << endl;
        c.assign(n+1, false);
        for (int i = 0 ; i < n ; i ++) {
            if (c[a[i]]) {
                maxu = max(maxu, a[i]);
            }
            c[a[i]] = true;
            a[i] = maxu;
            // tot += a[i];
        }
        for (int i = 0 ; i < n ; i ++) {
            tot += (n-i)*a[i];
        }
        cout << tot << "\n";
    }

}
