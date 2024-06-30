/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun 30 19:54:00 IST 2024
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
        reverse(a.begin(), a.end());
        vector<int> start(n, 0), end(n, 0);
        end[0] = a[0];
        for (int i = 1 ; i < n ; i ++) {
            if (a[i] > a[i-1]) start[i] = 0;
            else start[i] = (start[i-1]+a[i-1]-a[i]+1);
            end[i] = max(end[i-1]+1, start[i]+a[i]);
            // cout << start[i] << " hello " << end[i] << endl;
        }
        int m = -1;
        for (int i = 0 ; i < n ; i ++) m = max(m, end[i]);
        cout << m << "\n";
    }
}
