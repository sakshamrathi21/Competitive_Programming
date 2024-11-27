/**
 *    Author: Saksham Rathi
 *    Created: Fri Jun 14 09:26:43 IST 2024
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
        int curr = a[0];
        int num_parts = 1;
        for (int i = 0 ; i < n ; i ++) {
            curr&=a[i];
            // cout << i << " hello " << curr << endl;
            if (curr == 0) {
                if (i == n-1) break;
                num_parts++;
                curr = a[i+1];
            }
        }
        if (curr != 0) num_parts--;
        num_parts = max(num_parts, 1LL);
        cout << num_parts << "\n";
    }
}
