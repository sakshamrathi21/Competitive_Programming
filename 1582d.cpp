/**
 *    Author: Saksham Rathi
 *    Created: Sat Jun 15 18:58:43 IST 2024
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
        if (n%2) {
            for (int i = 0 ; i < n-3 ; i +=2) {
                cout << a[i+1] << " " << -a[i] << " ";  
            }
            if ((a[n-2]+a[n-3]) != 0) cout << a[n-1] << " " << a[n-1] << " " << -(a[n-2]+a[n-3]) << " \n";
            else if ((a[n-1]+a[n-3]) != 0) cout << a[n-2] << " " << -(a[n-1]+a[n-3]) << " " << a[n-2] << " \n";
            else cout << -(a[n-2]+a[n-1]) << " " << a[n-3] << " " << a[n-3] << " \n";
            
            
        }
        else {
            for (int i = 0 ; i < n ; i +=2) {
                cout << a[i+1] << " " << -a[i] << " ";
            }
            cout << "\n";
        }
    }
}
