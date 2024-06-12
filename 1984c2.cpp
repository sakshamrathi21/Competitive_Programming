/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun  9 20:57:04 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

int MOD=998244353;

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
        int max_neg = 0, ind=-1, curr_neg = 0;
        for (int i = 0 ; i < n ; i ++) {
            // cout << curr_neg << " hello " << n << endl;
            curr_neg += a[i];
            if (curr_neg < max_neg) {
                max_neg = curr_neg;
                ind = i;
            }
        }
        // cout << max_neg << " hllo " << endl;
        vector<int> indices;
        if (ind != -1) {
            curr_neg = 0;
            for (int i = 0 ; i < n ; i ++) {
                curr_neg += a[i];
                if (curr_neg == max_neg) {
                    indices.push_back(i);
                }
            } 
        }
        int prod = 1;
        if (indices.size()) {
            int curr = 1;
            for (int i = 0 ; i < indices.size() ; i ++) {
                curr *= 2;
                curr %= MOD;
            }
            curr -=1;
            prod*=curr;
            prod %= MOD;
            // cout << " hello " << prod << endl;
            int curr1 = 1;
            int sum = 0;
            for (int i = 0 ; i < indices[0] ; i ++ ) {
                sum += a[i];
                if (sum >= 0) {
                    curr1*=2;
                    curr1 %= MOD;
                }
                else break;
            }
            prod*=curr1;
            for (int i = indices[0] ; i < n-indices.size() ; i ++) {
                prod *= 2;
                prod%=MOD;
            }
            // cout << " hello " << prod << endl;
        }
        else {
            for (int i = 0 ; i < n ; i ++) {
                prod *= 2;
                prod%=MOD;
            }
        }
        cout << prod << "\n";
    }
}
