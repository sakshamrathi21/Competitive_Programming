/**
 *    Author: Saksham Rathi
 *    Created: Tue Dec  3 19:43:43 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (k == 1) {
            cout << n%MOD << "\n";
            continue;
        }
        int a = 1, b = 1, ind = 2;
        while (true) {
            // cout << " hello " << ind << endl;
            if (b%k == 0) {
                break;
            }
            int temp = a%k;
            a = b%k;
            b = ((temp%k) + (b%k))%k;
            ind++;
        }
        
        cout << ((n%MOD)*(ind%MOD))%MOD << "\n";
    }
}
