/**
 *    Author: Saksham Rathi
 *    Created: Sat Jun  8 15:36:34 IST 2024
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
        int i = 0, j = n - 1;
        int x = 0;
        int cnt = 0;
        while (i < j) {
            // cout << " hello " << i << j << cnt << endl;
            if (x+a[i]<a[j]) {
                // cout << cnt << " check " << x << endl;
                x+=a[i];
                cnt += a[i];
                a[i] = 0;
                i++;
                
                // cout << cnt << " check " << x << endl;
            }
            else if (x+a[i] == a[j]) {
                cnt += a[i];
                cnt += 1;
                a[i] = 0; a[j] = 0;
                i++;
                j--;
                
            }
            else {
                a[i] -= (a[j]-x);
                cnt += 1;
                cnt += a[j]-x;
                x += a[i];
                cnt += a[i];
                a[i] = 0; a[j] = 0;
                i++;
                j--;
                
            }
        }
        if  (a[i] != 0) {
            if (x == 0) {
                cnt+= ((a[i]%2==0) ? (a[i]/2) : (a[i]/2+1));
            }
            else if (x<=a[i]) {
                a[i] -= x;
                cnt++;
                cnt+= ((a[i]%2==0) ? (a[i]/2) : (a[i]/2+1));
            }
            else cnt+= ((a[i]%2==0) ? (a[i]/2) : (a[i]/2+1));
        }
        cout << cnt << "\n";
    }
}
