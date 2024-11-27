/**
 *    Author: Saksham Rathi
 *    Created: Tue Aug  6 21:02:29 IST 2024
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
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        int cnt = 0;
        if (a1 > b1 && a2 > b2) cnt+=2;
        if (a1 > b2 && a2 > b1) cnt+=2;
        cout<< cnt << "\n";

    }
}
