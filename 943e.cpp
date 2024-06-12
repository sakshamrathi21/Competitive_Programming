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
        for (int i = 1 ; i<= n-2 ; i ++) {
            cout << i << " " << i << "\n";
        }
        cout << n << " " << n-1 << "\n" << n << " " << n<< '\n';
    }
}
