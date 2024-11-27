/**
 *    Author: Saksham Rathi
 *    Created: Tue Jun 11 20:06:34 IST 2024
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
        string a, b;
        cin >> a >> b;
        // cout << " hello " << a << endl;
        char temp = a[0];
        a[0] = b[0];
        b[0] = temp;
        cout << a << " " << b << "\n";

    }
}
