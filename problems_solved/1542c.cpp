/**
 *    Author: Saksham Rathi
 *    Created: Sat Jun 15 13:11:29 IST 2024
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

int lm(int x, int y) {
    return (x*y/gcd(x, y));
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int l = 1;
        int cost = 0;
        for (int i = 1 ; i <= n && l <= n ; i ++) {
            l = lm(l, i);
            cost += n/l;
            cost %= 1000000007;
        }
        cost += n;
        cost %= 1000000007;
        cout << cost << "\n";
    }
}
