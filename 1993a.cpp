/**
 *    Author: Saksham Rathi
 *    Created: Tue Aug  6 14:26:53 IST 2024
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
        string s;
        cin >> s;
        int ca = 0, cb = 0, cc = 0, cd = 0;
        for (int i = 0 ; i < s.length() ; i ++) {
            if (s[i] == 'A') ca++;
            if (s[i] == 'B') cb++;
            if (s[i] == 'C') cc++;
            if (s[i] == 'D') cd++;
        }
        int cnt = 0;
        cnt += min(ca, n);
        cnt += min(cb, n);
        cnt += min(cc, n);
        cnt += min(cd, n);
        cout << cnt << "\n";
    }
}
