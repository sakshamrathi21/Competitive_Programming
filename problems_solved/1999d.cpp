/**
 *    Author: Saksham Rathi
 *    Created: Tue Aug  6 21:11:20 IST 2024
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
        string s, t;
        cin >> s >> t;
        int l = 0, r = 0;
        while (l < s.length() && r < t.length()) {
            // cout << " hello " << l << r << endl;
            if (s[l] == '?') {
                s[l] = t[r];
                l++;
                r++;
            }
            else if (s[l] == t[r]) {
                l++;
                r++;
            }
            else {
                l++;
            }
        }
        if (r < t.length()) {
            cout << "NO\n";
            continue;
        }
        for (int i = l ; i < s.length() ; i ++) {
            if (s[i] == '?') s[i] = 'a';
        }
        cout << "YES\n" << s << "\n";

    }
}
