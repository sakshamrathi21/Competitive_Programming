#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        
        int k, m;
        cin >> k >> m;
        int d = m/k;
        // cout << " d " << d << endl;
        if (d%3 == 2) {
            cout << 0 << "\n";
            continue;
        }
        int n = d/3;
        // cout << " n " << n << endl;
        if ((3*n+2)*k-m >= 0) {
            cout << (3*n+2)*k-m << "\n";
        }
        // cout << " hello " << t  << endl;
    }
}
