/**
 *    Author: Saksham Rathi
 *    Created: Fri Jun 14 18:53:37 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> binForm(int y) {
    vector<int> b;
    while (y > 0) {
        b.push_back(y%2);
        y/=2;
    }
    return b;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        if (x > n) {
            cout << -1 << "\n";
            continue;
        }
        vector<int> b1 = binForm(n), b2 = binForm(x);
        bool poss = true;
        for (int i = 0 ; i < b2.size() ; i ++) {
            if (b2[i] == 1 && b1[i] == 0) {poss = false; break;}
        }

    }
}
