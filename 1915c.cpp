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
        int a[n];
        for (int i = 0 ; i < n ; i ++) cin >> a[i];
        int s = 0;
        for (int i = 0 ; i < n ; i ++) s+= a[i];
        int sq = sqrt(s);
        if (sq*sq == s) cout << "YES" << "\n";
        else cout << "NO" << "\n";


    }
}
