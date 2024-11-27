/**
 *    Author: Saksham Rathi
 *    Created: Sun Jul 28 11:18:12 IST 2024
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
        int n, m;
        cin >> n >> m;
        int l = max(0LL, n-m);
        int r = n+m;
        int cnt = 0;
        for (int i= 0 ; i < 31 ; i ++) {
            int bit = 0;
            if ((1<<i)&l || (1<<i)&r) bit = 1;
            if (l/(1<<i) != r/(1<<i)) bit = 1;
            cnt += (1<<i)*bit;
        }
        cout << cnt << "\n";
    }
}
