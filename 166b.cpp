#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n+1);
        for (int i = 0 ; i < n ; i ++) cin >> a[i];
        for (int i = 0 ; i < n +1 ; i ++ ) cin >> b[i];
        int td = 0;
        for (int i = 0 ; i < n ; i ++) td += abs(a[i]-b[i]);
        // 
        int md = INT32_MAX;
        for (int i = 0 ; i < n ; i ++) {
            if (b[n] <= a[i] && b[n]>= b[i]) md = 0;
            if (b[n] <= b[i] && b[n]>= a[i]) md = 0;
            md = min(md, abs(b[n]-a[i]));
            md = min(md, abs(b[n]-b[i]));
        }
        // cout << td << " hello " << md << endl;
        td += md;
        cout << td+1 << "\n";
    }
}
