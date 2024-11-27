#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int l,r;
        cin >> l >> r;
        int sc = 0;
        while (r>1) {
            sc += 1;
            r/= 2;
        }
        cout << sc << "\n";
    }
}
