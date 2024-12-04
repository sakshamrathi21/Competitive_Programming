/**
 *    Author: Saksham Rathi
 *    Created: Tue Dec  3 21:10:49 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

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
        int ri = -1;
        int min_s = INT32_MAX;
        for (int i = n - 1 ; i >= 0 ; i -- ) {
            if (a[i] > min_s && (ri == -1 || a[i] < a[ri])) {
                ri = i;
            }
            min_s = min(a[i], min_s);
        }
        vector<int> b, c;
        for (int i = 0 ; i < n ; i ++) {
            if (a[i] >= a[ri]) b.push_back(a[i]);
            else c.push_back(a[i]);
        }
        sort(b.begin(), b.end());
        for (auto x : c) cout << x << " ";
        for (auto x : b) cout << x + 1 << " ";
        cout << "\n";
    }
}
