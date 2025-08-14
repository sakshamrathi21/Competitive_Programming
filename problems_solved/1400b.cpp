/**
 *    Author: Saksham Rathi
 *    Created: Thu Aug 14 23:01:41 IST 2025
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void solve() {
    int p, f, cs, cw, s, w;
    cin >> p >> f >> cs >> cw >> s >> w;
    int best = 0;
    int xp, xf, yp, yf;
    for (xp = 0 ; xp <= cs ; xp ++) {
        if (xp * s > p) break;
        yp = min(cw, (p - xp * s)/w);
        if (s <= w) {
            xf = min(f/s, cs - xp);
            yf = min((f - s*xf)/w, cw - yp);
        }
        else {
            yf = min(f/w, cw - yp);
            xf = min((f - w*yf)/s, cs - xp);
        }
        best = max(best, xp + yp + xf + yf);
    }
    cout << best << "\n";
}

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
