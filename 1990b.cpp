/**
 *    Author: Saksham Rathi
 *    Created: Sat Jul 20 21:26:02 IST 2024
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
        int n, x, y;
        cin >> n >> x >> y;
        for (int i = 1 ; i < y ; i ++) {
            cout << "-1 ";
        }
        for (int i = y ; i <= x ; i ++) {
            cout << "1 ";
        }
        for (int i = x+1 ; i <= n ; i ++) {
            cout << "-1 ";
        }
        cout << "\n";
    }
}
