/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun 23 19:43:30 IST 2024
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
        vector<int> a(3);
        cin >> a[0] >> a[1] >> a[2];
        sort(a.begin(), a.end());
        cout << (a[2]-a[0]) << "\n"; 
    }
}
