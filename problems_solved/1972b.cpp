/**
 *    Author: Saksham Rathi
 *    Created: Sun Jul 28 15:12:33 IST 2024
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
        int uc = 0;
        for (int i = 0 ; i < n ; i ++ ) if (s[i] == 'U') uc++;
        if (uc%2) cout << "YES\n";
        else cout << "NO\n";
    }
}
