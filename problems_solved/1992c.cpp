/**
 *    Author: Saksham Rathi
 *    Created: Thu Jul 11 20:23:20 IST 2024
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
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = n ; i >= k ; i --) {
            cout << i << " ";
        }
        for (int i = m+1 ; i < k ; i ++) {
            cout << i << " ";
        }
        for (int i = 1 ; i <= m ; i ++) {
            cout << i << " ";
        }
        cout << "\n";
    }
}
