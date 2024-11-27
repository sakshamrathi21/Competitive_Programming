/**
 *    Author: Saksham Rathi
 *    Created: Tue Jun 25 19:50:35 IST 2024
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
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        int curr = 0;
        int cnt = 0;
        int left = 0, right = 0;
        while (left < n ) {
            // cout << left << " hello " << right << endl; 
            while (curr < l && right < n) {
                curr += a[right];
                right++;
            }
            if (curr >= l && curr <= r) {
                left = right;
                curr = 0;
                cnt++;
            }
            else {
                curr -= a[left];
                left++;
            }
        }
        cout << cnt << "\n";
    }
}
