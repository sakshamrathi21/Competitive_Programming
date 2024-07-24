/**
 *    Author: Saksham Rathi
 *    Created: Wed Jul 24 12:06:56 IST 2024
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
        int n, k;
        cin >> n >> k;
        if ( k == 0) {
            cout << "0\n";
            continue;
        }
        int ans = 1, curr = n;
        k -= curr;
        while ( k > 0 ) {
            curr--;
            k-=curr;
            ans++;
            if (k > 0) {
                k-=curr;
                ans++;
            }
        }
        cout << ans << "\n";
    }
}
