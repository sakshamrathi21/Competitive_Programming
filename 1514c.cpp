/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun 16 08:59:48 IST 2024
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
    int n;
    cin >> n;
    vector<int> coprime;
    int p = 1;
    for (int i = 1 ; i<= n-1 ; i ++) {if (gcd(i, n) == 1) {coprime.push_back(i); p*= i; p%=n;}}
    if (p == 1) cout << coprime.size() << "\n";
    else cout << coprime.size()-1 << "\n";
    for (int i = 0 ; i < coprime.size() ; i ++) {
        if (p != 1 && coprime[i] == p) continue;
        cout << coprime[i] << " ";
    }

}
