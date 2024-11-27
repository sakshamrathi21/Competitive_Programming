#include<bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int x, int y) {
    if (y == 0) return x;
    if (x < y) return gcd(y, x);
    if (x%y ==0) return y;
    return gcd(x%y, y);
}

bool possible(vector<int>&a, int k) {
    
    int cgcd = abs(a[0]-a[k]);
    if (cgcd == 1) return false;
    if (cgcd == 0) {
        for (int i = 1 ; i < a.size()-k ; i ++) {
            if (abs(a[i]-a[i+k]) != 0) cgcd = abs(a[i]-a[i+k]);
        }
    }
    // if (k == 1) cout << "hello" << cgcd << endl;
    for (int i = 1 ; i < a.size()-k ; i ++) {
        // cout << i << " hello " << k << a.size() << a[i+k] <<  endl;
        if (abs(a[i]-a[i+k]) != 0) cgcd = gcd(cgcd, abs(a[i]-a[i+k]));
        if (cgcd == 1) return false;
    }
    return true;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) cin >> a[i];
        int cnt = 1;
        
        for (int k = 1 ; k < n ; k ++) {
            if (n%k == 0) {
                // cout << k << " hello " << possible(a, k) << endl;
                if (possible(a, k)) cnt++;
            }
        }
        cout << cnt << "\n";
    }
}
