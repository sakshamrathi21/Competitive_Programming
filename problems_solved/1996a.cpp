/**
 *    Author: Saksham Rathi
 *    Created: Sat Jul 27 13:35:16 IST 2024
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
        if (n%4 == 2) {
            cout << (n-2)/4+1 << "\n";
        }
        else cout << n/4 << "\n";

    }
}
