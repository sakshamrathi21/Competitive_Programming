#include<bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int x, int y) {
    if (y == 0) return x;
    if (x < y) return gcd(y, x);
    if (x%y ==0) return y;
    return gcd(x%y, y);
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
        for (int i = 0 ; i < n ; i++) cin >> a[i];
        int min_a = INT32_MAX;
        for (int i = 0 ; i < n ; i ++) min_a = min(min_a, a[i]);
        if (min_a == 1) {
            cout << "Yes" << "\n";
            continue;
        }
        vector<int> nd;
        for (int i = 0 ; i < n ; i ++) {
            if (a[i]%min_a != 0) nd.push_back(a[i]);
        }
        if (nd.size() == 0) {
            cout << "Yes" << "\n";
            continue;
        }
        int cgcd = nd[0];
        for (int i = 1 ; i < nd.size() ; i ++) {
            cgcd = gcd(cgcd, nd[i]);
        }
        bool found = false;
        for (int i = 0 ; i < nd.size() && !found ; i ++) {
            if (nd[i] == cgcd) {
                cout << "Yes" << "\n";
                found = true;
            }
        }
        if (!found) {
            cout << "No" << "\n";
        }
    } 
}
