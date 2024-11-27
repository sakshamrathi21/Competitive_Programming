/**
 *    Author: Saksham Rathi
 *    Created: Tue Jun 18 09:03:36 IST 2024
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
        int n, c;
        cin >> n >> c;
        vector<int> s(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> s[i];
        }
        int odd = 0, even = 0;
        int tot = (c+2)*(c+1)/2;
        for (int i = 0 ; i < n ; i ++) {
            tot -= (c-s[i]+1);
            tot -= (s[i]/2+1);
            if (s[i]%2) odd++;
            else even++;
        }
        tot += 1ll*((odd)*(odd+1))/2;
        tot += 1ll*((even)*(even+1))/2;
        cout << tot << "\n";
    }
}
