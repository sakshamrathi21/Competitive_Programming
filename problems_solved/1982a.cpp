/**
 *    Author: Saksham Rathi
 *    Created: Tue Jun 25 19:50:28 IST 2024
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
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 >= x1 && x2 <= y2) {
            cout << "YES\n";
        }
        else if (y1 <= x1 && x2 >= y2) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }

    }
}
