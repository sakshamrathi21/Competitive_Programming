/**
 *    Author: Saksham Rathi
 *    Created: Sat Jul 27 11:04:31 IST 2024
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
        int n, x;
        cin >> n >> x;
        int cnt = 0;
        for (int a = 1 ; a <= n ; a ++) {
            for (int b = 1 ; b <= n/a ; b ++) {
                int ch = min(x-a-b, (n-a*b)/(a+b));
                if (ch >= 1) cnt += ch;
            }
        }
        cout << cnt << "\n";
    }
}
