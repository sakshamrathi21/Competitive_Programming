/**
 *    Author: Saksham Rathi
 *    Created: Thu Jun 20 08:22:05 IST 2024
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
        if (k > n) {
            cout << "NO\n";
            continue;
        }
        if (n == k) {
            cout << "YES\n1\n1\n";
            continue;
        }
        if (k < n && 2*k > n+1) {
            cout << "NO\n";
            continue;
        }
        else {
            cout << "YES\n2\n" << n-k+1 << " " << 1 << "\n";
        }
    }
}
