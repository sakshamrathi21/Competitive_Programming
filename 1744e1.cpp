/**
 *    Author: Saksham Rathi
 *    Created: Sat Jun 15 08:45:08 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int x, int y) {
    if (y == 0) return x;
    if (x < y) return gcd(y, x);
    if (x%y ==0) return y;
    return gcd(x%y, y);
}


signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        bool poss = false;
        for (int x = a+1 ; x <= c ; x++){
            int yd = (a*b)/gcd(a*b, x);
            int y = (d/yd)*yd;
            if (y > b) {
                poss = true;
                cout << x << " " << y << "\n";
                break;
            }
        }
        if (!poss) cout << "-1 -1\n";
    }
}
