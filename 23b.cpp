#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >>t;
    while (t--) {
        int n;
        cin >> n;
        if (n==0 || n ==1) {
            cout << 0 << '\n';
        }
        else cout << n-2 << "\n";
    }
}
