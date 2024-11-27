/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun  9 20:33:41 IST 2024
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
        bool poss = true;
        while (n > 0) {
            if (n%10 == 9) {
                poss = false;
                break;
            }
            int curr = 10+n%10;
            n-=curr;
            if (n < 0) poss = false;
            n/=10;
            
        }
        if (poss) cout << "YES\n";
        else cout << "NO\n";
    }
}
