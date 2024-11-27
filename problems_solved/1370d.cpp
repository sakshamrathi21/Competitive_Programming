/**
 *    Author: Saksham Rathi
 *    Created: Fri Jun 21 08:20:54 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

bool ch(vector<int>&a, int x, int k, int curr) {
    int ans = 0;
    for (int i = 0 ; i < a.size() ; i ++) {
        if (curr%2 == ans%2) {
            if (a[i] <= x) {
                ans++;
            }
        }
        else ans++;
    }
    return (ans >= k);
}

int bS(vector<int>&a, int low, int high, int k) {
    while (low < high) {
        // cout << low << " hello " << high << endl;
        int mid = (low+high)/2;
        if (ch(a, mid, k, 0) || ch(a, mid, k, 1)) {
            high = mid;
        }
        else {
            low = mid+1;
        }
    }
    return low;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
        }
        cout << bS(a, 0, 1e9, k);
    }
}
