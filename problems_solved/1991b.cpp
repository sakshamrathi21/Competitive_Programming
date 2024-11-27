/**
 *    Author: Saksham Rathi
 *    Created: Mon Jul 29 15:36:15 IST 2024
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
        vector<int> b(n-1);
        for (int i = 0 ; i < n-1 ; i ++) {
            cin >> b[i];
        }
        vector<int> a(n, 0);
        for (int i = 0 ; i < n-1 ; i ++ ) {
            for (int j = 0 ; j < 30 ; j ++) {
                if ((1<<j)&b[i]) {
                    a[i] |= (1<<j);
                    a[i+1] |= (1<<j);
                }
            }
        }
        bool poss = true;
        for (int i = 0 ; i < n-1 ; i ++) {
            if ((a[i]&a[i+1]) != b[i]) {
                poss = false;
                break;
            }
        }
        if (!poss) {
            cout << "-1\n";
        }
        else {
            for (int i = 0 ; i < n ; i ++ ) {
                cout << a[i] << " ";
            }
            cout << "\n";
        }

    }
}
