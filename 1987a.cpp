/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun 30 19:53:53 IST 2024
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
        cout << (n-1)*k+1 << "\n";
    }
}
