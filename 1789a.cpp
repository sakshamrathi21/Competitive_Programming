/**
 *    Author: Saksham Rathi
 *    Created: Mon Aug 19 15:47:21 IST 2024
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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        bool poss = false;
        for (int i = 0 ; i < n ; i ++) {
            for (int j = i+1 ; j < n ; j ++) {
                if (gcd(a[i], a[j]) <= 2) {
                    poss = true;
                    break;
                }
            }
        }
        if (poss) cout << "YES\n";
        else cout << "NO\n";
    }
}
