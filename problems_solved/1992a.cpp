/**
 *    Author: Saksham Rathi
 *    Created: Thu Jul 11 20:05:13 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

int max_prod(int a, int b, int c, int ns) {
    if (ns == 0) return a*b*c;
    int res = max_prod(a+1, b, c, ns-1);
    res = max(res, max_prod(a, b+1, c, ns-1));
    res = max(res, max_prod(a, b, c+1, ns-1));
    return res;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        // int n;
        // cin >> n;
        int a, b, c;
        cin >> a >> b >> c;
        cout << max_prod(a, b, c, 5) << "\n";
    }
}
