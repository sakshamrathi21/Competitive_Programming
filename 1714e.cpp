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
        for (int i = 0 ; i < n ; i ++ ) cin >> a[i];
        bool fivfn = false;
        for (int i = 0 ; i < n ; i ++) {
            if (a[i]%10 == 0) {fivfn = true; continue;}
            if (a[i]%10 == 5) {a[i] += 5; fivfn = true;}
            else {
                while (a[i]%10 != 2) a[i]+= (a[i]%10);
            }
        }
        bool possible = true;
        if (fivfn) {
            for (int i = 0 ; i < n-1 ; i ++) {
                if (a[i] != a[i+1]) {
                    possible = false;
                    break;
                }
            }
        }
        if (!possible) {
            cout << "No" <<"\n";
            continue;
        }
        for (int i = 0 ; i < n - 1 ; i ++) {
            if ((a[i]%20) != (a[i+1]%20)) {
                possible = false;
                break;
            }
        }
        if (!possible) {
            cout << "No" <<"\n";
            continue;
        }
        cout << "Yes" << "\n"; 
    }
}
