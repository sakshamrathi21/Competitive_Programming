/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun 16 08:21:06 IST 2024
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
        int n, k;
        cin >> n >> k;
        
        for (int i = 0 ; i < k-3 ; i ++) cout << "1 ";
        int x = (n-k+3);
        if (x%4 == 0) {
            cout << x/2 << " " << x/4 << " " << x/4 << "\n";
        }
        else if (x%2 == 0) {
            cout << x/2-1 << " " << x/2-1 << " " << 2 << "\n";
        }
        else {
            cout << "1 " << x/2 << " " << x/2 << "\n";
        }
    }
}
