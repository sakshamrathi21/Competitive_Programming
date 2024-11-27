/**
 *    Author: Saksham Rathi
 *    Created: Thu Jun 20 18:10:46 IST 2024
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
        int a, b, c;
        cin >> a >> b >> c;
        int m = LLONG_MAX, a1, b1, c1;
        for (int i = 1 ; i <= 2*a ; i ++) {
            for (int j = i ; j <= 2*b ; j += i) {
                if(c/j*j >= j) {
                    int cost = abs(a-i) + abs(b-j) + abs(c/j*j-c);
                    if (cost < m) {
                        m = cost, a1 = i, b1 = j, c1 = c/j*j;
                    }
                }
                int cost = abs(a-i) + abs(b-j) + abs(c/j*j+j-c);
                if (cost < m) {
                    m = cost, a1 = i, b1 = j, c1 = c/j*j+j;
                }
            }
        }
        cout << m << "\n";
        cout << a1 <<" " << b1 << " " << c1 << "\n";
    }
}
