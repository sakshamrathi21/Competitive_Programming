/**
 *    Author: Saksham Rathi
 *    Created: Sat Jun 15 09:03:42 IST 2024
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
        int co = 0;
        vector<bool> vis(n, false);
        for (int i = 0 ; i < min(31LL, n) ; i ++) {
            int mx = 0, idx = -1;
            for (int j = 0 ; j < n ; j ++) {
                if (vis[j]) continue;
                if ((co|a[j]) > mx && (co|a[j])>co) {
                    mx = co|a[j];
                    idx = j;
                }
            }
            if (idx != -1) {
                cout << a[idx] << " ";
                co |= a[idx];
                vis[idx] = true;
            }
            else {
                // cout << " hello " << endl;
                for (int k = 0 ; k < n ; k ++) {
                    if (!vis[k]) cout << a[k] << " ";
                }
                break;
            }
        }
        cout << "\n";
    }
}
