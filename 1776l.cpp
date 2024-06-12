/**
 *    Author: Saksham Rathi
 *    Created: Mon Jun 10 19:01:26 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int x, int y) {
    // cout << x << y << endl;
    if (y == 0) return x;
    if (x < y) return gcd(y, x);
    if (x%y ==0) return y;
    return gcd(x%y, y);
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int pc = 0 , sc = 0;
        for (int i = 0 ; i < s.length() ; i ++) {
            if (s[i] == '+') pc++;
            else sc++;
        }
        int q;
        cin >> q;
        while (q--) {
            int a, b; cin >> a >> b;
            if (pc == sc) {
                cout << "YES\n"; continue; 
            }
            if (a== b ) {
                cout << "NO\n"; continue;
            }
            if (abs((pc-sc)*b)%abs(b-a)) {
                cout << "NO\n"; continue;
            }
            int k = (pc-sc)*b/(b-a);
            if (k >= -sc && k <= pc) {
                cout << "YES\n"; continue;
            }
            cout << "NO\n";
        }

    }
}
