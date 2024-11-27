/**
 *    Author: Saksham Rathi
 *    Created: Thu Jul 18 20:19:04 IST 2024
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
        string s, t;
        cin >> s >> t;
        bool of = false, zf = false, poss = true;
        for (int i = 0 ; i < s.length() ; i ++) {
            if (!zf && s[i] == '0') zf = true;
            if (!of && s[i] == '1') of = true;
            if (s[i] == t[i]) continue;
            if (s[i] == '0' && t[i] == '1' && !of) {
                poss = false;
                break;
            }
            if (s[i] == '1' && t[i] == '0' && !of) {
                poss = false;
                break;
            }
        }
        if (poss) cout << "YES\n";
        else cout << "NO\n";
    }
}
