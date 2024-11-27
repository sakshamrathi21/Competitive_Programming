/**
 *    Author: Saksham Rathi
 *    Created: Wed Jul 24 16:44:12 IST 2024
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
        vector<long double> b(n);
        for (int i = 0 ; i < n ; i ++ ) {
            if (a[i] == 1){
                b[i] = -1;
                continue;
            }
            b[i] = log2(log2((long double)a[i]));
            // cout << " hello " << b[i] << endl; 
        }
        int ans = 0;
        bool poss = true;
        for (int i = 0 ; i < n-1 ; i ++) {
            if (b[i] <= b[i+1]) continue;
            if (b[i+1] < 0) {
                poss = false;
                break;
            }
            int cnt = (1+(b[i]-b[i+1]-1e-9));
            ans += cnt;
            b[i+1] += cnt;
        }
        if (!poss) ans = -1;
        cout << ans << "\n";
    }
}
