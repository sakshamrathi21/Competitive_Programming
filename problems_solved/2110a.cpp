/**
 *    Author: Saksham Rathi
 *    Created: Sat May 24 15:58:45 BST 2025
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
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int fo = -1, fe = -1, lo = -1, le = -1;
        for (int i = 0 ; i < n ; i ++) {
            if (a[i] % 2 == 0) {
                if (fe == -1) {
                    fe = i;
                } else {
                    le = i;
                }
            } else {
                if (fo == -1) {
                    fo = i;;
                } else {
                    lo = i;
                }
            }
        }
        int ans = n - 1;
        if (fo != -1 && lo != -1)
        {
            ans = n - (lo - fo + 1);
        }
        if (fe != -1 && le != -1)
        {
            ans = min(ans, n - (le - fe + 1));
        }
        cout << ans << "\n";
    }
}
