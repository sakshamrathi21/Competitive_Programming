/**
 *    Author: Saksham Rathi
 *    Created: Sun Jun 16 14:25:31 IST 2024
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
        int n, k;
        cin >> n >> k;
        if (n%2 == 1) {
            if (k > ((n-1)*(n+1)/2)) {
                cout << "No\n";
                continue;
            }
        }
        else {
            if (k > ((n)*(n)/2)) {
                cout << "No\n";
                continue;
            }
        }
        if (k%2 == 1) {
            cout << "No\n";
            continue;
        }
        vector<int> a(n+1);
        for (int i = 0 ;i <= n ; i ++ ) a[i] = i;
        int left = 1, right = n;
        for (int r = 0 ; r < n ; r ++) {
            // cout << " hello " << k << endl;
            if (k <= 0) break;
            if (k <= 2*(a[right] - a[left])) {
                // cout << a[left] << " check" << a[k/2+left];
                int x = a[left], y = a[k/2+left];
                swap(a[left], a[k/2+left]);
                // cout << a[left] << " check" << a[k/2+left];
                k -= 2*(y-x);
                left ++;
            }
            else {
                int x = a[left], y = a[right];
                k -= 2*(y-x);
                swap(a[left], a[right]);
                left ++;
                right --;
            }
        }
        cout << "Yes\n";
        for (int i = 1 ; i <= n ; i ++ ) cout << a[i] << " ";
        cout << "\n";

    }
}
