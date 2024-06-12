/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun  9 20:16:13 IST 2024
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
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        string s;
        s.push_back('B');
        int i;
        for (i = 1 ; i < n ; i ++) {
            if (a[i] == a[i-1]) s.push_back('B');
            else break;
        }
        if (i == n) cout << "NO\n";
        else {
            for (; i < n ; i ++) s.push_back('R');
            if (s[n-2] == 'B') s[n-2] = 'R';
            else s[n-1] = 'B';
            cout << "YES\n";
            cout << s << "\n";
        }
    }
}
