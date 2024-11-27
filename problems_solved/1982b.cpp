/**
 *    Author: Saksham Rathi
 *    Created: Tue Jun 25 19:50:32 IST 2024
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
        int x, y, k;
        cin >> x >> y >> k;
        if (k <= 100) {
            for (int i = 0 ; i < k ; i ++) {
                x+=1;
                while (x%y ==0) x/=y;
            }
            cout << x << "\n";
            continue;
        }
        int op = 0;
        while (x >= y) {
            // cout << x << y << endl;
            if (op == k) break;
            if ((x/y+1)*y - x + op <= k) {
                op = (x/y+1)*y - x + op;
                x = (x/y+1)*y;
                while (x%y == 0) x/=y;
                // cout << op << x << " " << (x/y+1)*y - x << endl;
            }
            else break;
        }
        
        if (op == k) {
            cout << x << "\n";
            continue;
        }
        if (x >= y) {
            k -= op;
            cout << x + k << "\n";
            continue;
        }
        
        k -= op;
        k %= (y-1);
        if (k >= y - x) {
            k -= (y-x);
            x = 1;
            x += k; 
        }
        else {
            x += k;
        }
        cout << x << "\n";
    

    }
}
