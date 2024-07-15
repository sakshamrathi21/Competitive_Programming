/**
 *    Author: Saksham Rathi
 *    Created: Mon Jul 15 23:27:05 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

int val(int n, int k) {
    // cout << " hello " << n << " " << k << endl;
    if (n == 1) return 0;
    if (n <= 0) return 0;
    return (1+val(n-k+1, k));
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << val(n, k) << "\n";
    }
}
