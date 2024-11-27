/**
 *    Author: Saksham Rathi
 *    Created: Thu Jun 27 20:08:23 IST 2024
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
        int x, y;
        cin >> x >> y;
        if (y-abs(x)+1 >= -abs(x)) cout << "YES\n";
        else cout<< "NO\n";

    }
}
