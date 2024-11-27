/**
 *    Author: Saksham Rathi
 *    Created: Wed Jul  3 08:40:10 IST 2024
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
        vector<int> a(n), b(n);
        int tot = 0;
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        for (int i = 0 ; i < n ; i ++) {
            cin >> b[i];
            if (a[i] > b[i]) swap(a[i], b[i]);
            tot += (b[i]-a[i]);
        }
        int mn = LLONG_MAX, mni = -1, mx = -1, mxi= -1;
        for (int i = 0 ; i < n ; i ++) {
            if (a[i] > mx) {
                mx = a[i];
                mxi  = i;
            }
            if (b[i] < mn) {
                mn= b[i];
                mni = i;
            }
        }
        if (mx <= mn) {
            cout << tot << "\n";
            continue;
        }
        if (mxi != mni) {
            cout << tot + 2*(mx-mn) << "\n";
            continue;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int diff = max(a[n-2]-mn, mx-b[1]);
        if (diff >= 0) cout << tot + 2*diff << '\n';
        else cout << tot << "\n";
    }
}
