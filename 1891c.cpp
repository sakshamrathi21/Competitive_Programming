/**
 *    Author: Saksham Rathi
 *    Created: Fri Jul 26 16:22:30 IST 2024
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
        sort(a.begin(), a.end());
        int l = 0, r = n-1, curr = 0, cnt = 0;
        while (l < r) {
            // cout << l << " " << r << " " << a[l] << " " << a[r] << " " << curr << endl;
            if (curr+a[l] < a[r]) {
                curr += a[l];
                cnt += a[l];
                a[l] = 0;
                l++;
            }
            else if (curr+a[l] == a[r]) {
                cnt += a[l];
                a[r] = 0;
                a[l] = 0;
                curr = 0;
                l++;
                r--;
                cnt += 1;
            }
            else {
                cnt += 1;
                cnt += (a[r]-curr);
                a[l] -= (a[r]-curr);
                curr = 0;
                a[r] = 0;
                r--;
            }
        }
        // cout << " check " << a[l] << curr << endl;
        if (curr >= a[l] && curr != 0) {
            cnt += 1;
            a[l] = 0;
        }
        if (a[l] != 0) {
            if (a[l] == 1 && curr == 0) {
                cnt++;
            }
            else {
                int x = (a[l]-curr+1)/2;
                // cout << " check "
                cnt+=x;
                cnt+=1;
            }
        }
        cout << cnt << "\n";
    }
}
