/**
 *    Author: Saksham Rathi
 *    Created: Thu Jun 27 09:46:02 IST 2024
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
        int h, c, t;
        cin >> h >> c >> t;
        if ((h+c)/2 >= t) cout << "2\n";
        else {
            int k = (h-t)/(2*t-h-c);
            if (abs(k*(h+c)+h - t*(2*k+1))*(2*k+3) <= abs((k+1)*(h+c)+h - t*(2*k+3))*(2*k+1)) cout << 2*k+1 <<"\n";
            else cout << 2*k+3 << "\n";
        }
    }
}
