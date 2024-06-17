/**
 *    Author: Saksham Rathi
 *    Created: Mon Jun 17 09:43:22 IST 2024
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
        int a, b;
        cin >> a >> b;
        int m = LLONG_MAX;
        for (int k = 1 ; k <= 100000 ; k ++ ) {
            int curr = k-1;
            if (a%k == 0) curr += a/k;
            else curr+= (a/k+1);
            if (b%k == 0) curr += b/k;
            else curr+= (b/k+1);
            m = min(m, curr);
        }
        cout << m << "\n";
    }
}
