#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        if (m > n) {
            cout << "No" << "\n";
            continue;
        }
        if ((n-m)%2 == 0) {
            cout << "Yes" << "\n";
            continue;
        }
        else {
           cout << "No" << "\n"; 
        }
    }
}
