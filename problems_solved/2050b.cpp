/**
 *    Author: Saksham Rathi
 *    Created: Thu Dec 12 19:05:33 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

signed main () {
    (void)MOD;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int s = 0;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
            s += a[i];
        }
        if (s%n) {
            cout << "NO\n";
            continue;
        }
        int r = s/n;
        for (int i = 0 ; i < n-2 ; i ++) {
            if (a[i] != r) {
                a[i+2] -= (r - a[i]);
                a[i] = r;
            }
        }
        bool poss = true;
        for (int i = 0 ; i < n ; i ++ ) if (a[i] != r) {poss = false; break;}
        if (poss) cout << "YES\n";
        else cout << "NO\n";
    }
}
