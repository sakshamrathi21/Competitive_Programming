/**
 *    Author: Saksham Rathi
 *    Created: Tue Jun 11 09:58:59 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int x, int y) {
    // cout << x << y << endl;
    if (y == 0) return x;
    if (x < y) return gcd(y, x);
    if (x%y ==0) return y;
    return gcd(x%y, y);
}


signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0 ; i < n ; i ++) cin >> a[i];
    for (int i = 0 ; i < m ; i ++) cin >> b[i];
    sort(a.begin(), a.end());
    int g = 0;
    for (int i = 1 ; i < n ; i ++ ) g = gcd(g, a[i]-a[0]);
    for (int i = 0 ; i < m ; i ++) cout << gcd(g, a[0]+b[i]) << " ";
}
