/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun  9 20:57:04 IST 2024
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
        int max_neg = LLONG_MAX, ind=-1, curr_neg = 0;
        for (int i = 0 ; i < n ; i ++) {
            // cout << curr_neg << " hello " << n << endl;
            curr_neg += a[i];
            if (curr_neg < max_neg) {
                max_neg = curr_neg;
                ind = i;
            }
        }
        // cout << " hello " << ind << endl;
        int sum = 0;
        if (ind == -1) {
            for (int i = 0 ; i < n ; i ++) sum+=a[i];
            cout << sum << "\n";
        }
        else {
            for (int i = 0 ; i <= ind ; i ++ ) {
                sum += a[i];
            }
            sum = abs(sum);
            for (int i = ind+1 ; i < n ; i ++) sum += a[i];
            cout << abs(sum) << "\n";
        }
    }
}
