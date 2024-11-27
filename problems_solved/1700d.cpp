/**
 *    Author: Saksham Rathi
 *    Created: Sat Jul  6 16:41:49 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

int binSearch(vector<int>&y, int low, int high, int val) {
    while (low < high) {
        if (high-low <= 2) {
            for (int i = low; i<= high && i < y.size() ; i++){
                if (y[i] <= val) return i;
            }
            return -2;
        }
        // cout << low << " " << high << " " << val << endl;
        int mid = (low+high)/2;
        if (y[mid] <= val) {
            high = mid+1;
        }
        else {
            low = mid+1;
        }
    }
    if (low == y.size()) return -1;
    if (y[low] <= val) return low;
    if (high < y.size() && y[high] <= val) return high;
    return -2;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        vector<int>dp(n);
        vector<int> pref_sum(n);
        pref_sum[0] = a[0];
        for (int i = 1 ; i < n ; i ++) pref_sum[i] = pref_sum[i-1]+a[i];
        dp[0] = a[0];
        for (int i = 1 ; i < n ; i ++) {
            int x;
            if (pref_sum[i]%(i+1)) x = pref_sum[i]/(i+1)+1;
            else x = pref_sum[i]/(i+1);
            dp[i] = max(dp[i-1], x);
        }
        vector<int> res(n);
        for (int i = 0 ; i < n ; i ++) {
            int x;
            if (pref_sum[n-1]%(i+1)) x = pref_sum[n-1]/(i+1)+1;
            else x = pref_sum[n-1]/(i+1);
            // cout << x << " hello " << i << endl;
            res[i] = max(x, dp[i]);
        }
        // for (int i = 0 ; i < n ; i ++) cout << res[i] << " ";
        // cout << "\n";
        int q;
        cin >> q;
        while (q--) {
            int l;
            cin >> l;
            cout << binSearch(res, 0, n, l)+1 << "\n"; 
        }
    }
}
