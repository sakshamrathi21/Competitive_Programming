/**
 *    Author: Saksham Rathi
 *    Created: Sat Jun  8 17:01:16 IST 2024
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
        vector<int> b(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> a[i];
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int cnt1 = a[n/2]-a[(n-1)/2]+1;
        int cnt2 = b[n/2]-b[(n-1)/2]+1;
        cout << cnt1*cnt2 << "\n";


    }
}
