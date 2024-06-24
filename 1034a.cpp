/**
 *    Author: Saksham Rathi
 *    Created: Sat Jun 22 17:12:46 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int x, int y) {
    if (y == 0) return x;
    if (x < y) return gcd(y, x);
    if (x%y ==0) return y;
    return gcd(x%y, y);
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;

    vector<int> visited(15000001, 0);
    visited[1] = true;
    for (int k = 2 ; k < 15000001 ; k ++) {
        if (visited[k]) continue;
        // cout << k << endl;
        for (int i = 2*k  ; i < 15000001 ; i+=k) {
            // if (i == 4) cout << " hello" << i << k << endl;
            visited[i] = k;
            // if (i == 4) cout << " hello" << i << k<< visited[i]<< endl;
        }
    }
    // cout << visited[9] << " hello " << endl;
    vector<int> primes;
    for (int p = 2 ; p < 15000001 ; p ++) if (!visited[p]) primes.push_back(p);
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        cin >> a[0];
        int g = a[0];
        for (int i = 1 ; i < n ; i ++) {
            cin >> a[i];
            g = gcd(a[i], g);
        }
        int mx = -1;
        for (int i = 0 ;i < n ; i ++) {a[i]/=g; mx = max(mx, a[i]);}
        int mc = -1;
        for (auto p : primes) {
            if (p > mx) break;
            int cnt = 0;
            for (int i = 0 ; i < n ; i ++) {
                if (a[i]%p == 0) cnt++;
            }
            mc = max(mc, cnt);
        }
        if (mc == 0 || mc == -1) cout << -1;
        else cout << n-mc;
    }
}
