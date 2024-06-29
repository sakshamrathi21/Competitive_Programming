/**
 *    Author: Saksham Rathi
 *    Created: Sat Jun 29 15:25:44 IST 2024
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
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        int x = 1, j = 0;
        while (k -- ) {
            while (j < n && a[j] <= x + j) j++;
            x += j;
        }
        cout << x << "\n";
    }
}
