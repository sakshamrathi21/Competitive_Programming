#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        int x = 1;
        while (x <= n) {
            x*= 2;
        }
        cout << x/2 << endl;
    }
}
