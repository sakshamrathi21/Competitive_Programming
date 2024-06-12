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
        int x[n];
        x[0] = 0;
        for (int i = 1 ; i < n ; i ++) cin >> x[i];
        int a[n];
        a[0] = 1000;
        for (int i = 1 ; i < n ; i ++) {
            a[i] = a[i-1]+x[i];
        }
        for (int i = 0 ; i < n ; i ++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}
