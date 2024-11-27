/**
 *    Author: Saksham Rathi
 *    Created: Sat Jun 22 14:46:04 IST 2024
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
        int a, b, c;
        cin >> a >> b >> c;
        if (max(max(a, b), c) >= 2*(a+b+c-max(max(a, b), c))) cout << a+b+c-max(max(a, b), c) << "\n";
        else cout << (a+b+c)/3 << "\n";
    }
}
