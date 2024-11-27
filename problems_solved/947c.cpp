#include<bits/stdc++.h>
using namespace std;
#define int long long

int med(int a, int b, int c) {
    int minV = min({a, b, c});
    int maxV = max({a, b, c});
    return (a+b+c-minV-maxV);
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0 ; i < n ; i ++) cin >> a[i];
        if (n == 1) {
            cout << a[0] << "\n";
            continue;
        }
        int max_in = -1;
        for (int i = 0 ; i < n-1 ; i++) {
            max_in = max(max_in, min(a[i], a[i+1]));
        }
        int max_t = -1;
        for (int i = 0 ; i < n - 2 ; i ++) {
            max_t = max(max_t, med(a[i], a[i+1], a[i+2]));
        }
        cout << max(max_t, max_in) << "\n";
    }
}
