/**
 *    Author: Saksham Rathi
 *    Created: Tue Aug  6 20:58:03 IST 2024
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
        int n;
        cin >> n;
        cout << (n%10) + (n/10) << "\n";
    }
}
