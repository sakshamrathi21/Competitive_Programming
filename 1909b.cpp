#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0 ; i < n ; i ++) cin >> a[i];
        int k = 2;
        while (k < 1e18) {
            bool same = true;
            for (int i = 0 ; i < n-1 ; i ++) {
                if (a[i]%k != a[i+1]%k) {
                    same = false; break;
                }
            }
            if (!same) {
                cout << k << "\n";
                break;
            }
            k*= 2;
        }
    }
    
}
