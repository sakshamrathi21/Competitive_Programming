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
        int a[n];
        for (int i = 0 ; i < n ; i ++ ) cin >> a[i];
        int bi = -1;
        int cnt = 0;
        int b[n-1];
        for (int i = 0 ; i < n - 1 ; i ++) {
            if (a[i] < 2*a[i+1]) b[i] = 1;
            else b[i] = 0;
        }
        int s[n];
        s[0] = 0;
        for (int i = 0 ; i < n - 1 ; i ++) {
            s[i+1] = s[i] + b[i];
        }
        for (int i = 0 ; i < n-k ; i ++) {
            if (s[i+k]-s[i] == k) cnt++;
        }
        cout << cnt << "\n";
    }
}
