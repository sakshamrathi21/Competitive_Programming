/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun 30 08:54:01 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        int mz = 0, mo = 0;
        for (int i = 0 ; i < n ; i ++) {
            if ((a[i]%3)*(a[i]%3)%3 == 0) mz++;
            else mo++;
        }
        int mp = n/2, cz = 0;
        if (mz >= mo) {
            cout << "2\n";
            for (int i = 0 ; i < n ; i ++) {
                if ((a[i]%3)*(a[i]%3)%3 == 1) cout <<"1";
                else {
                    if (cz < mp) cout <<"0";
                    else cout << "1";
                    cz++;
                }
            }
        }
        else {
            cout << "0\n";
            for (int i = 0 ; i < n ; i ++) {
                if ((a[i]%3)*(a[i]%3)%3 == 0) cout <<"0";
                else {
                    if (cz < mp) cout <<"1";
                    else cout << "0";
                    cz++;
                }
            }
        }
    }
}
