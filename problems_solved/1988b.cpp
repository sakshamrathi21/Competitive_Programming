/**
 *    Author: Saksham Rathi
 *    Created: Mon Jul 15 23:35:54 IST 2024
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
        int co = 0, cz = 0;
        if (s[0] == '0') cz++;
        else co++;
        for (int i = 1 ; i < n ; i ++) {
            if (s[i] == s[i-1] && s[i] == '0') continue;
            if (s[i] == '0') cz++;
            else co++;
        }
        if (cz >= co) cout << "NO\n";
        else cout << "YES\n";
    }
}
