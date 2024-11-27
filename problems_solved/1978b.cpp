/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun 16 14:25:27 IST 2024
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
        int n, a, b;
        cin >> n >> a >> b;

        if (a >= b) {
            cout << a*n << "\n";
            continue;
        }
        if (b-n+1 >= a) {
            cout << ((2*b-n+1)*n)/2 << "\n";
            continue;
        }
        int i1 = b-a, i2 = b+1-a;
        
        int l1 = ((2*b-i1+1)*i1)/2+a*(n-i1), l2 = ((2*b-i2+1)*i2)/2+a*(n-i2);
        cout << max(l1, l2) << "\n"; 



    }
}
