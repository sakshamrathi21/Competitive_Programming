/**
 *    Author: Saksham Rathi
 *    Created: Sun Jul 28 16:21:39 IST 2024
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
        int cnt = 0;
        for (int b = 1 ; b <= m ; b ++) {
            cnt += (n/b+1)/b;
        }
        cout << cnt-1<< "\n";
    }
}
